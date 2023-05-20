#ifndef _ImaDetaljaGreska_h_
#define _ImaDetaljaGreska_h_
#include<iostream>
using namespace std;
class ImaDetaljaGreska
{
	friend ostream& operator<<(ostream& it, ImaDetaljaGreska& i)
	{
		return it << "Ne moze da se doda rukovalac kad su vec izracunati detalji.";
	}
};

#endif 