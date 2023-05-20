#ifndef _Put_h_
#define _Put_h_
#include "Lista.h"
#include "Tacka.h"
#include "PutGreska.h"

using namespace std;
class Put
{
	Lista <Tacka> start;
public:
	//konstruktori i operatori dodele
	Put() = default;
	//metode
	double fullDistance()
	{
		int n = start.getSize();
		double dist = 0;
		for (int i = 0; i < n-1; i++)
			dist += start[i]->distance(*(start[i+1]));
		return dist;
	}
	//preklopljeni operatori
	Put& operator+=(Tacka* t)
	{
		bool uListi = false;
		int n = start.getSize();
		for (int i = 0; i < n; i++)
		{
			if (start[i] == t)
			{
				uListi = true;
				break;
			}
		}
		if(uListi) throw PutGreska();
		start += t;
		return *this;
	}
	friend ostream& operator<<(ostream& out, Put& p)
	{
		int n = p.start.getSize();
		for (int i = 0; i < n; i++)
			out << *p.start[i] << endl;
		return out;
	}
};
#endif


