#ifndef _ElPorukaTekst_h_
#define _ElPorukaTekst_h_
#include<iostream>
#include<string>
#include"ElPoruka.h"
#include"VecPoslataGreska.h"
using namespace std;

class ElPorukaTekst : public ElPoruka
{
	string text;
public:
	//konstukrori i operatori dodele
	ElPorukaTekst(Korisnik* k1, Korisnik* k2, string nas): ElPoruka(k1,k2,nas), text("") {}

	//metode
	void setText(string t) 
	{ 
		if (getStanje() == POSLATA) throw VecPoslataGreska();
		text = t;
	}
	void posalji() override { stanje = POSLATA; }

	ElPoruka* kopiranje() const override
	{
		return new ElPorukaTekst(*this);
	}

	//preklopljeni operatori
	friend ostream& operator<<(ostream& it, ElPorukaTekst& e)
	{
		e.ispisi(it);
		it << endl;
		it << e.text;
		return it;
	}
};
#endif