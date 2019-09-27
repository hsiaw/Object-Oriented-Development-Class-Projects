#include "blurtReps.h"
#include "gen.h"
#include "dubGen.h"
#include "skipGen.h"
#include "blurtGens.h"
#include "blurtDubGens.h"
#include "blurtSkipGens.h"
//#include <iostream>
//#include <stdlib.h>
#include <time.h>
#include <iostream>

const int MAXRAND = 100;
const int NUMOBJS = 20;
const int NUMTESTS = 10;

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

int main()
{
	srand(time(NULL));

	string pingS;
	int queryN;

	gen* genArray[NUMOBJS];
	blurtReps* blurtArray[NUMOBJS];

	for(int i = 0; i < NUMOBJS; i++)
	{
		genArray[i] = getGenObj(rand() % MAXRAND);
		blurtArray[i] = getBlurtObj(rand() % MAXRAND);
		
	}

	for(int l = 0; l < NUMOBJS; l++)
	{
		for(int j = 0; j < NUMTESTS; j++)
		{
			queryN = genArray[l]->query();
			cout << queryN << " ";
		}

		//cout << " in between " << endl;

		for(int k = 0; k < NUMTESTS; k++)
		{
			pingS = blurtArray[l]->ping();	
			cout << pingS << " ";
		}
		cout << " loop " << l << endl;
	}

	for(int i = 0; i < NUMOBJS; i++)
	{
		delete genArray[i];
		delete blurtArray[i];
		cout << " dloop " << i << endl;
	}

	//delete genArray[1];
	//delete blurtArray[4];
	return 1;
}
