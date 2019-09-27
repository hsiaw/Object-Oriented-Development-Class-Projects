using namespace std;

#include "blurtReps.h"
#include <string>

const int MAXPINGS = 8;
const int MAXSTRINGLEN = 4;

blurtReps::blurtReps()
{
	word = "null";
	repCount = (MAXSTRINGLEN - word.size() + 1);
	outState = findOutState(word);
	numPings = 0;
	active = true;
}

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

int blurtReps::query()
{
	return numPings;
}

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

string blurtReps::truncWord(string w, int len)
{
	string newWord = w.substr(0, len);
	return newWord;
}

void blurtReps::changeState()
{	
	outState = ((outState + 1) % 3);
}

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
