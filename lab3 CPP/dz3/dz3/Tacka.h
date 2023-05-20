#ifndef _Tacka_h_
#define _Tacka_h_
#include<iostream>
#include<cmath>
using namespace std;
class Tacka
{
	int x, y;
public:
	//konstruktor
	Tacka (int a, int b): x(a), y(b) {}
	
	//metode
	double distance(Tacka& a)
	{
		return sqrt( pow(a.x-this->x, 2)+pow(a.y-this->y,2) );
	}
	
	//preklopljeni operatori
	bool operator==(Tacka& dr)
	{
		if (this->x == dr.x && this->y == dr.y) return true;
		return false;
	}
	friend ostream& operator<<(ostream& out, Tacka& t)
	{
		return out << "(" << t.x << "," << t.y << ")";
	}
};
#endif


