#ifndef _Prodavac_h_
#define _Prodavac_h_
#include<iostream>
#include"Lista.h"
#include"Posiljka.h"
#include"Artikal.h"
#include"Rukovalac.h"
using namespace std;

class Prodavac : public Rukovalac
{
	struct Trojka
	{
		Artikal* art;
		double marza;
		int dani;
		Trojka(Artikal* a, double m, int d): art(a), marza(m), dani(d) {}
		~Trojka() { art = nullptr; }
	};
	string ime;
	Lista<Trojka> katalog;
	Trojka* find(Artikal* a)//trazi trojku u kojoj se nalazi potreban artikal vraca nullptr ako ne nadje
	{
		//Artikal* trazeni = p->getArtikal();
		int n = katalog.getSize();
		for (int i = 0; i < n; i++)
		{
			if (*(katalog[i]->art) == *a)
				return katalog[i];
		}
		return nullptr;
	}
public:
	//konstruktori, operatori dodele i destruktor
	Prodavac(string i):ime(i), katalog() {}
	//metode
	string getIme() const { return ime; }
	double prodajnaCena(Artikal* a) //vraca -1 ako ne nadje artikal
	{
		Trojka* t = find(a);
		if (t == nullptr) return -1;
		double vrati = a->getPurPrice() * t->marza;
		return vrati;
	}
	void handle(Posiljka* p) override
	{
		Artikal* trazeni = p->getArtikal();
		Trojka* t = find(trazeni);
		if (t == nullptr) return;
		double pPrice = t->art->getPurPrice();
		double m = t->marza * pPrice;
		izmeni(p, t->dani, m);
	}
	void dodaj(Artikal* a, double m, int d)
	{
		Trojka* t = new Trojka(a, m, d);
		katalog += t;
	}
	//preklopljeni operatori

};
#endif


