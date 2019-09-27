#ifndef GEN_H
#define GEN_H
class gen
{
  public:
	gen(int, int);
	virtual ~gen() {};
	void setDiff(int);
	void setfT(int);
	virtual void reset();
	virtual int query();
  protected:
	int firstTerm;
	int difference;
	int index;
	int threshold;
	bool active;
};
#endif

