/* Wendy Hsia
 * February 22, 2018
 * P4
 * version 1
 *
 * This file contains the header definition of gen
 * -several members are virtual or protected for future inheritance
 * -virtual destructor defined here
 */

#ifndef GEN_H
#define GEN_H

#include <string>

class gen
{
  public:
	gen(int, int);
	virtual ~gen(){};
	void setDiff(int);
	void setfT(int);
	virtual void reset();
	virtual int query();
	virtual string whoami();
  protected:
	int firstTerm;
	int difference;
	int index;
	int threshold;
	bool active;
};
#endif

