#ifndef _NemaDetaljaGreska_h_
#define _NemaDetaljaGreska_h_
#include<iostream>
using namespace std;

class NemaDetaljaGreska
{
	friend ostream& operator<<(ostream& it, NemaDetaljaGreska& n)
	{
		return it << "Nisu izracunati detalji te se ne mogu dohvatiti.";
	}
};
#endif