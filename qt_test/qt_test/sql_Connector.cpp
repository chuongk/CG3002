#include "sql_Connector.h"

sql_Connector::sql_Connector()
{
	int ab;
	server=Server; 
	user = USR ; 
	password = PWD; 
	Initialize();
}

sql_Connector::~sql_Connector()
{
	if (con!=NULL)
		delete con;
	if (stmt!=NULL)
		delete stmt;
	if (res!=NULL)
		delete res;
}

void sql_Connector::Initialize()
{
	driver=NULL; con=NULL; stmt=NULL; res=NULL;
}

sql_Connector::sql_Connector(string server_in, string usr_in, string pwd_in)
{
	server=server_in;
	user=usr_in;
	password=pwd_in;
	Initialize();
}

/* 
	Connect to a database with server, username and password define in the constructor
*/
void sql_Connector::start_Connect()
{
	try {
		driver = get_driver_instance();
		con = driver->connect(server, user, password);
	}
	catch (sql::SQLException &e) {
		std::cout<<e.what();
		system("PAUSE");
		exit(1);
	}
}

/*
	choose database specified by DB_in
*/
void sql_Connector::chooseDB(string DB_in)
{
	if (con!=NULL)
		con->setSchema(DB_in);
}

/*
	create database specified by DB_in
*/
void sql_Connector::createDB(string DB_in)
{
	if (stmt!=NULL)
		delete stmt;
	if (con==NULL)
		con = driver->connect(server, user, password);
	try{
		stmt = con->createStatement();
		stmt->execute("create database IF NOT EXISTS " + DB_in);
	}
	catch (sql::SQLException &e) {
		std::cout<<e.what();
		system("PAUSE");
		exit(1);
	}

}
/*
	execute a query from a file
*/
void sql_Connector::execute_from_FILE(string file_name)
{
	fstream inStream(file_name);

	if (inStream)
	{
		std::string contents;
		inStream.seekg(0, std::ios::end);
		contents.resize(inStream.tellg());
		inStream.seekg(0, std::ios::beg);
		inStream.read(&contents[0], contents.size());
		try{
			stmt = con->createStatement();
			stmt->execute(contents);
		}
		catch (sql::SQLException &e) {
			std::cout<<e.what();
			system("PAUSE");
			exit(1);
		}
		inStream.close();
	}
}

/*
	Populate the database from the file given
*/
void sql_Connector::insert_from_FILE(string file_name)
{
	
	std::string delimiter = ":";
	int pos = 0;
	int z=0;
	string line;
	string token;
	ifstream read;
	try{
		sql::PreparedStatement  *prep_stmt;
		sql::PreparedStatement *prep2;
		prep_stmt = con->prepareStatement("INSERT IGNORE INTO item(itemName, category, manufacturer, itemId, price, local_stock, minimum_stock, bundle_unit) VALUES (?, ?, ? , ?, ?, ?, ? ,? )");
		prep2 = con->prepareStatement("INSERT IGNORE INTO category(Product_Name, Category) VALUES(?, ?)");
		read.open(file_name);
		if(read.is_open())
		{
			cout << "File ./" << file_name << " is open.\n";
			while (!read.eof())
			{
				getline(read,line);
				z=0;
				while ((pos = line.find(delimiter)) != std::string::npos) {
					token = line.substr(0, pos);
					line.erase(0, pos + delimiter.length());
					switch(z)
					{
					case 0: case 1: case 2:
						prep_stmt->setString(z+1, token);
						if (z==1 || z==0)
						{
							prep2->setString(z+1,token);
						}
						break;
					case 3: case 5: case 6:
						prep_stmt->setInt(z+1, atoi(token.c_str()));
						break;
					case 4:
						prep_stmt->setDouble(z+1, atof(token.c_str()));
						break;
					}
					z++;
				}
				prep_stmt->setInt(z+1, atoi(line.c_str()));
				prep_stmt->executeUpdate();
				prep2->executeUpdate();
			}
		}
		else
			cout << "Error opening " << file_name << ".\n";
		
		delete prep_stmt;
		delete prep2;
	}
	catch (sql::SQLException &e) {
			std::cout<<e.what()<<endl;
			system("PAUSE");
			exit(1);
	}

}

