/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the header definition of blurtDubGens
 * -inherits multiply from blurtReps and dubGen
 */

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
	string whoami();
};
#endif
