#ifndef BLURTDUBGENS_H
#define BLURTDUBGENS_H

#include "blurtReps.h"
#include "dubGen.h"
#include <string>

class blurtDubGens: public blurtReps, public dubGen
{
  public:
	blurtDubGens(int, int, int, string);
	void reset();
	int query();
};
#endif
