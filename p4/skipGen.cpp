using namespace std;

#include "skipGen.h"

const int DEFAULT_K = 3;
const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;

skipGen::skipGen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newK = DEFAULT_K) : gen(fT,diff)
{
	k = newK;
	numResets = 0;
}

void skipGen::setK(int newK)
{
	k = newK;
}

void skipGen::reset()
{
	if(numResets != k)
	{
		gen::reset();
		k = DEFAULT_K;
		numResets++;
	}
	else
	{
		return;
	}
}

int skipGen::query() 
{
	int retVal;
	if(active)
	{
		int skipNum = getSkip();
		retVal = (firstTerm + (index - 1) * difference);
		index += skipNum;
		skip++;
	}
	else
	{
		retVal = -1;
	}
	if(skip == threshold)
	{
		active = false;
		skip = 0;
	}
	return retVal;
}

int skipGen::getSkip()
{
	int retVal = (numResets % 3);
	if(retVal == 2)
	{
		retVal = k;
	}
	return retVal;
}
