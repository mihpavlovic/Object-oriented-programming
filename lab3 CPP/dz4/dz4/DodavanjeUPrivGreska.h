#ifndef _DodavanjeUPrivGreska_h_
#define _DodavanjeUPrivGreska_h_
#include<iostream>
using namespace std;
class DodavanjeUPrivGreska
{
public:
	friend ostream& operator<<(ostream& it, DodavanjeUPrivGreska& d)
	{
		it << "Ne moze da se doda igrac koji ima manju od minimalne vrednosti";
		return it;
	}
};

#endif 