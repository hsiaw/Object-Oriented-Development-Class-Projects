/* Wendy Hsia
 * February 7, 2018
 * P4 
 * version 1
 * 
 * This file contains the class definition of skipGen.
 *      skipGen inherits from gen class. It retains public
 *      functionality such as setting the arithmetic sequence
 *      and inherits the protected data fields difference,
 *      first term, index, threshold, and active.
 *      
 *      A skipGen object is like a gen object except it cannot
 *          be reset more than k times and it skips 0, 1, or k values
 *          in the sequence when queried for output.
 *      
 *      -certain members are protected or virtual for future inheritance
 *
 *      CLASS INVARIANTS
 *      The skipGen object will deactivate after a certain number of queries but 
 *          can be reset to reactivate unless it has already been reactivated
 *          k times.
 *      There is no limit to the arithmetic sequence skipGen will generate.
 *      
 *      INTERFACE INVARIANTS
 *      The difference and first term can be changed to get a new 
 *      arithmetic sequence, and the k value can be set.    
 *      skipGen overrides the reset and query functions to implement 
 *          extended functionality.
 */


using namespace std;

#include "skipGen.h"

const int DEFAULT_K = 3;
const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;

//Default constructor
skipGen::skipGen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newK = DEFAULT_K) : gen(fT,diff)
{
	k = newK;
	numResets = 0;
}

//Function to change the k value
void skipGen::setK(int newK)
{
	k = newK;
}

//Function to reset object. Overrides gen's function
void skipGen::reset()
{
	if(numResets != k)
	{
		gen::reset();
		k = DEFAULT_K;
		numResets++;
	}
	else
	{
		return;
	}
}

//Function to get output from object. Overrides gen's function
int skipGen::query() 
{
	int retVal;
	if(active)
	{
		int skipNum = getSkip();
		retVal = (firstTerm + (index - 1) * difference);
		index += skipNum;
		skip++;
	}
	else
	{
		retVal = -1;
	}
	if(skip == threshold)
	{
		active = false;
		skip = 0;
	}
	return retVal;
}

//Private utility function to determine skip value
int skipGen::getSkip()
{
	int retVal = (numResets % 3);
	if(retVal == 2)
	{
		retVal = k;
	}
	return retVal;
}

//ID function
string skipGen::whoami()
{
	return "skipGen";
}
