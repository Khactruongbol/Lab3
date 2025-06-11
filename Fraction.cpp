	#include "Fraction.h"
	bool Fraction::check() {
		if (denominator == 0)
			return false;
		else
		return true;
	}
	Fraction::Fraction(int num, int den) {
		numerator = num;
		denominator = den;
		if (!check()) {
			numerator = 0;
			denominator = 1;
		}
	}
	Fraction::Fraction(int random) {
		numerator = rand() % (random + 1);
		do {
			denominator = rand() % (random + 1);
		} while (denominator == 0);
	}
	int gcd(int a, int b) {
		if (b == 0) return abs(a);
		return gcd(b, a % b);
	}

	void Fraction::simplify() {
		int g = gcd(numerator, denominator);
		if (g != 0) {
			numerator /= g;
			denominator /= g;
		}
		if (denominator < 0) {
			numerator = -numerator;
			denominator = -denominator;
		}
	}
	ostream& operator<<(ostream& out, const Fraction &fra)
	{
		out << fra.numerator << "/" << fra.denominator;
			return out;
	}
	istream& operator>>(istream& in, Fraction& fra) {
		in >> fra.numerator >> fra.denominator;
		if (!fra.check()) {
			fra.numerator = 0;
			fra.denominator = 1;
		}
		return in;
	}
	Fraction& Fraction::operator++()
	{
		numerator += denominator;
		return *this;
	}
	const Fraction Fraction::operator++(int a)
	{
		Fraction backup(*this); 
		++(*this);
		return backup;
	}
	Fraction& Fraction::operator--()
	{
		numerator -= denominator;
		return *this;
	}
	const Fraction Fraction::operator--(int a)
	{
		Fraction backup(*this);
		--(*this);
		return backup;
	}
	Fraction operator+(const Fraction& a, const Fraction& b) {
		return Fraction(a.numerator * b.denominator + b.numerator * a.denominator,
			a.denominator * b.denominator);
	}
	Fraction operator-(const Fraction& a, const Fraction& b) {
		return Fraction(a.numerator * b.denominator - b.numerator * a.denominator,
			a.denominator * b.denominator);
	}
	Fraction operator*(const Fraction& a, const Fraction& b) {
		Fraction result(a.numerator * b.numerator, a.denominator * b.denominator);
		result.simplify();
		return result;
	}
	Fraction operator/(const Fraction& a, const Fraction& b) {
		return Fraction(a.numerator * b.denominator, a.denominator * b.numerator);
	}
	bool operator==(const Fraction& a, const Fraction& b) {
		Fraction fa = a, fb = b;
		fa.simplify();
		fb.simplify();
		return fa.numerator == fb.numerator && fa.denominator == fb.denominator;
	}
	bool operator!=(const Fraction& a, const Fraction& b) {
		return !(a == b);
	}
	bool operator<(const Fraction& a, const Fraction& b) {
		Fraction fa = a, fb = b;
		fa.simplify();
		fb.simplify();
		return fa.numerator * fb.denominator < fb.numerator * fa.denominator;
	}
	bool operator>(const Fraction& a, const Fraction& b) {
		Fraction fa = a, fb = b;
		fa.simplify();
		fb.simplify();
		return fa.numerator * fb.denominator > fb.numerator * fa.denominator;
	}
	Fraction Fraction::maxFraction(Fraction* arr, int n) {
		Fraction maxF = arr[0];
		for (int i = 1; i < n; ++i) {
			if (arr[i] > maxF) {
				maxF = arr[i];
			}
		}
		return maxF;
	}

	Fraction Fraction::minFraction(Fraction* arr, int n) {
		Fraction minF = arr[0];
		for (int i = 1; i < n; ++i) {
			if (arr[i] < minF) {
				minF = arr[i];
			}
		}
		return minF;
	}