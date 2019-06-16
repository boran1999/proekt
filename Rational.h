#pragma once
#ifndef _RATIONAL_H
#define _RATIONAL_H
#include <iostream>

class Rational
{
public:
	int numer, denom;
	Rational();
	Rational(int number);
	Rational(int n, int d);

	Rational& operator +=(const Rational& r);
	Rational& operator *=(const Rational& r);
	Rational operator *(const Rational& r) const;
	Rational operator *=(const int & l);
	Rational operator /=(const int & l);
	Rational operator *(const int & l) const;
	Rational operator /(const int & l) const;
	Rational& operator /=(const Rational& r);
	Rational& operator /(const Rational& r);
	Rational operator +(const Rational& r) const;
	Rational operator -() const;
	Rational& operator -=(const Rational& r);
	Rational operator -(const Rational& r) const;

	void simplify();
	void sqrtr();

	

	Rational& operator ++();
	Rational operator ++(int);

	bool operator ==(const Rational& r) const;
	bool operator <(const Rational& r) const;
	bool operator >(const Rational& r) const;
	bool operator !=(const Rational& r) const;

	operator int() const;
	operator double() const;
};
#endif -
