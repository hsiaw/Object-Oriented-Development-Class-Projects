#ifndef SKIPGEN_H
#define SKIPGEN_H

#include "gen.h"

class skipGen: public gen
{
  public:
	skipGen(int, int, int);
	void setK(int);
	void reset();
	int query();
  protected:
	int k;
	int numResets;
	int skip;
	int getSkip();	
};
#endif
