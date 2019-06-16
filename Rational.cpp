#include<iostream>
#include<math.h>
#include "Rational.h"

using namespace std;

Rational::Rational()
{
	numer = 0;
	denom = 1;
}

Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}

Rational::Rational(int n, int d)
{
	numer = n;
	denom = d;
}

void Rational::simplify()
{
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom % i == 0)
		{
			numer /= i;
			denom /= i;
			i--;
		}
}

void Rational::sqrtr() {
	double x = 1, x1 = 1;
	int n = 1, npr = 0, d = 1, dpr = 0, k, l;
	k = numer;
	l = denom;
	while (npr != n) {
		npr = x;
		x = (x + (numer / x)) * 0.5;
		n = x;
	}
	while (dpr != d) {
		dpr = x1;
		x1 = (x1 + (denom / x1)) * 0.5;
		d = x1;
	}
	numer = n;
	denom = d;
	Rational dr(n, d), xdr(k, l), del(1, 2);
	for (int i = 0; i < 2; i++) {
		dr = (dr + (xdr / dr)) * del;
	}
	numer = dr.numer;
	denom = dr.denom;
}

Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer * r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}

Rational& Rational::operator *=(const Rational& r)
{
	numer = numer * r.numer;
	denom = denom * r.denom;
	simplify();
	return *this;
}

Rational Rational::operator *(const Rational& r) const
{
	Rational res(*this);

	return res *= r;
}

Rational Rational::operator *=(const int& l)
{

	numer = numer * l;
	simplify();
	return *this;

}

Rational Rational::operator /=(const int& l)
{

	denom = denom * l;
	simplify();
	return *this;

}

Rational Rational::operator /(const int& l) const
{

	Rational res(*this);

	return res /= l;

}

Rational Rational::operator *(const int& l) const
{

	Rational res(*this);

	return res *= l;

}

Rational& Rational::operator /=(const Rational& r)
{
	numer = numer * r.denom;
	denom = denom * r.numer;
	simplify();
	return *this;
}

Rational& Rational::operator /(const Rational& r)
{
	Rational res(*this);

	return res /= r;
}

Rational Rational::operator +(const Rational& r) const
{
	Rational res(*this);

	return res += r;
}

Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}

Rational& Rational::operator -= (const Rational& r)
{

	numer = (numer * r.denom - denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}

Rational Rational::operator -(const Rational& r) const
{
	Rational res(*this);

	return res -= r;
}


Rational& Rational::operator ++()
{
	numer += denom;
	return(*this);
}

Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}

bool Rational::operator ==(const Rational& r) const
{
	return (numer == r.numer) && (denom == r.denom);
}

bool Rational::operator <(const Rational& r) const
{
	return ((numer*r.denom) < (r.numer*denom));
}

bool Rational::operator >(const Rational& r) const
{
	return ((numer*r.denom) > (r.numer*denom));
}

bool Rational::operator !=(const Rational& r) const
{
	return !(*this == r);
}

Rational::operator int() const
{
	return numer / denom;
}

Rational::operator double() const
{
	return ((double)numer / denom);
}
