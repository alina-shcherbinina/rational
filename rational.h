#include <iostream>
using namespace std;

class Rational
{
	void simplify();
public:
	int numer;
	int denom;
	Rational(int n, int d);
	Rational(int number);
	Rational();

	Rational& operator +=(const Rational& r);
	Rational operator +(const Rational& r) const;

	Rational operator -() const;
	Rational& operator -=(const Rational& r);

	Rational& operator ++();
	Rational operator ++(int);

	Rational& operator *=(const Rational& r);
	Rational& operator /=(const Rational& r);

	Rational& operator +=(const double& r);
	Rational& operator *=(const double& r);
	Rational operator +(const double& r) const;

	bool operator ==(const double& r) const;
	bool operator ==(const Rational& r) const;
	bool operator !=(const Rational& r) const;

	

	operator int() const;
	operator double() const;

	friend istream& operator >>(istream& in, Rational& r);
	friend ostream& operator <<(ostream& out, const Rational& r);
};