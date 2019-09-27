using namespace std;

#include "cohortReps.h"
#include <string>

const int DEFAULT_CAPACITY = 5;

cohortReps::cohortReps()
{
	capacity = DEFAULT_CAPACITY;
	array = new blurtReps*[capacity];
	count = 0;
}

void cohortReps::push(string word)
{
	if (count == capacity)
	{
		resize();
	}
	blurtReps* newBlurt = new blurtReps(word);
	array[count] = newBlurt;
	count++;
}

void cohortReps::pop()
{
	count--;
	delete array[count];
}

void cohortReps::clear()
{
	for (int i = (count - 1); i >= 0; i--)
	{
		delete array[i];
	}
	count = 0;
}

bool cohortReps::isEmpty()
{
	return (count == 0);
}

void cohortReps::resize()
{
	blurtReps** local = new blurtReps*[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		local[i] = array[i];
		delete array[i];
	}
	capacity *= 2;
	array = local;
}