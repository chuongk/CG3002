#include "qt_test.h"
#include "transact.h"
#include <sql_Connector.h> // Strange, cannot include it in the qt_test.h file
qt_test::qt_test(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Initialize();
}


/*
	Do any intialization here
*/
void qt_test::Initialize()
{
	
}


qt_test::~qt_test()
{

}

void qt_test::on_pushButton_clicked()
{
	ui.textEdit->setText("hello world!");
	//Open a web url from browser
	QString link = "http://localhost/phpmyadmin/";
	QDesktopServices::openUrl(QUrl(link));
}

void qt_test::on_dateEdit_dateChanged(const QDate &date)
{
	transact *Itran= new transact();
	Itran->show();
	/*QTableWidget *table=new QTableWidget(0,2,0);

	table->insertColumn(0);
	table->setHorizontalHeaderItem(0, new QTableWidgetItem("Whatever"));
	table->insertRow(0);
	ui.textEdit_2->setText(date.toString());*/
	//ui.tableWidget->hide();
	//table->show();
}

/*
	When the button is clicked, take the barcode value from the barcode_line and search the item based on that barcode
*/

void qt_test::on_SearchButton_clicked()
{
	int j = ui.item_table->rowCount();
	if (j>0)
	{
		for (int i=0;i<j;i++)
			ui.item_table->removeRow(0);
		j=0;
	}
	
	QString label_result="Empty Result!";
	QString barcode=ui.barcode_line->text();
	QString iName=ui.name_line->text();
	QString iCate=ui.cate_line->text();
	QString iManu=ui.manu_line->text();
	string barcod=barcode.toStdString();
	string iNam=iName.toStdString();
	string iCat=iCate.toStdString();
	string iMan=iManu.toStdString();
	vector<Item*> iList;
	ui.result_label->setStyleSheet("QLabel { color : red; font: bold 14px; }");
	if (barcod.length()<=BARCODE_LENGTH)
	{
		//Item *tmp=new Item();
		Item *tmp;
		// Set up sql_connector to access database
		sql_Connector *contor=new sql_Connector();
		contor->start_Connect();
		contor->chooseDB("CG3002");
		//if (contor->search_from_barcode( atoi(barcod.c_str()),tmp)==1)
		if (contor->search_general(barcod,iNam,iCat,iMan,iList))
		{
			int size=iList.size();
			for (int i=0;i<size;i++)
			{
				QString val;
				ui.item_table->insertRow(j);
				ui.item_table->setSortingEnabled(false);
				QTableWidgetItem *item1;
				tmp=iList[i];
				for (int z=0;z<8;z++)
				{
					switch(z)
					{
					case 0:
						//Fill in item Id;
						val= QString::fromStdString(tmp->get_ItemID_toStr());
						break;
					case 1:
						//Fill in item_name;
						val= QString::fromStdString(tmp->get_ItemName());
						break;
					case 2:
						//Fill in category;
						val = QString::fromStdString(tmp->get_ItemCategory());
						break;
					case 3:
						//Fill in manufacturer:
						val = QString::fromStdString(tmp->get_ItemManufacturer());
						break;
					case 4:
						//Fill in price;
						val = QString::fromStdString(tmp->get_ItemPrice_toStr());
						break;
					case 5:
						//Fill in local stock;
						val = QString::fromStdString(tmp->get_ItemLocalStock_toStr());
						break;
					case 6:
						//Fill in minimum stock;
						val = QString::fromStdString(tmp->get_ItemMinStock_toStr());
						break;
					case 7:
						//Fill in bundle
						val = QString::fromStdString(tmp->get_ItemBundelUnit_toStr());
						break;
					}
					//ui.item_table->setRowCount(j);
					ui.item_table->setItem(j,z,new QTableWidgetItem(val));
				}
				delete tmp;
			}
			iList.clear();
			
			ostringstream convert;   // stream used for the conversion
			convert << size;      // insert the textual representation of 'Number' in the characters in the stream
			label_result= QString::fromStdString(convert.str()) + " results";
		}
		delete contor;
	}
	ui.result_label->setText(label_result);
}
