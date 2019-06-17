#pragma once
#include<vector>

using namespace std;

class Longmath {
public:
	vector<long long> fnum;
	long long N = 10;
	Longmath();
	Longmath(const char *filename);

	Longmath& operator += (Longmath& r);
	Longmath& operator + (Longmath& r) const;
	Longmath& operator -= (Longmath& r);
	Longmath& operator - (Longmath& r) const;
	Longmath& operator *= (Longmath& r);
	Longmath& operator * (Longmath& r) const;
	Longmath& operator /= (const int& r);
	Longmath& operator / (const int& r) const;

	Longmath powl(int k);
};
