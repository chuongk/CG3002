#ifndef TRANSACT_H
#define TRANSACT_H

#include <QWidget>
#include <qdialog.h>
#include "ui_transact.h"
#include <string.h>
#include "sql_Connector.h"
using namespace std;

#define TRANS_WIDTH 404
#define TRANS_HEIGHT 266

class transact : public QDialog
{
	Q_OBJECT

public:
	transact(QDialog *parent = 0);
	~transact();
	public slots:
		void on_transact_Cancel_clicked();
		void on_transact_Item_add_clicked();
		void on_transact_Submit_clicked();
private:
	Ui::transact ui;
	bool is_number(const std::string& s);
	int check_transact_syntax();
	double check_barcode(string barcode,string quantity,int ro,sql_Connector *contor);
	int check_cashier(string cId, int ro, sql_Connector *contor);
	void Initialize();
};

#endif // TRANSACT_H
