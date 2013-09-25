#ifndef QT_TEST_H
#define QT_TEST_H


#include <QtWidgets/QMainWindow>
#include "ui_qt_test.h"
#include <qdesktopservices.h>
#include <qurl.h>

#include <string>
#include <sstream>
#include <fstream>
using namespace std;

#define BARCODE_LENGTH 8
#define APP_WIDTH 722
#define APP_HEIGHT 432
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
	public slots:
		void on_pushButton_clicked();
		void on_dateEdit_dateChanged(const QDate &date);
		void on_SearchButton_clicked();
		void on_sync_button_clicked();
		void on_transact_generate_Report_clicked();
};

#endif // QT_TEST_H
