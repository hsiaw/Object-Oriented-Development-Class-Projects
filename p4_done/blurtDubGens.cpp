/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the implementation of the blurtDubGens class.
 * -A blurtDubGens object combines the functionality of the blurtReps class
 *  	and dubGen class
 * -Class invariants: encapsulates both an arithmetic sequence with double functionality
 *  	and a string available for output
 * -Interface invariants: subordinates blurtReps query() function which only returns numPings
 *  	in favor of supporting dubGen query() function which gets output from the arithmetic sequence
 */

using namespace std;

#include "blurtDubGens.h"
#include <string>

const int DEFAULT_P = 3;
const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;

//Default constructor that uses both parent constructors for initialization
blurtDubGens::blurtDubGens(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newP = DEFAULT_P, string w = "null"): dubGen(fT,diff,newP), blurtReps(w)
{}

//Function that resets the active states for both dubGen and blurtReps
void blurtDubGens::reset()
{
	dubGen::reset();
	blurtReps::active = true;
	numPings = 0;
}

//Function that returns output only from dubGen
int blurtDubGens::query()
{
	return dubGen::query();
}

//ID function
string blurtDubGens::whoami()
{
	return "blurtDubGens";
}
