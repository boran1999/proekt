#include<vector>
#include<iostream>
#include<fstream>
#include "chain.h"

using namespace std;

	chain::chain() {}

	chain::chain(int a) {
		Rational r(a);
		num.push_back(r);
	}

	chain::chain(int a, int b) {
		Rational r(a);
		num.push_back(r);
		Rational r1(1, b);
		num.push_back(r1);
	}

	chain::chain(int a, int b, int c) {
		Rational r(a);
		num.push_back(r);
		Rational r1(1, b);
		num.push_back(r1);
		Rational r2(1, c);
		num.push_back(r2);
	}

	void chain::set(const char* namefile) {
		ifstream in(namefile);
		Rational r1;
		int number;
		in >> number;
		r1.numer = number;
		r1.denom = 1;
		num.push_back(r1);
		while (!in.eof()) {
			in >> number;
			r1.numer = 1;
			r1.denom = number;
			num.push_back(r1);
		}
	}
	void chain::setnum(const char* namefile) {
		ifstream in(namefile);
		Rational r;
		while(!in.eof()){
			char sym = in.get();
			if (sym > '0' && sym < '9') {
				int numer = sym - '0';
				r.numer = numer;
				r.denom = 1;
				num.push_back(r);
			}
		}
	}

	Rational chain::to_rat() const{
		chain temp;
		temp.num = (*this).num;
		Rational r;
		r.numer = temp.num[temp.num.size() - 2].denom;
		r.denom = 1;
		Rational nr = temp.num[temp.num.size() - 1] + r;
		temp.num.pop_back();
		temp.num.pop_back();
		temp.num.push_back(nr);
		while (temp.num.size() > 1) {
			Rational one(1);
			temp.num[temp.num.size() - 1] = one / temp.num[temp.num.size() - 1];
			Rational r;
			if (temp.num[temp.num.size() - 2].denom == 1) {
				r.numer = temp.num[temp.num.size() - 2].numer;
				r.denom = 1;
			}
			else {
				r.numer = temp.num[temp.num.size() - 2].denom;
				r.denom = 1;
			}
			Rational nr = temp.num[temp.num.size() - 1] + r;
			temp.num.pop_back();
			temp.num.pop_back();
			temp.num.push_back(nr);
		}
		return temp.num[0];
	}

	void chain::to_chain(Rational r) {
		num.clear();
		if (r.denom > r.numer) {
			num.push_back(Rational(0));
		}
		else if (r.denom == r.numer) {
			cout << "Невозможно получить цепную дробь";
			exit;
		}
		else {
			int del = r.numer / r.denom;
			num.push_back(Rational(del));
			r.numer = r.numer - del * r.denom;
		}
		while (r.numer != 1) {
			Rational nr;
			Rational one(1);
			r = one / r;
			int del = r.numer / r.denom;
			num.push_back(Rational(1, del));
			r.numer = r.numer - del * r.denom;
		}
		num.push_back(r);
	}

	void chain::to_chain(Rational r, const char filename) {

	}

	chain& chain::operator +=(const chain& r)
	{
		Rational t1 = to_rat();
		Rational t2 = r.to_rat();
		t1.numer = (t1.numer * t2.denom + t1.denom * t2.numer);
		t1.denom *= t2.denom;
		t1.simplify();
		(*this).to_chain(t1);
		return (*this);
	}

	chain chain::operator + (const chain& r) const{
		chain temp(*this);
		return temp += r;
	}

	chain& chain::operator -=(const chain& r)
	{
		Rational t1 = to_rat();
		Rational t2 = r.to_rat();
		t1.numer = (t1.numer * t2.denom - t1.denom * t2.numer);
		t1.denom *= t2.denom;
		t1.simplify();
		(*this).to_chain(t1);
		return (*this);
	}

	chain chain::operator - (const chain& r) const{
		chain temp(*this);
		return temp -= r;
	}

	chain& chain::operator *=(const chain& r)
	{
		Rational t1 = to_rat();
		Rational t2 = r.to_rat();
		t1.numer = (t1.numer * t2.numer);
		t1.denom *= t2.denom;
		t1.simplify();
		(*this).to_chain(t1);
		return (*this);
	}

	chain chain::operator * (const chain& r) const{
		chain temp(*this);
		return temp *= r;
	}

	chain& chain::operator /=(const chain& r)
	{
		Rational t1 = to_rat();
		Rational t2 = r.to_rat();
		t1.numer = (t1.numer * t2.denom);
		t1.denom *= t2.numer;
		t1.simplify();
		(*this).to_chain(t1);
		return (*this);
	}

	chain chain::operator / (const chain& r) const{
		chain temp(*this);
		return temp /= r;
	}

	bool chain::operator == (const chain& r){
		Rational t1 = to_rat();
		Rational t2 = r.to_rat();
		return (t1.numer == t2.numer) && (t1.denom == t2.denom);
	}

	bool chain::operator > (const chain& r) {
		Rational t1 = to_rat();
		Rational t2 = r.to_rat();
		return (t1.numer * t2.denom) > (t1.denom * t2.numer);
	}

	bool chain::operator < (const chain& r) {
		Rational t1 = to_rat();
		Rational t2 = r.to_rat();
		return (t1.numer * t2.denom) < (t1.denom * t2.numer);
	}

	bool chain::operator != (const chain& r) {
		return !(*this == r);
	}
