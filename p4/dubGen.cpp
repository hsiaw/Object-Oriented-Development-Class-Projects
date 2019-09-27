using namespace std;

#include "dubGen.h"

const int DEFAULT_P = 3;
const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;

dubGen::dubGen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newP = DEFAULT_P) : gen(fT,diff)
{
	p = newP;
}

void dubGen::setP(int newP)
{
	p = newP;
}

void dubGen::reset()
{
	gen::reset();
	p = DEFAULT_P;
	index = 1;
}

int dubGen::query()
{
	if(index == threshold)
	{
		active = false;
	}
	if(active)
	{
		int retVal;
		if((index % p) == 0)
		{
			retVal = (2* (firstTerm + (index - 1) * difference));
		}
		else
		{
			retVal = (firstTerm + (index -1) * difference);
		}
		index++;
		return retVal;
	}
	else
	{
		return -1;
	}
}
