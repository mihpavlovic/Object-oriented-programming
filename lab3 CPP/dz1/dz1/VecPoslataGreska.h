#ifndef _VecPoslataGreska_h_
#define _VecPoslataGreska_h_
#include<iostream>
using namespace std;

class VecPoslataGreska
{
public:
	friend ostream& operator<<(ostream& it, VecPoslataGreska& o)
	{
		return it << "Ne moze da se menja tekst posto je poruka vec poslata." << endl;
	}
};
#endif