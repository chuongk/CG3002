#include "Transaction.h"

Transaction::Transaction()
{
}
Transaction::Transaction(int ItId, int IcId, int IiId, string iDate, int Iquantiy, double Iprice)
{
	tId=ItId;
	cId=IcId;
	iId=IiId;
	tDate=iDate;
	quantity=Iquantiy;
	price=Iprice;
}
Transaction::~Transaction()
{
}
int Transaction::get_tId()
{
	return tId;
}
int Transaction::get_cId()
{
	return cId;
}
int Transaction::get_iId()
{
	return iId;
}
string Transaction::get_Date()
{
	return tDate;
}
int Transaction::get_Quantity()
{
	return quantity;
}
double Transaction::get_Price()
{
	return price;
}

void Transaction::set_tId(int ItId)
{
	tId=ItId;
}
void Transaction::set_cId(int IcId)
{
	cId=IcId;
}
void Transaction::set_iId(int IiId)
{
	iId=IiId;
}
void Transaction::set_Date(string iDate)
{
	tDate=iDate;
}
void Transaction::set_Quantity(int Iquantity)
{
	quantity=Iquantity;
}
void Transaction::set_Price(double Iprice)
{
	price=Iprice;
}

string Transaction::get_tId_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << tId;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the strea
	return Result;
}
string Transaction::get_cId_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << cId;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the strea
	return Result;
}
string Transaction::get_iId_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << iId;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the strea
	return Result;
}
string Transaction::get_Quantity_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << quantity;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the strea
	return Result;
}
string Transaction::get_Price_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << price;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the strea
	return Result;
}