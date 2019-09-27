/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the implementation of the blurtGens class.
 * -A blurtGens object combines the functionality of the blurtReps class
 *  	and gen class.
 * -Class invariants: encapsulates both an arithmetic sequence and a string
 *  	available for output
 * -Interface invariants: subordinates blurtReps query() function which only
 *  	returns numPings in favor of supporting gen query() function which 
 *  	gets output from the arithmetic sequence
 */

using namespace std;

#include "blurtGens.h"
#include <string>

const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;
const int DEFAULT_THRESHOLD = 5;

//Default constructor that uses both parent constructors for initialization
blurtGens::blurtGens(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, string w = "null") : gen(fT,diff), blurtReps(w)
{}

//Function that resets the active states for both gen and blurtReps and sets numPings to 0
void blurtGens::reset()
{
	gen::reset();
	blurtReps::active = true;
	numPings = 0;
}

//Function that returns output from only gen
int blurtGens::query()
{
	return gen::query();
}

//ID function
string blurtGens::whoami()
{
	return "blurtGens";
}
