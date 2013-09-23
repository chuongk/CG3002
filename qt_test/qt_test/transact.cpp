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
}


/*
	Submit the transactions to add to database
*/
void transact::on_transact_Submit_clicked()
{
	//Set up SQL CONNECTOR
	sql_Connector *contor=new sql_Connector();
	contor->start_Connect();
	contor->chooseDB("CG3002");

	int i;
	QTableWidgetItem *tmp;
	QColor color=Qt::red;
	ui.transact_table->item(0,0)->setBackgroundColor(color);
	int ro=ui.transact_table->rowCount();
	for (i=0;i<ro;i++)
	{
		tmp=ui.transact_table->item(i,0);

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