#ifndef _Privilegovani_h_
#define _Privilegovani_h_
#include<iostream>
#include"Tim.h"
#include"DodavanjeUPrivGreska.h"
using namespace std;
class Privilegovani : public Tim 
{
	int minVr;
public:
	//konstruktori
	Privilegovani(int m, string ime, int maks): minVr(m), Tim(ime, maks) {}
	
	//metode
	void prikljuci(int i, Igrac* ig) override
	{
		if (ig == nullptr) return;
		if (ig->getVrednost() < minVr) throw DodavanjeUPrivGreska();
		if (i >= maxIgraca) return;
		niz[i] = ig;
		trenIgraca++;
	}

	//preklopljeni operatori
	friend ostream& operator<<(ostream& it, Privilegovani& p)
	{
		p.ispisi(it);
		it << endl;
		it << "("<<p.minVr <<")";
		return it;
	}
};
#endif



