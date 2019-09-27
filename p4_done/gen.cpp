/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the class definition of gen.
 * -A gen object has the definition of an arithmetic
 *      sequence and upon query outputs the next int in
 *      the sequence. It defines the public interface
 *      of a gen object that can reset and query, also change
 *      the sequence definition.
 *      
 *      CLASS INVARIANTS
 *      The gen object will deactivate after a certain number of
 *      queries but can be reactivated with reset.
 *      There is no limit to the arithmetic sequence gen will generate.
 *      
 *      INTERFACE INVARIANTS
 *      The difference and first term can be changed to get a new 
 *      arithmetic sequence, but there is no way to restart a gen obj
 *      to retrieve the beginning of the sequence.
 *      
 *      The functions query and reset are virtual for extension in
 *          descendant classes.
 */

using namespace std;

#include "gen.h"

const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;
const int DEFAULT_THRESHOLD = 5;

//Default constructor
gen::gen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE)
{
	firstTerm = fT;
	difference = diff;
	index = 1;
	active = true;
	threshold = DEFAULT_THRESHOLD;
}

//Function to change the difference of the sequence
void gen::setDiff(int nDiff)
{
	difference = nDiff;
}

//Function to change the first term of the sequence
void gen::setfT(int fT)
{
	firstTerm = fT;
}

//Function to reset object
void gen::reset()
{
	active = true;
}

//Function to retrieve input from sequence
int gen::query()
{
	if(index == threshold)
	{
		threshold += threshold;
		active = false;
	}
	if(active)
	{
		int nextInt = (firstTerm + (index - 1) * difference);
		index++;
		return nextInt;
	}
	else
	{
		return -1;
	}
}

//ID function
string gen::whoami()
{
	return "gen";
}
