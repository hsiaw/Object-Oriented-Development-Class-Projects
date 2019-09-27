/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the header definition of blurtGens
 * -inherits multiply from gen and blurtReps
 */

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
	string whoami();
};
#endif
