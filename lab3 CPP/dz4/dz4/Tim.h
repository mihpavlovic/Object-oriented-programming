#ifndef _Tim_h_
#define _Tim_h_
#include"Igrac.h"

class Tim
{
protected:
	string ime;
	int maxIgraca;
	int trenIgraca;
	Igrac** niz;

	void kopiraj(const Tim& t);
	void premesti(Tim& t);
	void obrisi();
	virtual void ispisi(ostream& it)
	{
		bool prvi = true;
		cout << ime;
		if (maxIgraca != 0)
		{
			it << "[";
			for (int i = 0; i < maxIgraca; i++)
			{
				if (niz[i] != nullptr)
				{
					if (prvi)
					{
						prvi = false;
						it << *(niz[i]);
					}
					else it << "," << *(niz[i]);
				}
					
			}
			it << "]";
		}
	}

public:
	//konstruktori, operatori dodele, destruktor
	Tim(string i, int max) : ime(i), maxIgraca(max), niz(new Igrac * [max]), trenIgraca(0)
	{
		for (int i = 0; i < max; i++)
			niz[i] = nullptr;
	}
	Tim(const Tim& t) { kopiraj(t); }
	Tim(Tim&& t) { premesti(t); }
	Tim& operator=(const Tim& t)
	{
		if (this != &t)
		{
			obrisi();
			kopiraj(t);
		}
		return *this;
	}
	Tim& operator=(Tim&& t)
	{
		if (this != &t)
		{
			obrisi();
			premesti(t);
		}
		return *this;
	}
	~Tim() { obrisi(); }

	//metode
	int getTrenIgraca() const { return trenIgraca; }
	int getMaxIgraca() const { return maxIgraca; }
	double srednjaVrednost() const
	{
		double tren = 0;
		for (int i = 0; i < maxIgraca; i++)
		{
			if (niz[i] != nullptr)
				tren += niz[i]->getVrednost();
		}
		tren = tren / trenIgraca;
		return tren;
	}
	virtual void prikljuci(int i, Igrac* ig) 
	{ 
		if (i >= maxIgraca) return;
		niz[i] = ig; 
		trenIgraca++; 
	}

	//preklopljeni operatori
	Igrac* operator[] (int i)
	{
		if (i >= maxIgraca) return nullptr;//ili throw exception
		return niz[i];
	}
	const Igrac* operator[] (int i) const 
	{
		if (i >= maxIgraca) return nullptr;//ili throw exception
		return niz[i];
	}
	bool operator==(Tim& t)
	{
		if (ime == t.ime && maxIgraca ==t.maxIgraca)
		{
			for (int i = 0; i < maxIgraca; i++)
			{
				if (niz[i] != t.niz[i])
					return false;
			}
			return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream& it, Tim& t)
	{
		t.ispisi(it);
		return it;
	}



};
#endif



