#include "Posiljka.h"
void Rukovalac::izmeni(Posiljka* p, int d, double m)
{
	p->detalji.cekanje += d;
	p->detalji.cena += m;
}

