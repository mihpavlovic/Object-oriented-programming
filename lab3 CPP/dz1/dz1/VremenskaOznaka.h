#ifndef _VremenskaOznaka_h_
#define _VremenskaOznaka_h_
#include<iostream>
using namespace std;
class VremenskaOznaka
{
	int godina;
	int mesec;
	int dan;
	int sat;
	int minuti;
public:
	VremenskaOznaka(int g, int m, int d, int s, int min) : godina(g), mesec(m), dan(d), sat(s), minuti(m)
	{
		if (minuti / 60)
		{
			minuti = minuti % 60;
			sat += 1;
		}
		if (sat / 24)
		{
			sat = sat % 24;
			dan += 1;
		}
		if (dan / 32)
		{
			dan = dan % 32;
			mesec += 1;
		}
		if (mesec / 13)
		{
			mesec = mesec % 13;
			godina++;
		}
	}
	friend ostream& operator<<(ostream& it, VremenskaOznaka& v)
	{
		return it << v.dan << "." << v.mesec << "." << v.godina << "-" << v.sat << ":" << v.minuti;
	}
};
#endif
