#ifndef _Korisnik_h_
#define _Korisnik_h_
#include <iostream>
#include <string>
using namespace std;
class Korisnik
{
	string ime;
	int adresa;
public:
	//konstruktori i operatori dodele
	Korisnik(string i, int a):ime(i),adresa(a){}
	Korisnik(const Korisnik&) = delete;
	Korisnik(Korisnik&&) = delete;
	Korisnik& operator=(const Korisnik&) = delete;
	Korisnik& operator=(Korisnik&&) = delete;

	//metode
	string getIme() const { return ime; }
	int getAdresa() const { return adresa; }
	
	//preklopljeni operatori
	friend ostream& operator<<(ostream& it, Korisnik& k)
	{
		return it << "(" << k.ime << ")" << k.adresa;
	}
};
#endif
