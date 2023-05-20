#ifndef _ElPoruka_h_
#define _ElPoruka_h_
#include<iostream>
#include<string>
#include"Korisnik.h"
using namespace std;
class ElPoruka
{
public:
	enum En { U_PRIPREMI, POSLATA, PRIMLJENA };
protected:
	
	Korisnik* prim;
	Korisnik* pos;
	string naslov;
	En stanje;
	virtual void ispisi(ostream& a)
	{
		a << naslov << endl;
		a << *pos << endl;
		a << *prim;
	}
public:
	//konstruktor
	ElPoruka(Korisnik* k1, Korisnik* k2, string nas) : prim(k1), pos(k2), naslov(nas), stanje(U_PRIPREMI) {}

	//metode
	Korisnik* getPos() const { return pos; }
	Korisnik* getPrim() const { return prim; }
	string getNaslov() const { return naslov; }
	En getStanje() const { return stanje; }
	virtual void posalji() = 0;
	virtual ElPoruka* kopiranje() const = 0;
	//preklopljeni operatori
	friend ostream& operator<< (ostream& it, ElPoruka& e)
	{
		e.ispisi(it);
		return it;
	}


};
#endif