void sql_Connector::insert_Transaction_from_FILE(string file_name)
{
	//populate_Cashier_from_FILE(file_name,1234);
	std::string delimiter = ":";
	int pos = 0;
	int z=0;
	string line;
	string token;
	ifstream read;
	try{
		sql::PreparedStatement  *prep_stmt;
		prep_stmt = con->prepareStatement("INSERT IGNORE INTO local_transaction(tId, cId, itemId, Unit_Sold,tDate) VALUES (?, ?, ?, ?, ?)");
		read.open(file_name);
		if(read.is_open())
		{
			cout << "File ./" << file_name << " is open.\n";
			while (!read.eof())
			{
				getline(read,line);
				z=0;
				while ((pos = line.find(delimiter)) != std::string::npos) {
					token = line.substr(0, pos);
					line.erase(0, pos + delimiter.length());
					switch(z)
					{
					case 0: case 1: 
						prep_stmt->setInt(z+1, atoi(token.c_str()));
						break;
					case 4: case 3:
						prep_stmt->setInt(z, atoi(token.c_str()));
						break;
					}
					z++;
				}
				token=toDate(line);
				prep_stmt->setDateTime(5, token);
				prep_stmt->executeUpdate();
			}
		}
		else
			cout << "Error opening " << file_name << ".\n";
		
		delete prep_stmt;
	}
	catch (sql::SQLException &e) {
			std::cout<<e.what()<<endl;
			system("PAUSE");
			exit(1);
	}
}

void sql_Connector::populate_cashier_test()
{
	std::string delimiter = ":";
	int pos = 0;
	int z=0;
	string line;
	string token;
	ifstream read;
	try{
		sql::PreparedStatement  *prep_stmt;
		prep_stmt = con->prepareStatement("INSERT INTO cashier(cashierID, shopID ) VALUES (?,?)");
		prep_stmt->setInt(1,1693);
		prep_stmt->setInt(2,1693);
		prep_stmt->executeUpdate();
		delete prep_stmt;
	}
	catch (sql::SQLException &e) {
			std::cout<<e.what()<<endl;
			system("PAUSE");
			exit(1);
	}
}

void sql_Connector::populate_Cashier_from_FILE(string file_name,int SID)
{
	std::string delimiter = ":";
	int pos = 0;
	int z=0;
	string line;
	string token;
	ifstream read;
	try{
		sql::PreparedStatement  *prep_stmt;
		prep_stmt = con->prepareStatement("INSERT IGNORE INTO cashier(cashierID, shopID ) VALUES (?,?)");
		read.open(file_name);
		if(read.is_open())
		{
			cout << "File ./" << file_name << " is open.\n";
			while (!read.eof())
			{
				getline(read,line);
				z=0;
				while ((pos = line.find(delimiter)) != std::string::npos) {
					token = line.substr(0, pos);
					line.erase(0, pos + delimiter.length());
					switch(z)
					{
					case 0:
						prep_stmt->setInt(z+1, atoi(line.c_str()));
						break;
					}
					z++;
				}
				prep_stmt->setInt(2, SID);
				prep_stmt->executeUpdate();
			}
		}
		else
			cout << "Error opening " << file_name << ".\n";
		
		delete prep_stmt;
	}
	catch (sql::SQLException &e) {
			std::cout<<e.what()<<endl;
			system("PAUSE");
			exit(1);
	}
}

