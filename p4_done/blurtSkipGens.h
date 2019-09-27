/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the header definition of blurtSkipGens
 * -inherits multiply from blurtReps and skipGen
 */

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
	string whoami();
};
#endif


