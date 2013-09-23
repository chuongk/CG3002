#ifndef TRANSACT_H
#define TRANSACT_H

#include <QWidget>
#include "ui_transact.h"
#include <string.h>

class transact : public QWidget
{
	Q_OBJECT

public:
	transact(QWidget *parent = 0);
	~transact();
	public slots:
		void on_transact_Cancel_clicked();
		void on_transact_Item_add_clicked();
		void on_transact_Submit_clicked();
private:
	Ui::transact ui;
	bool is_number(const std::string& s);
	int check_transact_syntax();
};

#endif // TRANSACT_H
