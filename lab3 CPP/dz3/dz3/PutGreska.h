#ifndef _PutGreska_h_
#define _PutGreska_h_
#include<iostream>
using namespace std;
class PutGreska
{
public:
	friend ostream& operator<<(ostream& out, PutGreska& p)
	{
		return out << "Ova tacka vec postoji u putu.";
	}
};

#endif 