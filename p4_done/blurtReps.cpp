/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 3
 *
 * This file contains the implementation of the blurtReps class.
 * -A blurtReps object encapsulates a string and will have different output
 *  	based on an internal state
 * -Class invariants: object will age out after a certain number of pings,
 *  	object is essentially null after aging out and will only return -1,
 *  	output is PLAIN, TERSE, or REPEAT, based on the inputted word length,
 *  	output state changes after each ping, string is truncated if inputted
 *  	word is greater than MAXSTRINGLEN
 * -Certain members are virtual or protected in anticipation of future inheritance
 * -Interface invariants: object can only be pinged MAXPINGS times and then becomes
 *  	irretrievably inactive, object can be queried to return number of times it's
 *  	been pinged
 */

using namespace std;

#include "blurtReps.h"
#include <string>

const int MAXPINGS = 8;
const int MAXSTRINGLEN = 4;

//No argument default constructor
blurtReps::blurtReps()
{
	word = "null";
	repCount = (MAXSTRINGLEN - word.size() + 1);
	outState = findOutState(word);
	numPings = 0;
	active = true;
}

//String argument constructor
blurtReps::blurtReps(string w)
{
	if(w.size() < 5)
	{
		word = w;
	}
	else
	{
		word = truncWord(w, MAXSTRINGLEN);
	}
	repCount = (MAXSTRINGLEN - word.size() + 1);
	outState = findOutState(word);
	numPings = 0;
	active = true;
}

//Function to return number of pings
int blurtReps::query()
{
	return numPings;
}

//Function to return output
//PRECONDITION: no output will happen if object is inactive
//POSTCONDITION: object may become inactive
string blurtReps::ping()
{
	if(active)
	{
		string retWord;
		if (outState == PLAIN)
                {
                    	retWord = word;
                }
                else if (outState == REPEAT)
                {
			retWord = word.substr(0,0);
                    	for (int i = 0; i < repCount; i++)
                    	{
                      		retWord += word;
                    	}
                    	repCount++;
                }
                else
                {
                    	for (int i = 0; i < (word.size() + 1) / 2; i++)
                    	{
                        	retWord = truncWord(word, (word.size() + 1) / 2);
                    	}
                }
                numPings++;
                changeState();
                if (numPings == MAXPINGS)
                {
                    	active = false;
			
                }
		return retWord;	
	}
	else
	{
		return word.substr(0,0);
	}
}

//ID function
string blurtReps::whoami()
{
	return "blurtReps";
}

//Private utility function to truncate a string to a certain length
string blurtReps::truncWord(string w, int len)
{
	string newWord = w.substr(0, len);
	return newWord;
}

//Private utility function to cycle through output states
void blurtReps::changeState()
{	
	outState = ((outState + 1) % 3);
}

//Private utility function to determine initial output state
//	based on string length
int blurtReps::findOutState(string w)
{
	if(w.size() < MAXSTRINGLEN / 2)
	{
		return REPEAT;
	}
	else if(w.size() == MAXSTRINGLEN / 2)
	{
		return PLAIN;
	}
	else
	{
		return TERSE;
	}
}
