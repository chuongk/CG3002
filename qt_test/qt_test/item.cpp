#include "item.h"

Item::Item()
{
}

Item::~Item()
{
}

/*
	Return ItemId in std::string formm
*/
string Item::get_ItemID_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << itemId;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the strea
	return Result;
}

string Item::get_ItemPrice_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << price;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the stream
	return Result;
}

string Item::get_ItemLocalStock_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << local_stock;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the stream
	return Result;
}

string Item::get_ItemMinStock_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << minimum_stock;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the stream
	return Result;
}

string Item::get_ItemBundelUnit_toStr()
{
	string Result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << bundle_unit;      // insert the textual representation of 'Number' in the characters in the stream
	Result = convert.str(); // set 'Result' to the contents of the strea
	return Result;
}