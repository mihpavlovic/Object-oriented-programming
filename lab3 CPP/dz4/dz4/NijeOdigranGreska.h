#ifndef _NijeOdigranGreska_h_
#define _NijeOdigranGreska_h_
#include<iostream>
using namespace std;
class NijeOdigranGreska
{
	friend ostream& operator<<(ostream& it, NijeOdigranGreska& n)
	{
		return it << "Mec nije odigran.";
	}
};
#endif 