string sql_Connector::toDate(string toCut)
{
	std::string delimiter = "/";
	string result="";
	string arr[3];
	string token;
	int pos = 0;
	int z=0;
	while ((pos = toCut.find(delimiter)) != std::string::npos) {
		token = toCut.substr(0, pos);
		toCut.erase(0, pos + delimiter.length());
		arr[z]=token;
		z=z+1;
	}
	arr[z]=toCut;
	result=arr[2]+'-'+arr[1]+'-'+arr[0];
	return result;
}

/*
	This function take the barcode and search the item based on it
	success: return 1;
	no item: return 0;
*/
int sql_Connector::search_from_barcode(int barcode,Item *Ifind)
{
	try
	{
		int count=0;
		ostringstream convert;   // stream used for the conversion
		convert << barcode;      // insert the textual representation of 'Number' in the characters in the stream
		string query="SELECT * FROM item i WHERE i.itemId=" + convert.str() + " and i.itemName=i.itemName" ; 
		stmt=con->createStatement();
		res=stmt->executeQuery(query);
		while (res->next())
		{
			count++;
			Ifind->set_ItemID(res->getInt("itemId"));
			Ifind->set_ItemName(res->getString("itemName"));
			Ifind->set_ItemCategory(res->getString("category"));
			Ifind->set_ItemManufacturer(res->getString("manufacturer"));
			Ifind->set_ItemPrice(res->getDouble("price"));
			Ifind->set_ItemLocalStock(res->getInt("local_stock"));
			Ifind->setItemMinStock(res->getInt("minimum_stock"));
			Ifind->setItemBundleUnit(res->getInt("bundle_unit"));
		}
		if (count!=1)
			return 0;
		else
			return 1;
	}
	catch (sql::SQLException &e) {
		std::cout<<e.what()<<endl;
		system("PAUSE");
		exit(1);
	}

}

/*
	This function takes in the string barcode, name, category and manufacture( allow empty string)
	Compute the search base on the info given
	Return 0 if find at
*/
int sql_Connector::search_general(string barcode,string iName,string iCate, string iManu,vector<Item*> &iList)
{
	if (!(barcode.length() || iName.length() || iCate.length() || iManu.length()))
		return 0;

	string query=makeSearchQuery(barcode,iName,iCate,iManu);
	Item *Ifind;
	try
	{
		int count=0;
		stmt=con->createStatement();
		res=stmt->executeQuery(query);
		while (res->next())
		{
			count++;
			Ifind=new Item();
			Ifind->set_ItemID(res->getInt("itemId"));
			Ifind->set_ItemName(res->getString("itemName"));
			Ifind->set_ItemCategory(res->getString("category"));
			Ifind->set_ItemManufacturer(res->getString("manufacturer"));
			Ifind->set_ItemPrice(res->getDouble("price"));
			Ifind->set_ItemLocalStock(res->getInt("local_stock"));
			Ifind->setItemMinStock(res->getInt("minimum_stock"));
			Ifind->setItemBundleUnit(res->getInt("bundle_unit"));
			iList.push_back(Ifind);
		}
		if (count<1)
			return 0;
		else
			return 1;
		delete stmt;
		stmt=NULL;
		delete res;
		res=NULL;
	}
	catch (sql::SQLException &e) {
		return 0;
	}
}

string sql_Connector::makeSearchQuery(string barcode,string iName,string iCate, string iManu)
{
	string result="SELECT * FROM item i WHERE ";
	string bar,Name,Cate,Manu;

	if (barcode.length()==0)
		result+="i.itemId=i.itemId and ";
	else
		result+="i.itemId= "+barcode+ " and ";

	if (iName.length()==0)
		result+="i.itemName=i.itemName and ";
	else
		result+="i.itemName=\'"+iName+ "\' and ";

	if (iCate.length()==0)
		result+="i.category=i.category and ";
	else
		result+="i.category=\'"+iCate+ "\' and ";

	if (iManu.length()==0)
		result+="i.manufacturer=i.manufacturer ";
	else
		result+="i.manufacturer=\'"+iManu+"\'";

	return result;
}

