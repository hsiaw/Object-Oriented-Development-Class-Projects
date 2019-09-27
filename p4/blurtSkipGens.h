#ifndef BLURTSKIPGENS_H
#define BLURTSKIPGENS_H

#include "blurtReps.h"
#include "skipGen.h"
#include <string>

class blurtSkipGens: public blurtReps, public skipGen
{
  public:
	blurtSkipGens(int, int, int, string);
	void reset();
	int query();
};
#endif


