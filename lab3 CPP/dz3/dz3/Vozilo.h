#ifndef _Vozilo_h_
#define _Vozilo_h_
#include<iostream>
using namespace std;

class Vozilo
{
	string model;
public:
	Vozilo(string m): model(m) {}
	
	//metode
	virtual string getModel()const { return model; }
	virtual double fullPrice(int len) = 0;

};
#endif


