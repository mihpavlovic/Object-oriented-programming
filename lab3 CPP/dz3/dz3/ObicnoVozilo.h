#ifndef _ObicnoVozilo_h_
#define _ObicnoVozilo_h_
#include "Vozilo.h"
#include<iostream>
#include<string>
using namespace std;
class ObicnoVozilo : public Vozilo
{
	const int startPrice = 120;//za sva obicna vozila je ista startna cena
	double perKm = 0.1;
	
public:
	//kontruktori i operatori dodele
	ObicnoVozilo(string m):Vozilo(m){}

	//metode
	double fullPrice(int len=0) override
	{
		return startPrice + len * perKm;
	}

	//preklopljeni operatori
	friend ostream& operator<<(ostream& it, ObicnoVozilo& o)
	{
		return it<< o.getModel();
	}
	
};

#endif

