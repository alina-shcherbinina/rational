#include "pch.h"
#include <iostream>
#include "rational.h"
using namespace std;

Rational::Rational(int n, int d) {
	numer = n;
	denom = d;
}

Rational::Rational(int number)
{
	numer = number;
	denom = 1;
}

Rational::Rational()
{
	numer = 0;
	denom = 1;
}

Rational& Rational::operator +=(const Rational& r)
{
	numer = (numer*r.denom + denom * r.numer);
	denom *= r.denom;
	simplify();
	return *this;
}

void Rational::simplify()
{
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
	for (int i = 2; i <= abs(denom) && i <= abs(numer); i++)
		if (numer % i == 0 && denom%i == 0)
		{
			numer /= i;
			denom /= i;
			i--;
		}
}
Rational Rational::operator +(const Rational &r) const
{
	Rational res(*this);
	return res += r;
}
Rational Rational::operator -() const
{
	Rational r(-numer, denom);
	return r;
}
Rational& Rational::operator -=(const Rational& r)
{
	return (*this += (-r));
}
Rational& Rational::operator *=(const Rational& r)
{
	numer = (numer * r.numer);
	denom *= r.denom;
	simplify(); // упрощение
	return *this;
}
Rational& Rational::operator /=(const Rational& r)
{
	numer = (numer * r.denom);
	denom *= r.numer;
	simplify();
	return *this;
}
Rational& Rational::operator ++()
{
	numer += denom;
	return *this;
}
Rational Rational::operator ++(int)
{
	Rational r(*this);
	numer += denom;
	return r;
}
bool Rational::operator==(const Rational& r) const
{
	return (numer == r.numer) && (denom == r.denom);
}
bool Rational::operator!=(const Rational& r) const
{
	return !(*this == r);
}
Rational::operator int() const
{
	return numer / denom;
}
Rational::operator double() const
{
	return ((double)numer) / denom;
}
Rational& Rational::operator +=(const double& r) {
	double a = r;
	Rational rtr(0, 1);
	int k = 0;
	while (fabs(fmod(a, 1.0)) >= 0.000001) {
		rtr.numer = (int)(a * 10);
		rtr.denom *= 10;
		a *= 10;
	}
	*this += rtr;
	return *this;
}
Rational& Rational::operator *=(const double& r) {
	double a = r;
	Rational rtr(0, 1);
	while (fmod(a, 1) != 0) {
		rtr.numer = (a * 10) / 1;
		rtr.denom *= 10;
		a *= 10;
	}
	*this *= rtr;
	return *this;
}
bool Rational::operator ==(const double& r) const {
	double a = r;
	Rational rtr(0, 1);
	while (fmod(a, 1) != 0) {
		rtr.numer = (a * 10) / 1;
		rtr.denom *= 10;
		a *= 10;
	}
	return (numer == rtr.numer) && (denom == rtr.denom);
}
Rational Rational::operator +(const double& r) const {
	Rational res(*this);
	return res += r;
}
istream& operator >>(istream& in, Rational& r)
{
	in >> r.numer >> r.denom;
	return in;
}
ostream& operator <<(ostream& out, const Rational& r)
{
	out << r.numer << "/" << r.denom;
	return out;
}

