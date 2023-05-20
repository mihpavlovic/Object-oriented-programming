#ifndef _ListaIndexGreska_
#define _ListaIndexGreska_
#include<iostream>
using namespace std;
class ListaIndexGreska
{
	friend ostream& operator<<(ostream& out, ListaIndexGreska x)
	{
		return out << "Pristupanje nevalidnom indeksu.";
	}
};

#endif 