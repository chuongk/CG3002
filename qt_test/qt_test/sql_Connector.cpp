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
		string query="SELECT * FROM item i WHERE i.itemId=" + convert.str() ; 
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