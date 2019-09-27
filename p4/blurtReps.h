
#ifndef BLURTREPS_H
#define BLURTREPS_H

#include <string>
using namespace std;
class blurtReps
{
  public:
	blurtReps();
	virtual ~blurtReps() {};
	blurtReps(string);
	virtual int query();
	string ping();
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
