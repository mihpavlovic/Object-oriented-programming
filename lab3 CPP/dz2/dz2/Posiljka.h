#ifndef _Posiljka_h_
#define _Posiljka_h_
#include"Rukovalac.h"
#include"Artikal.h"
#include"Lista.h"
#include"ImaDetaljaGreska.h"
#include"NemaDetaljaGreska.h"


class Posiljka
{
public:
	struct Details
	{
		int cekanje;
		double cena;
		Details():cekanje(0), cena(0) {}
	};
private:
	friend class Rukovalac;
	Artikal* art;
	static int ukupno;//u main.cpp postavljen iznad main funkcije
	int id = ukupno++;
	Lista<Rukovalac> lista;
	Details detalji;
public:
	//konstruktori
	Posiljka(Artikal* a): art(a), detalji(), lista() {}

	//metode
	Artikal* getArtikal()const { return art; }
	int getId() const { return id; }
	Details getDetails()const
	{ 
		if (detalji.cena == 0 && detalji.cekanje == 0) throw NemaDetaljaGreska();
		else return detalji; 
	}
	void ispisiDetalje()const//pomocna funkcija za proveru 
	{
		cout << "Cena/Cekanje:" << endl;
		cout << detalji.cena << "/";
		cout << detalji.cekanje << endl;
	}
	void obradi()
	{
		int n = lista.getSize();
		for (int i = 0; i < n; i++)
		{
			lista[i]->handle(this);
		}
		//return *this;
	}

	//preklopljeni operatori
	Posiljka& operator+=(Rukovalac* r)
	{
		if (detalji.cekanje == 0 && detalji.cena == 0)
		{
			lista += r;
			return *this;
		}
		else throw ImaDetaljaGreska();
	}
	friend ostream& operator<<(ostream& it, Posiljka& p)
	{
		return it << "Posiljka[" << p.id << ", " << p.art->getName() << "]";
	}

};




#endif


