#ifndef BLURTGENS_H
#define BLURTGENS_H
#include "blurtReps.h"
#include "gen.h"

class blurtGens: public gen, public blurtReps
{
  public:
	blurtGens(int, int, string);
	void reset();
	int query();
};
#endif
