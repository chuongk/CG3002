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
	ui.transact_result->setText("");
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
	// Prevent choosing another window
	Itran->setModal(true);
	//Fixed the window size:
	Itran->setFixedSize(TRANS_WIDTH,TRANS_HEIGHT);
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
			ui.result_label->setStyleSheet("QLabel { color : green; font: bold 14px; }");
			label_result= QString::fromStdString(convert.str()) + " results";
		}
		delete contor;
	}
	ui.result_label->setText(label_result);
}

void qt_test::on_sync_button_clicked()
{
	// Get the current tab
	int cur_tab=ui.transact_table->currentIndex();
	string filename;
	switch (cur_tab)
	{
	case 0:	// Sorting by today
		transact_by_Curdate(filename);
		break;
	}
	
}

void qt_test::on_transact_generate_Report_clicked()
{
	// Get the current tab
	int cur_tab=ui.transact_table->currentIndex();
	string filename;
	ostringstream res;
	string result;
	switch (cur_tab)
	{
	case 0:	// Sorting by today
		res=transact_by_Curdate(filename);
		result=res.str();
		break;
	}
	// Save to file
	ofstream myfile (filename+".txt");
	myfile<<result;
	myfile.close();

	//Display the result
	ui.transact_result->setStyleSheet("QLabel { color : green; font: bold 12px; }");
	string gen_res= "Report name: " + filename +".txt genereated";
	ui.transact_result->setText(QString::fromStdString(gen_res));
}

/*
	Populate the table with today transaction
	Return the ostring of all the transactions info incase need to write to file
	the filename is in the argument
*/
ostringstream qt_test::transact_by_Curdate(string &filename)
{

	ostringstream result;
	int j = ui.transact_report->rowCount();
	if (j>0)
	{
		for (int i=0;i<j;i++)
			ui.transact_report->removeRow(0);
		j=0;
	}
	vector<Transaction *> iList;
	Transaction *tmp;
	int size,i;
	double revenue;
	// Set up sql_connector to access database
	sql_Connector *contor=new sql_Connector();
	contor->start_Connect();
	contor->chooseDB("CG3002");
	contor->get_Curdate_Transaction(iList);
	size=iList.size();
	for (i=0;i<size;i++)
	{
		QString val;
		ostringstream convert;
		ui.transact_report->insertRow(j);
		ui.transact_report->setSortingEnabled(false);
		QTableWidgetItem *item1;
		tmp=iList[i];
		for (int z=0;z<6;z++)
		{
			switch(z)
			{
			case 0:
				val= QString::fromStdString(tmp->get_tId_toStr());
				break;
			case 1:
				val= QString::fromStdString(tmp->get_cId_toStr());
				break;
			case 2:
				val= QString::fromStdString(tmp->get_iId_toStr());
				break;
			case 3:
				val= QString::fromStdString(tmp->get_Quantity_toStr());
				break;
			case 4:
				revenue=tmp->get_Price()*tmp->get_Quantity();
				convert << revenue;
				val = QString::fromStdString(convert.str());
				break;
			case 5:
				val = QString::fromStdString(tmp->get_Date());
				filename=tmp->get_Date();
				break;
			}
			//ui.item_table->setRowCount(j);
			ui.transact_report->setItem(j,z,new QTableWidgetItem(val));
			result<< val.toStdString();
			if (z<5)
				result<<":";
			else
				result<<"\n";
		}
		delete tmp;
	}
	
	ui.transact_result->setStyleSheet("QLabel { color : green; font: bold 12px; }");
	string trans_res="Sync complete, " + convert_from_int(size) + " results found";
	ui.transact_result->setText(QString::fromStdString(trans_res));
	iList.clear();
	delete contor;

	return result;
}

string qt_test::convert_from_int(int toCon)
{
	ostringstream convert;
	convert<<toCon;
	return convert.str();
}

/*
	Open a transaction file
*/
void qt_test::on_transact_open_file_clicked()
{
	QString filename;
	filename=QFileDialog::getOpenFileName();
	QString f = QFileInfo(filename).fileName();
	ui.transact_file->setText(f);
}

/*
	Sending file chosen to HQ
*/
void qt_test::on_transact_send_clicked()
{
	string filename;
	filename=ui.transact_file->text().toStdString();
	upload(filename);
}


void qt_test::upload(string filename)
{
	CURL *curl;
  CURLcode res;

  struct curl_httppost *formpost=NULL;
  struct curl_httppost *lastptr=NULL;
  struct curl_slist *headerlist=NULL;
  static const char buf[] = "Expect:";

  curl_global_init(CURL_GLOBAL_ALL);

  /* Fill in the file upload field */
  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "sendfile",
			   CURLFORM_FILE, filename.c_str(),
               CURLFORM_END);

  /* Fill in the filename field */
  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "filename",
			   CURLFORM_COPYCONTENTS, filename.c_str(),
               CURLFORM_END);


  /* Fill in the submit field too, even if this is rarely needed */
  curl_formadd(&formpost,
               &lastptr,
               CURLFORM_COPYNAME, "submit",
               CURLFORM_COPYCONTENTS, "send",
               CURLFORM_END);

  curl = curl_easy_init();
  /* initalize custom header list (stating that Expect: 100-continue is not
     wanted */
  headerlist = curl_slist_append(headerlist, buf);
  if(curl) {
    /* what URL that receives this POST */
    curl_easy_setopt(curl, CURLOPT_URL, DST_URL);

    /* enable verbose for easier tracing */
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);


    res = curl_easy_perform(curl);

    /* always cleanup */
    curl_easy_cleanup(curl);

    /* then cleanup the formpost chain */
    curl_formfree(formpost);
    /* free slist */
    curl_slist_free_all (headerlist);
  }
}