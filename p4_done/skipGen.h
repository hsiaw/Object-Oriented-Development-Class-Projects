/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the header definition of skipGen
 * -several members are virtual or protected for future inheritance
 * -virtual destructor defined here
 */

#ifndef SKIPGEN_H
#define SKIPGEN_H

#include "gen.h"

class skipGen: public gen
{
  public:
	skipGen(int, int, int);
	virtual ~skipGen(){};
	void setK(int);
	void reset();
	int query();
	virtual string whoami();
  protected:
	int k;
	int numResets;
	int skip;
	int getSkip();	
};
#endif
