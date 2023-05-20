#ifndef _Artikal_h_
#define _Artikal_h_
#include<iostream>
#include<string>
using namespace std;
class Artikal
{
	string name;
	int barcode;
	double purPrice;
public:
	//konstruktori i operatori dodele
	Artikal(string n, int code, double price): name(n), barcode(code), purPrice(price) {}

	//metode
	string getName() const { return name; }
	int getBarcode() const { return barcode; }
	double getPurPrice() const { return purPrice; }

	//preklopljeni operaotri
	bool operator==(Artikal& a)
	{
		return a.barcode == this->barcode;
	}
};
#endif


