#ifndef MIXREPS_H
#define MIXREPS_H

#include <string>
#include "blurtReps.h"
using namespace std;
class mixReps
{
public:
	mixReps();
	~mixReps();
	mixReps(string, string);
	void toggleCount();
	void togglePref();
private:
	blurtReps* xBlurt;
	blurtReps* zBlurt;
	int mixCount;
	bool prefOdd;
};
#endif