/********************************************************************************
** Form generated from reading UI file 'transact.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACT_H
#define UI_TRANSACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transact
{
public:
    QTableWidget *transact_table;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *transact_Item_add;
    QPushButton *transact_Submit;
    QPushButton *transact_Cancel;

    void setupUi(QWidget *transact)
    {
        if (transact->objectName().isEmpty())
            transact->setObjectName(QStringLiteral("transact"));
        transact->resize(302, 221);
        transact_table = new QTableWidget(transact);
        if (transact_table->columnCount() < 3)
            transact_table->setColumnCount(3);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        transact_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        transact_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        transact_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        transact_table->setObjectName(QStringLiteral("transact_table"));
        transact_table->setGeometry(QRect(0, 30, 301, 192));
        layoutWidget = new QWidget(transact);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 239, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        transact_Item_add = new QPushButton(layoutWidget);
        transact_Item_add->setObjectName(QStringLiteral("transact_Item_add"));

        horizontalLayout->addWidget(transact_Item_add);

        transact_Submit = new QPushButton(layoutWidget);
        transact_Submit->setObjectName(QStringLiteral("transact_Submit"));

        horizontalLayout->addWidget(transact_Submit);

        transact_Cancel = new QPushButton(layoutWidget);
        transact_Cancel->setObjectName(QStringLiteral("transact_Cancel"));

        horizontalLayout->addWidget(transact_Cancel);


        retranslateUi(transact);

        QMetaObject::connectSlotsByName(transact);
    } // setupUi

    void retranslateUi(QWidget *transact)
    {
        transact->setWindowTitle(QApplication::translate("transact", "transact", 0));
        QTableWidgetItem *___qtablewidgetitem = transact_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("transact", "Barcode", 0));
        QTableWidgetItem *___qtablewidgetitem1 = transact_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("transact", "Quantity", 0));
        QTableWidgetItem *___qtablewidgetitem2 = transact_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("transact", "Cashier ID", 0));
        transact_Item_add->setText(QApplication::translate("transact", "Add Item", 0));
        transact_Submit->setText(QApplication::translate("transact", "Submit", 0));
        transact_Cancel->setText(QApplication::translate("transact", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class transact: public Ui_transact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACT_H
