/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 3
 *
 * This file contains the header definition of blurtReps
 * -several members are virtual or protected for future inheritance
 * -virtual destructor defined here
 */

#ifndef BLURTREPS_H
#define BLURTREPS_H

#include <string>
using namespace std;
class blurtReps
{
  public:
	blurtReps();
	blurtReps(string);
	virtual ~blurtReps(){};
	virtual int query();
	string ping();
	virtual string whoami();
  protected:
	string word;
	int repCount;
	int outState;
	int numPings;
	bool active;
	enum state { PLAIN, TERSE, REPEAT };
	string truncWord(string, int);
	void changeState();
	int findOutState(string);
};
#endif
