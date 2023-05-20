#ifndef _Par_h_
#define _Par_h_
#include<iostream>
using namespace std;
template<typename T>
class Par
{
	T* p1;
	T* p2;
public:
	//konstruktor
	Par(T* t1, T* t2): p1(t1), p2(t2) {}
	
	//metodi
	T* getP1()const { return p1; }
	T* getP2()const { return p2; }
	void setP1(T* s1) { p1 = s1; }
	void setP2(T* s2) { p2 = s2; }
	void setP1Value(T s1) { *p1 = s1; }
	void setP2Value(T s2) { *p2 = s2; }

	//preklopljeni operatori
	bool operator==(Par& t1)
	{
		if (p1 == t1.p1 && p2 == t1.p2)
			return true;
		return false;
	}
	friend ostream& operator<< (ostream& it, Par& par)
	{
		return it << "[" << *(par.p1) << "-" << *(par.p2) << "]";
	}
};
#endif



