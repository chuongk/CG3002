/********************************************************************************
** Form generated from reading UI file 'qt_test.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_TEST_H
#define UI_QT_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qt_testClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QPushButton *SearchButton;
    QTableWidget *item_table;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *barcode_line;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLineEdit *name_line;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *cate_line;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *manu_line;
    QLabel *result_label;
    QWidget *tab_4;
    QTabWidget *transact_table;
    QWidget *tab_5;
    QTableWidget *transact_report;
    QWidget *tab_6;
    QLabel *label_5;
    QPushButton *sync_button;
    QPushButton *pushButton_2;
    QWidget *tab;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QWidget *tab_2;
    QDateEdit *dateEdit;
    QTextEdit *textEdit_2;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *qt_testClass)
    {
        if (qt_testClass->objectName().isEmpty())
            qt_testClass->setObjectName(QStringLiteral("qt_testClass"));
        qt_testClass->resize(722, 432);
        centralWidget = new QWidget(qt_testClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 721, 381));
        tabWidget->setAutoFillBackground(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        SearchButton = new QPushButton(tab_3);
        SearchButton->setObjectName(QStringLiteral("SearchButton"));
        SearchButton->setGeometry(QRect(640, 10, 75, 23));
        item_table = new QTableWidget(tab_3);
        if (item_table->columnCount() < 8)
            item_table->setColumnCount(8);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        item_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font);
        item_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font);
        item_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font);
        item_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font);
        item_table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        item_table->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font);
        item_table->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font);
        item_table->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        item_table->setObjectName(QStringLiteral("item_table"));
        item_table->setGeometry(QRect(0, 50, 711, 301));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        item_table->setFont(font1);
        item_table->setLayoutDirection(Qt::LeftToRight);
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 131, 41));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        barcode_line = new QLineEdit(layoutWidget);
        barcode_line->setObjectName(QStringLiteral("barcode_line"));

        verticalLayout->addWidget(barcode_line);

        layoutWidget_2 = new QWidget(tab_3);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 0, 131, 41));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        name_line = new QLineEdit(layoutWidget_2);
        name_line->setObjectName(QStringLiteral("name_line"));

        verticalLayout_2->addWidget(name_line);

        layoutWidget_3 = new QWidget(tab_3);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(260, 0, 131, 41));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        cate_line = new QLineEdit(layoutWidget_3);
        cate_line->setObjectName(QStringLiteral("cate_line"));

        verticalLayout_3->addWidget(cate_line);

        layoutWidget_4 = new QWidget(tab_3);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(390, 0, 131, 41));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        manu_line = new QLineEdit(layoutWidget_4);
        manu_line->setObjectName(QStringLiteral("manu_line"));

        verticalLayout_4->addWidget(manu_line);

        result_label = new QLabel(tab_3);
        result_label->setObjectName(QStringLiteral("result_label"));
        result_label->setGeometry(QRect(530, 10, 111, 21));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        transact_table = new QTabWidget(tab_4);
        transact_table->setObjectName(QStringLiteral("transact_table"));
        transact_table->setGeometry(QRect(0, 40, 711, 321));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        transact_report = new QTableWidget(tab_5);
        if (transact_report->columnCount() < 6)
            transact_report->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font);
        transact_report->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font);
        transact_report->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font);
        transact_report->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font);
        transact_report->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font);
        transact_report->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        transact_report->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        transact_report->setObjectName(QStringLiteral("transact_report"));
        transact_report->setGeometry(QRect(0, 0, 701, 291));
        transact_table->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        transact_table->addTab(tab_6, QString());
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 10, 46, 13));
        sync_button = new QPushButton(tab_4);
        sync_button->setObjectName(QStringLiteral("sync_button"));
        sync_button->setGeometry(QRect(420, 30, 75, 23));
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 30, 91, 23));
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 339, 73));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout->addWidget(textEdit);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        dateEdit = new QDateEdit(tab_2);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(460, 0, 110, 22));
        textEdit_2 = new QTextEdit(tab_2);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(460, 40, 104, 71));
        tableWidget = new QTableWidget(tab_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(160, 80, 256, 192));
        tabWidget->addTab(tab_2, QString());
        qt_testClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(qt_testClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 722, 21));
        qt_testClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(qt_testClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        qt_testClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(qt_testClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        qt_testClass->setStatusBar(statusBar);

        retranslateUi(qt_testClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(qt_testClass);
    } // setupUi

    void retranslateUi(QMainWindow *qt_testClass)
    {
        qt_testClass->setWindowTitle(QApplication::translate("qt_testClass", "qt_test", 0));
        SearchButton->setText(QApplication::translate("qt_testClass", "Search", 0));
        QTableWidgetItem *___qtablewidgetitem = item_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("qt_testClass", "itemId", 0));
        QTableWidgetItem *___qtablewidgetitem1 = item_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("qt_testClass", "itemName", 0));
        QTableWidgetItem *___qtablewidgetitem2 = item_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("qt_testClass", "category", 0));
        QTableWidgetItem *___qtablewidgetitem3 = item_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("qt_testClass", "manufacturer", 0));
        QTableWidgetItem *___qtablewidgetitem4 = item_table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("qt_testClass", "price", 0));
        QTableWidgetItem *___qtablewidgetitem5 = item_table->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("qt_testClass", "local_stock", 0));
        QTableWidgetItem *___qtablewidgetitem6 = item_table->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("qt_testClass", "minimum_stock", 0));
        QTableWidgetItem *___qtablewidgetitem7 = item_table->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("qt_testClass", "bundle_unit", 0));
        label->setText(QApplication::translate("qt_testClass", "Barcode ", 0));
        barcode_line->setText(QString());
        label_2->setText(QApplication::translate("qt_testClass", "Name", 0));
        name_line->setText(QString());
        label_3->setText(QApplication::translate("qt_testClass", "Category", 0));
        cate_line->setText(QString());
        label_4->setText(QApplication::translate("qt_testClass", "Manufacturer", 0));
        manu_line->setText(QString());
        result_label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("qt_testClass", "Search Item", 0));
        QTableWidgetItem *___qtablewidgetitem8 = transact_report->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("qt_testClass", "Transaction ID", 0));
        QTableWidgetItem *___qtablewidgetitem9 = transact_report->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("qt_testClass", "Cashier ID", 0));
        QTableWidgetItem *___qtablewidgetitem10 = transact_report->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("qt_testClass", "Item ID", 0));
        QTableWidgetItem *___qtablewidgetitem11 = transact_report->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("qt_testClass", "Unit Sold", 0));
        QTableWidgetItem *___qtablewidgetitem12 = transact_report->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("qt_testClass", "Revenue", 0));
        QTableWidgetItem *___qtablewidgetitem13 = transact_report->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("qt_testClass", "Date", 0));
        transact_table->setTabText(transact_table->indexOf(tab_5), QApplication::translate("qt_testClass", "Today", 0));
        transact_table->setTabText(transact_table->indexOf(tab_6), QApplication::translate("qt_testClass", "Tab 2", 0));
        label_5->setText(QApplication::translate("qt_testClass", "Sort by", 0));
        sync_button->setText(QApplication::translate("qt_testClass", "Sync", 0));
        pushButton_2->setText(QApplication::translate("qt_testClass", "Generate Report", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("qt_testClass", "Transactions", 0));
        pushButton->setText(QApplication::translate("qt_testClass", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("qt_testClass", "To PHP MyAdmin", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("qt_testClass", "Abc", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("qt_testClass", "BCd", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("qt_testClass", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class qt_testClass: public Ui_qt_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_TEST_H
