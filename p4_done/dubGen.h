/* Wendy Hsia
 * February 22, 2018
 * P4
 * Version 1
 *
 * This file contains the header definition of dubGen
 * -several members are virtual or protected for future inheritance
 * -virtual destructor defined here
 */

#ifndef DUBGEN_H
#define DUBGEN_H

#include "gen.h"

class dubGen: public gen
{
  public:
	dubGen(int, int, int);
	virtual ~dubGen(){};
	void setP(int);
	void reset();
	int query();
	virtual string whoami();
  protected:
	int p;
};
#endif
