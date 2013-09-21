#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <sstream>
using namespace std;
/*
	This class defines the item object, its attribute and further functions if necessary
*/
class Item
{
private:
	int itemId;
	string itemName;
	double price;
	string category;
	string manufacturer;
	int local_stock;
	int minimum_stock;
	int bundle_unit;
public:
	Item();
	~Item();

	int get_ItemID(){return itemId;};
	string get_ItemID_toStr();
	void set_ItemID(int iid){itemId=iid;};


	string get_ItemName(){return itemName;};
	void set_ItemName(string name){itemName=name;};

	double get_ItemPrice(){return price;};
	string get_ItemPrice_toStr();
	void set_ItemPrice(double iPrice){price=iPrice;};

	string get_ItemCategory(){return category;};
	void set_ItemCategory(string cate){category=cate;};

	string get_ItemManufacturer(){return manufacturer;};
	void set_ItemManufacturer(string manu){manufacturer=manu;};

	int get_ItemLocalStock(){return local_stock;};
	string get_ItemLocalStock_toStr();
	void set_ItemLocalStock(int lStock){local_stock=lStock;};

	int get_ItemMinStock(){return minimum_stock;};
	string get_ItemMinStock_toStr();
	void setItemMinStock(int mStock){minimum_stock=mStock;};

	int get_ItemBundelUnit(){return bundle_unit;};
	string get_ItemBundelUnit_toStr();
	void setItemBundleUnit(int bundle){bundle_unit=bundle;};
};
#endif