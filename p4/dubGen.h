#ifndef DUBGEN_H
#define DUBGEN_H

#include "gen.h"

class dubGen: public gen
{
  public:
	dubGen(int, int, int);
	void setP(int);
	void reset();
	int query();
  protected:
	int p;
};
#endif
