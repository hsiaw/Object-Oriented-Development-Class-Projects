using namespace std;

#include "blurtDubGens.h"
#include <string>

const int DEFAULT_P = 3;
const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;

blurtDubGens::blurtDubGens(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newP = DEFAULT_P, string w = "null"): dubGen(fT,diff,newP), blurtReps(w)
{}

void blurtDubGens::reset()
{
	dubGen::reset();
	blurtReps::active = true;
	numPings = 0;
}

int blurtDubGens::query()
{
	return dubGen::query();
}
