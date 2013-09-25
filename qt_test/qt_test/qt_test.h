#ifndef QT_TEST_H
#define QT_TEST_H


#include <QtWidgets/QMainWindow>
#include "ui_qt_test.h"
#include <qdesktopservices.h>
#include <qurl.h>
#include <qfiledialog.h>

#include <stdio.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#define BARCODE_LENGTH 8
#define APP_WIDTH 722
#define APP_HEIGHT 432
#define DST_URL "http://cg3002-05-z.comp.nus.edu.sg/upload.php"
class qt_test : public QMainWindow
{
	Q_OBJECT

public:
	qt_test(QWidget *parent = 0);
	~qt_test();

private:
	Ui::qt_testClass ui;
	void Initialize();
	string convert_from_int(int toCon);
	ostringstream transact_by_Curdate(string &filename);

	// File sending relate here
	//static size_t read_callback(void *ptr, size_t size, size_t nmemb, void *stream);
	void upload(string filename);
	public slots:
		void on_pushButton_clicked();
		void on_dateEdit_dateChanged(const QDate &date);
		void on_SearchButton_clicked();
		void on_sync_button_clicked();
		void on_transact_generate_Report_clicked();
		void on_transact_open_file_clicked();
		void on_transact_send_clicked();
};

#endif // QT_TEST_H