/*
	Insert a new transaction, date is current date
*/
int sql_Connector::insert_new_Transaction(string barcode, string iQuantity,string cashierID)
{
	try
	{
		//Update the Stock first
		update_stock(barcode,iQuantity,REDUCE);

		string query="SELECT MAX(l.tId) AS highest_tID , l.tDate FROM local_transaction l WHERE l.tDate=CURDATE()" ; 
		stmt=con->createStatement();
		res=stmt->executeQuery(query);
		res->first();
		int newtID=res->getInt("highest_tID")+1;
		string curDate=res->getString("tDate");
		delete stmt;
		stmt=NULL;
		delete res;
		res=NULL;

		int cId=atoi(cashierID.c_str());
		int itemId=atoi(barcode.c_str());
		int Unit_Sold=atoi(iQuantity.c_str());

		sql::PreparedStatement  *prep_stmt;
		prep_stmt = con->prepareStatement("INSERT INTO local_transaction(tId, cId, itemId, Unit_Sold,tDate) VALUES (?, ?, ?, ?, ?)");
		prep_stmt->setInt(1,newtID);
		prep_stmt->setInt(2,cId);
		prep_stmt->setInt(3,itemId);
		prep_stmt->setInt(4,Unit_Sold);
		prep_stmt->setString(5,curDate);

		prep_stmt->executeUpdate();
		delete prep_stmt;
		prep_stmt=NULL;
		return 1;
	}
	catch (sql::SQLException &e) {
		return 0;
	}
}


/*
	This function take the cId and search the cashier based on it
	success: return 1;
	no item: return 0;
*/
int sql_Connector::search_cashier_from_cId(int cId)
{
	try
	{
		int count=0;
		ostringstream convert;   // stream used for the conversion
		convert << cId;      // insert the textual representation of 'Number' in the characters in the stream
		string query="SELECT * FROM cashier c WHERE c.cashierId=" + convert.str(); 
		stmt=con->createStatement();
		res=stmt->executeQuery(query);
		while (res->next())
		{
			count++;
		}
		
		if (!count)
			return 0;
		else
			return 1;
	}
	catch (sql::SQLException &e) {
		std::cout<<e.what()<<endl;
		system("PAUSE");
		exit(1);
	}
}

/*
	Update an item stock based on bardcode and quantity reduce
	1: success
	0: unsuccesful
*/
int sql_Connector::update_stock(string barcode, string iQuantity, UpStock type)
{

	try
	{
		string sign;
		if (type== INCREASE)
			sign = "+";
		else
			sign = "-";
		string query="UPDATE item i SET i.local_stock=i.local_stock " + sign + " " + iQuantity + " WHERE i.itemId=" + barcode ; 
		stmt=con->createStatement();
		if (stmt->executeUpdate(query))
			return 1;
		return 0;
	}
	catch (sql::SQLException &e) {
		return 0;
	}
}

int sql_Connector::get_Curdate_Transaction(vector<Transaction*> &iList)
{
	try
	{
		Transaction *Itrans;
		int count=0;
		string query="SELECT * FROM  local_transaction l, item i WHERE l.tDate=CURDATE() and i.itemId=l.itemId ORDER BY l.tId ASC" ; 
		stmt=con->createStatement();
		res=stmt->executeQuery(query);
		while (res->next())
		{
			count++;
			Itrans=new Transaction();
			Itrans->set_cId(res->getInt("cId"));
			Itrans->set_tId(res->getInt("tId"));
			Itrans->set_iId(res->getInt("itemId"));
			Itrans->set_Date(res->getString("tDate"));
			Itrans->set_Quantity(res->getInt("Unit_Sold"));
			Itrans->set_Price(res->getDouble("price"));
			iList.push_back(Itrans);
		}
		if (count!=1)
			return 0;
		else
			return 1;
	}
	catch (sql::SQLException &e) {
		std::cout<<e.what()<<endl;
		system("PAUSE");
		exit(1);
	}
}