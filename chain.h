#pragma once
#include"Rational.h"

using namespace std;

class chain: public Rational{
public:
	vector<Rational> num;
	
	chain();
	chain(int a);
	chain(int a, int b);
	chain(int a, int b, int c);

	void set(const char* namefile);
	Rational to_rat() const;
	void to_chain(Rational r);

	chain& operator += (const chain& r);
	chain operator + (const chain& r) const;
	chain& operator -= (const chain& r);
	chain operator - (const chain& r) const;
	chain& operator *= (const chain& r);
	chain operator * (const chain& r) const;
	chain& operator /= (const chain& r);
	chain operator / (const chain& r) const;

	bool operator == (const chain& r);
	bool operator < (const chain& r);
	bool operator > (const chain& r);
	bool operator != (const chain& r);
};

