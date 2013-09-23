#include "transact.h"
#include "sql_Connector.h"
transact::transact(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

transact::~transact()
{

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

			contor->insert_new_Transaction(barcod,quantit,cashi);
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
			ui.transact_table->item(i,0)->setBackgroundColor(color);
			result=0;
		}

		QString quantity = tmp->text();
		string quantit = quantity.toStdString();
		if (!is_number(quantit))
		{
			ui.transact_table->item(i,1)->setBackgroundColor(color);
			result=0;
		}

		tmp=ui.transact_table->item(i,2);
		QString cashier = tmp->text();
		string cashi = cashier.toStdString();
		if (!is_number(cashi))
		{
			ui.transact_table->item(i,2)->setBackgroundColor(color);
			result=0;
		}

	}
	return result;
}