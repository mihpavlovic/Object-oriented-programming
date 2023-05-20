#include<iostream>
#include"Igrac.h"
#include"Tim.h"
#include"Mec.h"
#include"NijeOdigranGreska.h"
#include"DodavanjeUPrivGreska.h"
using namespace std;

int main()
{
	try
	{
		Igrac i0("miki", 912);
		Igrac i1("pera", 700);
		Igrac i2("mika");
		Igrac i3("alas", 1234);
		Igrac i4("persa", 720);
		Igrac i5("marko", 821);
		Tim t0("ok", 10);
		Tim t1("sabac", 23);
		Tim t2("beograd", 3);
		t0.prikljuci(1, &i0);
		t0.prikljuci(3, &i1);
		t0.prikljuci(6, &i2);
		t1.prikljuci(1, &i3);
		t1.prikljuci(3, &i4);
		t1.prikljuci(6, &i5);
		cout << t0 << endl;
		cout << t1 << endl;
		cout << t2 << endl;
		Mec m(&t0, &t1);
		int x1 = 0, x2 = 0;
		Par<int> x(&x1, &x2);
		m.odigrajMec();
		m.poeni(&x);
		cout << m << endl;
		cout << x << endl;

		return 0;
	}
	catch (NijeOdigranGreska n) {cout << n << endl;}
	catch (DodavanjeUPrivGreska d) { cout << d << endl; }

	
}