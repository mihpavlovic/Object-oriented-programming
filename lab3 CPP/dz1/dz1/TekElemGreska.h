#ifndef _TekElemGreska_h_
#define _TekElemGreska_h_
#include<iostream>
using namespace std;
class TekElemGreska
{
public:
	friend ostream& operator<<(ostream& it, TekElemGreska& t)
	{
		return it << "Ne postoji tekuci element.";
	}
};
#endif