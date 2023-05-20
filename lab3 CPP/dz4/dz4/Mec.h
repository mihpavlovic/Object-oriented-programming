#ifndef _Mec_h_
#define _Mec_h_
#include"Par.h"
#include"Tim.h"
#include"Igrac.h"
#include"NijeOdigranGreska.h"
class Mec
{
public:
	enum Ishod{NEODIGRANO=0,NERESENO=1, POBEDA_DOMACIN=2, POBEDA_GOST=3};
private:
	Par<Tim> par;//domacin je p1 a gost p2
	Ishod ishodMeca;
public:
	//konstuktori
	Mec(Tim* t1, Tim* t2): par(t1, t2), ishodMeca(NEODIGRANO) {}

	//metode
	Par<Tim>& getPar() { return par; }
	Ishod getIshodMeca() const { return ishodMeca; }
	bool isOdigran() const
	{
		if (ishodMeca != NEODIGRANO) return true;
		return false;
	}
	void odigrajMec()
	{
		int vr1 = 0;
		int povecanje = 10;
		int vr2 = 0;
		Tim* domacin = par.getP1();
		Tim* gost = par.getP2();
		int max1 = domacin->getMaxIgraca();
		int max2 = gost->getMaxIgraca();
		//pronalazenje vrednosti timova
		for (int i = 0; i < max1; i++)
		{
			if((*domacin)[i] !=nullptr)
				vr1 += (*domacin)[i]->getVrednost();
		}
		for (int i = 0; i < max2; i++)
		{
			if ((*gost)[i] != nullptr)
				vr1 += (*gost)[i]->getVrednost();
		}
		//odredjivanje ishoda meca 
		if (vr1 == vr2)
		{
			ishodMeca = NERESENO;
			return;
		}
		if (vr1 > vr2)//pobedio domacin
			ishodMeca = POBEDA_DOMACIN;
		else
		{
			ishodMeca = POBEDA_GOST;
			povecanje = -povecanje;
		}
		//postavljanje vrednosti timova
		for (int i = 0; i < max1; i++)
		{
			if ((*domacin)[i] != nullptr)
				(*domacin)[i]->povecajVr(povecanje);
		}
		for (int i = 0; i < max2; i++)
		{
			if ((*gost)[i] != nullptr)
				(*gost)[i]->povecajVr(-povecanje);
		}
		return;

	}
	void poeni(Par<int>* p)
	{
		int poeni1 = 0;
		int poeni2 = 0;
		if (ishodMeca == NERESENO)
		{
			poeni1 = 1;
			poeni2 = 1;
		}
		else if (ishodMeca == POBEDA_DOMACIN)
		{
			poeni1 = 3;
			poeni2 = 0;
		}
		else if (ishodMeca == POBEDA_GOST)
		{
			poeni1 = 0;
			poeni2 = 3;
		}
		else throw NijeOdigranGreska();
		p->setP1Value(poeni1);
		p->setP2Value(poeni2);
	}
	//preklopljeni operatori
	friend ostream& operator<<(ostream& it, Mec& m)
	{
		it << m.par << endl;
		if(m.ishodMeca!=NEODIGRANO)
			it << m.ishodMeca;
		return it;
	}
};
#endif



