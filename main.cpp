#include "pch.h"
#include <iostream>
#include "rational.h"
using namespace std;

int main() {
	Rational a(1, 2);
	Rational b(-1, 6);
	cout << "a=" << a << " b=" << b << " a+b=" << a + b << endl;

	cout << "a=" << a << " b=" << b << " a-b=";
	a -= b;
	cout << a << endl;

	cout << "a(" << a << ") *= b(" << b << ")=";
	a *= b;
	cout << a << endl;

	Rational c = 3;
	cout << "b=" << b << " c=" << c << " b/c=";
	b /= c;
	cout << b << endl;

	Rational e(6, 7), f(5, 15);
	cout << "e=" << e << " f=" << f << " e+f=?" << endl;
	cout << "enter the answer m/n. enter two numbers with space in between example:10 10" << endl;
	Rational g;
	cin >> g;
	if (e + f != g)
		cout << "False. e+f=" << e + f << endl;
	else
		cout << "True." << endl;

	double r = 0.56;
	Rational x(12, 15);
	cout << "x=" << x << " r=" << r << " x+r=";
	x += r;
	cout << x << endl;

	cout << "x*r=";
	x *= r;
	cout << x << endl;

	cout << "x/r=";
	x /= r;
	cout << x << endl;

	cout << "x*r=";
	x *= r;
	cout << x << endl;

	Rational p(1, 1);
	double t = 50.8;
	cout << "p=" << p << " t=" << t << " p+t=?" << endl;
	cout << "enter the answer m/n. enter two numbers with space in between example:10 10" << endl;
	Rational y;
	cin >> y;
	if (p + t != y)
		cout << "False. p+t=" << p + t << endl;
	else
		cout << "True." << endl;

}