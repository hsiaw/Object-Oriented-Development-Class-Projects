using namespace std;

#include "gen.h"

const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;
const int DEFAULT_THRESHOLD = 5;

gen::gen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE)
{
	firstTerm = fT;
	difference = diff;
	index = 1;
	active = true;
	threshold = DEFAULT_THRESHOLD;
}



void gen::setDiff(int nDiff)
{
	difference = nDiff;
}

void gen::setfT(int fT)
{
	firstTerm = fT;
}

void gen::reset()
{
	active = true;
}

int gen::query()
{
	if(index == threshold)
	{
		threshold += threshold;
		active = false;
	}
	if(active)
	{
		int nextInt = (firstTerm + (index - 1) * difference);
		index++;
		return nextInt;
	}
	else
	{
		return -1;
	}
}
