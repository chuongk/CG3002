#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <sstream>
using namespace std;

class Transaction
{
private:
	int tId;
	int cId;
	int iId;
	string tDate;
	int quantity;
	double price;
public:
	Transaction();
	Transaction(int ItId, int IcId, int IiId, string iDate, int Iquantiy, double Iprice);
	~Transaction();

	int get_tId();
	int get_cId();
	int get_iId();
	string get_Date();
	int get_Quantity();
	double get_Price();

	void set_tId(int ItId);
	void set_cId(int IcId);
	void set_iId(int IiId);
	void set_Date(string iDate);
	void set_Quantity(int Iquantity);
	void set_Price(double Iprice);

	string get_tId_toStr();
	string get_cId_toStr();
	string get_iId_toStr();
	string get_Quantity_toStr();
	string get_Price_toStr();
};
#endif