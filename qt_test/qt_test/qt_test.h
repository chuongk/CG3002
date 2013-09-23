#ifndef QT_TEST_H
#define QT_TEST_H


#include <QtWidgets/QMainWindow>
#include "ui_qt_test.h"
#include <qdesktopservices.h>
#include <qurl.h>


#define BARCODE_LENGTH 8

class qt_test : public QMainWindow
{
	Q_OBJECT

public:
	qt_test(QWidget *parent = 0);
	~qt_test();

private:
	Ui::qt_testClass ui;
	void Initialize();
	public slots:
		void on_pushButton_clicked();
		void on_dateEdit_dateChanged(const QDate &date);
		void on_SearchButton_clicked();
};

#endif // QT_TEST_H
