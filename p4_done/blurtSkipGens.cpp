/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the implementation of the blurtSkipGens class.
 * -A blurtSkipGens object combines the functionality of the blurtReps class
 *  	and skipGen class
 * -Class invariants: encapsulates both an arithmetic sequence with skip functionality
 *  	and a string available for output
 * -Interface invariants: subordinates blurtReps query() function which only returns
 *  	numPings in favor of supporting skipGen query() function which gets output from
 *  	the arithmetic sequence
 */
using namespace std;

#include "blurtSkipGens.h"
#include <string>

const int DEFAULT_K = 3;
const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;

//Default constructor that uses both parent constructors for initialization
blurtSkipGens::blurtSkipGens(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newK = DEFAULT_K, string w = "null"): skipGen(fT,diff,newK), blurtReps(w)
{}

//Function that resets the active states for both skipGen and blurtReps
void blurtSkipGens::reset()
{
	skipGen::reset();
	blurtReps::active = true;
	numPings = 0;
}

//Function that returns output from only skipGen
int blurtSkipGens::query()
{
	return skipGen::query();
}

//ID function
string blurtSkipGens::whoami()
{
	return "blurtSkipGens";
}
