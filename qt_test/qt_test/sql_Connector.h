#ifndef SQL_CONNECTOR_H
#define SQL_CONNECTOR_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

/*
  Include directly the different
  headers from cppconn/ and mysql_driver.h + mysql_util.h
  (and mysql_connection.h). This will reduce your build time!
*/
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include "mysql_error.h"
#include <cppconn\sqlstring.h>
#include "item.h"
using namespace sql;

#define Server "localhost"
#define USR	"root"
#define PWD	""



class sql_Connector
{
private:
	string server;
	string user;
	string password;
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;
	sql::ResultSet *res;
public:
	void Initialize();
	sql_Connector();
	sql_Connector(string server_in, string usr_in, string pwd_in);
	~sql_Connector();
	void start_Connect();
	void createDB(string DB_in);
	void chooseDB(string DB_in);
	void execute_from_FILE(string file_name);
	void insert_from_FILE(string file_name);
	void insert_Transaction_from_FILE(string file_name);
	void populate_cashier_test();
	int search_from_barcode(int barcode,Item *Ifind);
	int search_general(string barcode,string iName,string iCate, string iManu,vector<Item*> &iList);
private:
	void populate_Cashier_from_FILE(string file_name,int SID);
	string toDate(string toCut);
	string makeSearchQuery(string barcode,string iName,string iCate, string iManu);
};

#endif