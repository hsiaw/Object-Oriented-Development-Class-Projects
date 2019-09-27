using namespace std;

#include "mixReps.h"
#include <string>

mixReps::mixReps()
{
	xBlurt = new blurtReps();
	zBlurt = new blurtReps();
	mixCount = 2;
	prefOdd = true;
}

mixReps::mixReps(string x, string z)
{
	xBlurt = new blurtReps(x);
	zBlurt = new blurtReps(z);
	mixCount = 2;
	prefOdd = true;
}

void mixReps::toggleCount()
{
	mixCount = ((mixCount % 2) + 1);
}

void mixReps::togglePref()
{
	prefOdd = !prefOdd;
}