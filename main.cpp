#include<vector>
#include<iostream>
#include<fstream>
#include "chain.h"

using namespace std;

ostream& operator<<(ostream& out, const Rational r) {
	if (r.denom == 1) {
		out << r.numer;
	}
	else {
		out << r.numer << "/(" << r.denom;
	}
	return out;
}

ostream& operator <<(ostream& out, const chain ch) {
	cout << ch.num[0];
	for (int j = 1; j < ch.num.size(); j++) {
		cout << " + " << ch.num[j];
	}
	for (int j = 1; j < ch.num.size(); j++) {
		cout << ")";
	}
	return out;
}

int main() {
	setlocale(LC_ALL, "Russian");
	chain c, c1, z(1,2,3), l(3, 2, 3), s(2,2,2), m(1,3,4), rt;
	Rational a(155, 42);
	cout << "Перевод обычной дроби к цепной" << endl;
	rt.to_chain(a);
	cout << rt << endl;
	c.set("in.txt");
	c1.set("in1.txt");
	cout << "перевод цепной дроби к обычной" << endl;
	cout << m.to_rat() << endl;
	cout << "умножение цепных дробей" << endl;
	cout << z << " * " << c1 << " = ";
	z *= c1;
	cout << z << endl;
	cout << "деление цепных дробей" << endl;
	cout << c1 << " / " << c << " = ";
	z = c1 / c;
	cout << z << endl;
	cout << "оператор сравнения цепных дробей" << endl;
	if (z > c) {
		cout << "yes" << endl;
	}
	else
		cout << "no" << endl;
	system("pause");
	return 0;
}
