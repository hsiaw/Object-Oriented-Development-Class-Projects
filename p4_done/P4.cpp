/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the driver for P4
 * -It is intended for testing the classes created in P3 as well
 *  	as the new multiple inherited classes created in P4.
 * -It uses heterogeneous collections that are initialized via
 *  	isolated getObj functions to show that the objects multiply
 *  	inheriting can stand in for either of its parents
 * -Random generators are used to generate random ints and random strings
 */

#include "blurtReps.h"
#include "gen.h"
#include "dubGen.h"
#include "skipGen.h"
#include "blurtGens.h"
#include "blurtDubGens.h"
#include "blurtSkipGens.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int MAXRAND = 100;
const int NUMOBJS = 20;
const int NUMTESTS = 10;

//Function to generate a random string of random length
static string randStringGen()
{	
	char randChar = (char)((rand() % 26) + 97);
	int size = (rand() % 5) + 1;
	char randString[6];
	for (int i = 0; i < size; i++)
	{
		randString[i] = randChar;
	}
	randString[size] = '\0';
	return randString;
}

//Function to isolate initialization of gen objects, returns
//	gen pointer that can hold a gen object or any of its
//	descendants
static gen* getGenObj(int x)
{
	gen* retObj;	
	int y = (x%5);
	switch(y)
	{
		case (0): 
		{
			retObj = new dubGen(x, x+1, x+2); 
			break;
		}
		case (1): 
		{
			retObj = new skipGen(x, x+1, x+2);
			break;
		}
		case (2): 
		{
			retObj = new blurtGens(x, x+1, randStringGen());
			break;
		}
		case (3): 
		{
			retObj = new blurtDubGens(x, x+1, x+2, randStringGen()); 
			break;
		}
		case (4): 
		{	
			retObj = new blurtSkipGens(x, x+1, x+2, randStringGen());
			break;
		}
		default: 
		{
			retObj = new gen(x, x+1);
			break;
		}
	}
	return retObj;
}

//Function to isolate initialization of blurtReps objects, returns
//	blurtReps pointer that can hold a blurtReps object or any
//	of its descendants
static blurtReps* getBlurtObj(int x)
{
	blurtReps* retObj;
	int y = (x%3);
	switch(y)
	{
		case (0): 
		{
			retObj = new blurtDubGens(x, x+1, x+2, randStringGen());
			break;
		}
		case (1): 
		{
			retObj = new blurtGens(x, x+1, randStringGen());
			break;
		}
		case (2):
		{
			retObj = new blurtSkipGens(x, x+1, x+2, randStringGen());
			break;
		}
		default: 
		{
			retObj = new blurtReps(randStringGen());	
			break;
		}
	}
	return retObj;
}

//Driver
int main()
{
	srand(time(NULL));

	string pingS;
	int queryN;

	//HETEROGENEOUS ARRAYS
	gen* genArray[NUMOBJS];
	blurtReps* blurtArray[NUMOBJS];

	for(int i = 0; i < NUMOBJS; i++)
	{
		genArray[i] = getGenObj(rand() % MAXRAND);
		blurtArray[i] = getBlurtObj(rand() % MAXRAND);		
	}

	for(int l = 0; l < NUMOBJS; l++)
	{
		cout << "Querying " << genArray[l]->whoami() << endl;
		for(int j = 0; j < NUMTESTS; j++)
		{
			queryN = genArray[l]->query();
			cout << queryN << " ";
		}

		cout << endl << endl;
		
		cout << "Pinging " << blurtArray[l]->whoami() << endl;
		for(int k = 0; k < NUMTESTS; k++)
		{
			pingS = blurtArray[l]->ping();	
			cout << pingS << " ";
		}
		
		cout << endl << endl;
	}

	for(int i = 0; i < NUMOBJS; i++)
	{
		delete genArray[i];
		delete blurtArray[i];
	}

	return 1;
}
