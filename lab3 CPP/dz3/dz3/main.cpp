#include<iostream>
#include "Put.h"
#include"ListaIndexGreska.h"
#include"PutGreska.h"
#include"ObicnoVozilo.h"
#include"Lista.h"
using namespace std;

int main()
{
	try
	{
		Tacka l0(2, 3);
		Tacka l1(5, 8);
		Tacka l2(11, 3);
		Tacka l3(0, 7);
		Put x;
		x += &l0;
		x += &l1;
		x += &l2;
		x += &l3;
		cout << x << endl;
		cout << x.fullDistance() << endl;
		ObicnoVozilo voz("masina");
		cout << voz ;
	}
	catch (ListaIndexGreska e)
	{
		cout << e << endl;
	}
	catch (PutGreska g)
	{
		cout << g << endl;
	}
}