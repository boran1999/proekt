#include"Longmath.h"
#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;


Longmath::Longmath(){}

Longmath::Longmath(const char *filename) {
	ifstream in(filename);
	while (!in.eof()) {
		char sym = in.get();
		if (sym >= '0' && sym <= '9') {
			int numer = sym - '0';
			fnum.push_back(numer);
		}
	}
}

Longmath& Longmath::operator+= (Longmath& r) {
	while (fnum.size() != r.fnum.size()) {
		if (fnum.size() > r.fnum.size()) 
			r.fnum.emplace(r.fnum.begin(), 0);
		else 
			fnum.emplace(fnum.begin(), 0);
	}
	int carry = 0;
	for (int i = fnum.size()-1; i >=0 ; i--) {
		fnum[i] += r.fnum[i] + carry;
		if (fnum[i] >= N) {
			carry = 1;
			fnum[i] -= N;
		}
		else
			carry = 0;
	}
	while (fnum[0] == 0) {
		auto iter = fnum.cbegin();
		fnum.erase(iter);
	}
	return *this;
}

Longmath& Longmath::operator + (Longmath& r) const {
	Longmath temp(*this);
	return temp += r;
}

Longmath& Longmath::operator-= (Longmath& r) {
	while (fnum.size() != r.fnum.size()) {
		if (fnum.size() > r.fnum.size())
			r.fnum.emplace(r.fnum.begin(), 0);
		else
			fnum.emplace(fnum.begin(), 0);
	}
	int carry = 0;
	for (int i = fnum.size() - 1; i >= 0; i--) {
		fnum[i] -= (carry +  r.fnum[i]);
		if (fnum[i] < 0) {
			carry = 1;
			fnum[i] += N;
		}
		else
			carry = 0;
	}
	while (fnum[0] == 0) {
		auto iter = fnum.cbegin();
		fnum.erase(iter);
	}
	return *this;
}

Longmath& Longmath::operator - (Longmath& r) const {
	Longmath temp(*this);
	return temp -= r;
}

Longmath& Longmath::operator*= (Longmath& r) {

	long long k = fnum.size() + r.fnum.size();
	Longmath res;
	res = *this;
	while (res.fnum.size() != r.fnum.size()) {
		if (res.fnum.size() > r.fnum.size())
			r.fnum.emplace(r.fnum.begin(), 0);
		else
			res.fnum.emplace(res.fnum.begin(), 0);
	}
	(*this).fnum.clear();
	(*this).fnum.resize(k);
	for (int i = res.fnum.size() - 1; i >= 0; i--) {
		int carry = 0;
		for (int j = r.fnum.size() - 1; j >= 0; j--) {
			fnum[i+j] = res.fnum[i] * r.fnum[j] + carry;
			carry = fnum[i+j] / N;
			fnum[i+j] %= N;
		}
	}
	while (fnum[0] == 0) {
		auto iter = fnum.cbegin();
		fnum.erase(iter);
	}
	return *this;
}

Longmath& Longmath::operator * (Longmath& r) const {
	Longmath temp(*this);
	return temp *= r;
}

Longmath& Longmath::operator/= (const int& r) {
	int carry = 0;
	int p, q;
	for (int i = 0; i < fnum.size()-1; i++) {
		p = fnum[i] + carry * N;
		q = p / r;
		carry = p - q * r;
		fnum[i] = q;
	}
	while (fnum[0] == 0) {
		auto iter = fnum.cbegin();
		fnum.erase(iter);
	}
	return *this;
}

Longmath& Longmath::operator / (const int& r) const {
	Longmath temp(*this);
	return temp /= r;
}

Longmath Longmath::powl(int k){
	Longmath res;
	res = (*this);
	for (int i = 1; i < k; i++) {
		(*this)*=res;
	}
	return (*this);
}
