#include<iostream>
#include"Lista.h"
#include"ElPorukaTekst.h"
#include"ElPoruka.h"
#include"VremenskaOznaka.h"
#include"Korisnik.h"
#include"TekElemGreska.h"
#include"VecPoslataGreska.h"
using namespace std;
int main()
{/*
	Lista<int> x;
	int a0 = 5, a1 = 3, a2 = 10, a3 = 11;
	
	x.dodaj(&a0);
	x.dodaj(&a1);
	x.dodaj(&a2);
	x.dodaj(&a3);
	//cout << x;
	x.naPrvi();
	x.naSled();
	x.naSled();
	x.naSled();
	x.naSled();
	x.pisiCurr();*/
	try
	{
		Korisnik k1("Pera", 9);
		Korisnik k2("Mika", 19);
		ElPorukaTekst x(&k1, &k2, "Naslov poruke");//prvo ide primalac pa posiljalac
		//ElPorukaTekst x1 = x;
		string t = "Tekst poruke";
		x.setText(t);
		x.posalji();
		//x.setText("Tekst poruke 2");
		cout << x << endl;
		return 0;
	}
	catch (TekElemGreska e)
	{
		cout << e << endl;
	}
	catch (VecPoslataGreska v)
	{
		cout << v << endl;
	}
}