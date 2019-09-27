using namespace std;

#include "blurtSkipGens.h"
#include <string>

const int DEFAULT_K = 3;
const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;

blurtSkipGens::blurtSkipGens(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newK = DEFAULT_K, string w = "null"): skipGen(fT,diff,newK), blurtReps(w)
{}

void blurtSkipGens::reset()
{
	skipGen::reset();
	blurtReps::active = true;
	numPings = 0;
}

int blurtSkipGens::query()
{
	return skipGen::query();
}
