/* Wendy Hsia
 * February 7, 2018
 * P4 
 * version 1
 * 
 * This file contains the class definition of dubGen.
 *      dubGen inherits from gen class. It retains public
 *      functionality such as setting the arithmetic sequence
 *      and inherits the protected data fields difference,
 *      first term, index, threshold, and active.
 *      
 *      A dubGen object is like a gen object except it can be reset
 *          to start at the beginning of the sequence and it doubles
 *          every p'th value.
 *      
 *      -Certain members are protected or virtual for future inheritance
 *
 *      CLASS INVARIANTS
 *      The dubGen object will deactivate after a certain number of queries but 
 *          can be reset to reactivate and it will start at the beginning of
 *          the sequence again.
 *      There is no limit to the arithmetic sequence dubGen will generate.
 *      
 *      INTERFACE INVARIANTS
 *      The difference and first term can be changed to get a new 
 *      arithmetic sequence, and the p value can be set.    
 *      dubGen overrides the reset and query functions to implement 
 *          extended functionality.
 */


using namespace std;

#include "dubGen.h"

const int DEFAULT_P = 3;
const int DEFAULT_FIRST = 4;
const int DEFAULT_DIFFERENCE = 2;

//Default constructor
dubGen::dubGen(int fT = DEFAULT_FIRST, int diff = DEFAULT_DIFFERENCE, int newP = DEFAULT_P) : gen(fT,diff)
{
	p = newP;
}

//Function to change the p value
void dubGen::setP(int newP)
{
	p = newP;
}

//Function to reset object. Overrides gen's function
void dubGen::reset()
{
	gen::reset();
	p = DEFAULT_P;
	index = 1;
}

//Function to get output from object. Overrides gen's function
int dubGen::query()
{
	if(index == threshold)
	{
		active = false;
	}
	if(active)
	{
		int retVal;
		if((index % p) == 0)
		{
			retVal = (2* (firstTerm + (index - 1) * difference));
		}
		else
		{
			retVal = (firstTerm + (index -1) * difference);
		}
		index++;
		return retVal;
	}
	else
	{
		return -1;
	}
}

//ID function
string dubGen::whoami()
{
	return "dubGen";
}
