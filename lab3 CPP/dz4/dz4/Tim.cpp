#include "Tim.h"

void Tim::kopiraj(const Tim& t)
{
	ime = t.ime;
	maxIgraca = t.maxIgraca;
	trenIgraca = t.trenIgraca;
	niz = new Igrac * [maxIgraca];
	for (int i = 0; i < maxIgraca; i++)
		niz[i] = t.niz[i];
}

void Tim::premesti(Tim& t)
{
	niz = t.niz;
	ime = t.ime;
	maxIgraca = t.maxIgraca;
	trenIgraca = t.trenIgraca;
	t.niz = nullptr;
	//t.ime = "";
	//t.maxIgraca = 0;
	//t.trenIgraca = 0;
}

void Tim::obrisi()
{
	for (int i = 0; i < maxIgraca; i++)
		niz[i] = nullptr;
	//t.ime = "";
	//t.maxIgraca = 0;
	//t.trenIgraca = 0;
	delete niz;
}