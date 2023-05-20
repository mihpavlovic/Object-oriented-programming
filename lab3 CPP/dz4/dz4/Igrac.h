#ifndef _Igrac_h_
#define _Igrac_h_
#include<iostream>
#include<string>
using namespace std;

class Igrac
{
	string ime;
	int vrednost;
public:
	//konstruktori
	Igrac(string i, int v=1000): ime(i), vrednost(v) {}

	//
	string getIme() const { return ime; }
	int getVrednost() const { return vrednost; }
	void povecajVr(double per) { vrednost += (per / 100) * vrednost; } 

	//preklopljeni operatori
	bool operator==(Igrac& i)
	{
		if (this->ime == i.ime && this->vrednost == i.vrednost)
			return true;
		return false;
	}
	friend ostream& operator<<(ostream& it, Igrac& i)
	{
		if(&i!=nullptr)
			it << i.ime << "#" << i.vrednost;
		return it;
	}

};
#endif



