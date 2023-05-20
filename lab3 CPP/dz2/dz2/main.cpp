#include<iostream>
#include"Lista.h"
#include"Artikal.h"
#include"Posiljka.h"
#include"Rukovalac.h"
#include"Prodavac.h"
#include"ImaDetaljaGreska.h"
#include"NemaDetaljaGreska.h"
#include"ListaIndexGreska.h"

using namespace std;
int Posiljka::ukupno = 0;
int main()
{
	try 
	{
		Artikal a0("mleko", 1231, 50.99);
		Artikal a1("kola", 4110, 80.99);
		Artikal a2("sprajt", 4111, 111.99);
		Artikal a3("fanta", 4112, 79);
		Posiljka p0(&a0);
		//Posiljka p1(&a1);
		//Posiljka p2(&a2);
		Prodavac pro0("miks");
		Prodavac pro1("nadjica");
		Prodavac pro2("dunja");
		cout << p0 << endl;
		//cout << p1 << endl;
		//cout << p2 << endl;
		p0.ispisiDetalje();
		p0 += &pro0;
		p0 += &pro1;
		p0 += &pro2;
		pro0.dodaj(&a0, 0.2, 1);
		pro1.dodaj(&a0, 0.7, 3);
		pro2.dodaj(&a0, 0.3, 8);
		p0.obradi();
		p0.ispisiDetalje();
		//cout << "Prodajna cena:" << pro0.prodajnaCena(&a0) << endl;
		return 0;
	}
	catch (ImaDetaljaGreska i) { cout << i << endl; }
	catch (NemaDetaljaGreska n) { cout << n << endl; }
	catch (ListaIndexGreska l) { cout << l << endl; }
	

}