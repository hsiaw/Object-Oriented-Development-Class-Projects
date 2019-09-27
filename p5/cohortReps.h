#ifndef COHORTREPS_H
#define COHORTREPS_H

#include <string>
#include "blurtReps.h"
using namespace std;
class cohortReps
{
public:
	cohortReps();
	~cohortReps();
	void push(string);
	void pop();
	void clear();
	bool isEmpty();
	cohortReps operator+(const cohortReps&);
	cohortReps operator-(const cohortReps&);
private:
	blurtReps** array;
	int count;
	int capacity;
	void resize();
};
#endif
