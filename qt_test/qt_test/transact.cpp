#include "transact.h"
#include "sql_Connector.h"
transact::transact(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Initialize();
}

transact::~transact()
{
	
}

/*
	Do initialize stuff here
*/
void transact::Initialize()
{
	ui.transact_res->setText("");
}

/*
	Cancel current transaction
*/
void transact::on_transact_Cancel_clicked()
{
	this->close();
}

/*
	Add a row to insert new item info
*/
void transact::on_transact_Item_add_clicked()
{
	ui.transact_table->insertRow(0);
	int col=ui.transact_table->columnCount();
	for (int i=0;i<col;i++)
	{
		ui.transact_table->setItem(0,i,new QTableWidgetItem(""));
	}
}


/*
	Submit the transactions to add to database
*/
void transact::on_transact_Submit_clicked()
{
	
	if (check_transact_syntax())
	{
		double transaction_price=0;
		double item_price;
		//Set up SQL CONNECTOR
		sql_Connector *contor=new sql_Connector();
		contor->start_Connect();
		contor->chooseDB("CG3002");
		int i;
		QTableWidgetItem *tmp;

		int ro=ui.transact_table->rowCount();
		for (i=0;i<ro;i++)
		{
			tmp=ui.transact_table->item(i,0);

			//Taking the parameters and convert to stdString
			QString barcode = tmp->text();
			string barcod = barcode.toStdString();
			tmp=ui.transact_table->item(i,1);

			QString quantity = tmp->text();
			string quantit = quantity.toStdString();

			tmp=ui.transact_table->item(i,2);
			QString cashier = tmp->text();
			string cashi = cashier.toStdString();

			// Get item_price, also check if barcode exists
			item_price=check_barcode(barcod,quantit,i,contor);
			if (item_price < 0)
				break;
			transaction_price+=item_price;

			// Check if cashier exists
			if (!check_cashier(cashi,i,contor))
				break;

			// Finally insert the new Transactions
			contor->insert_new_Transaction(barcod,quantit,cashi);

			ostringstream convert;
			convert << transaction_price;
			
			ui.transact_total_price->setText(QString::fromStdString(convert.str()));
		}

		delete contor;
	}
}

bool transact::is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(), 
        s.end(), [](char c) { return !isdigit(c); }) == s.end();
}

/*
	Support function for on_Transact_submit, check if the value in the cells is not empty or not integer
	Doesn't check if the value is valid or not
	return: 0 if wrong
			1 if right
*/
int transact::check_transact_syntax()
{
	int i;
	int result=1;
	QTableWidgetItem *tmp;
	QColor color=Qt::red;
	
	int ro=ui.transact_table->rowCount();
	for (i=0;i<ro;i++)
	{
		tmp=ui.transact_table->item(i,0);

		//Taking the parameters and convert to stdString
		QString barcode = tmp->text();
		string barcod = barcode.toStdString();
		tmp=ui.transact_table->item(i,1);
		if (!is_number(barcod))
		{
			color=Qt::red;
			result=0;
		}
		else
			color=Qt::white;
		ui.transact_table->item(i,0)->setBackgroundColor(color);

		QString quantity = tmp->text();
		string quantit = quantity.toStdString();
		if (!is_number(quantit))
		{
			color=Qt::red;
			result=0;
		}
		else
			color=Qt::white;
		ui.transact_table->item(i,1)->setBackgroundColor(color);

		tmp=ui.transact_table->item(i,2);
		QString cashier = tmp->text();
		string cashi = cashier.toStdString();
		if (!is_number(cashi))
		{
			color=Qt::red;
			result=0;
		}
		else
			color=Qt::white;
		ui.transact_table->item(i,2)->setBackgroundColor(color);

	}

	ui.transact_res->setStyleSheet("QLabel { color : red; font: bold 12px; }");
	if (!result)
		ui.transact_res->setText("Please fill the red cell(s) with correct format");
	else
		ui.transact_res->setText("");

	return result;
}

/*
	Check if the barcode in row ro exists and return the total price of the item with the barcode
	return -1 if wrong
*/
double transact::check_barcode(string barcode,string quantity,int ro,sql_Connector *contor)
{
	ostringstream convert;
	convert << barcode;
	int bar=atoi(convert.str().c_str());
	convert.str("");
	convert << quantity;
	int quan = atoi(convert.str().c_str());
	convert.str("");
	convert << (ro+1);
	QString cur_row= QString::fromStdString(convert.str());
	Item *tmp=new Item();
	QString result;
	if (contor->search_from_barcode(bar,tmp))
	{
		double price=tmp->get_ItemPrice();
		double total_price=price*quan;
		convert.str("");
		convert<<price;
		result=QString::fromStdString(convert.str());
		ui.transact_table->setItem(ro,3,new QTableWidgetItem(result));
		return total_price;
	}
	else
	{
		ui.transact_res->setStyleSheet("QLabel { color : red; font: bold 12px; }");
		result="barcode in row " + cur_row + " doesn't exist!";
		ui.transact_res->setText(result);
		return -1;
	}
}

/*
	Return 1 if cashier exists
	Return 0 if no
*/
int transact::check_cashier(string cId, int ro, sql_Connector *contor)
{
	ostringstream convert;
	convert << cId;
	int cashierId=atoi(convert.str().c_str());
	convert.str("");
	convert << (ro+1);
	QString cur_row= QString::fromStdString(convert.str());
	QString result="";
	if (contor->search_cashier_from_cId(cashierId))
	{
		ui.transact_res->setText(result);
		return 1;
	}
	else
	{
		ui.transact_res->setStyleSheet("QLabel { color : red; font: bold 12px; }");
		result="cashier in row " + cur_row + " doesn't exist!";
		ui.transact_res->setText(result);
		return 0;
	}
}