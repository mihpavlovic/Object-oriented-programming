#ifndef _Rukovalac_h_
#define _Rukovalac_h_
#include<iostream>

using namespace std;
class Posiljka;
class Rukovalac
{
protected:
	virtual void izmeni(Posiljka* p, int d, double m);//definicija u Posiljka.cpp
public:
	virtual void handle(Posiljka* p) = 0;
};
#endif


