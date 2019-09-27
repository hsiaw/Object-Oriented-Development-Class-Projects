using namespace std;

#include "blurtGens.h"
#include <string>

const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;
const int DEFAULT_THRESHOLD = 5;

blurtGens::blurtGens(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, string w = "null") : gen(fT,diff), blurtReps(w)
{}

void blurtGens::reset()
{
	gen::reset();
	blurtReps::active = true;
	numPings = 0;
}

int blurtGens::query()
{
	return gen::query();
}
