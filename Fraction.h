#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction() : numerator(0), denominator(1){}
	Fraction(int num, int den);
	Fraction(int random);
	friend ostream& operator<< (ostream& out, const Fraction &fra);
	friend istream& operator>>(istream& in, Fraction& fra);
	bool check();
	Fraction& operator++();
	const Fraction operator++(int a);
	Fraction& operator--();
	const Fraction operator--(int a);
	friend Fraction operator+(const Fraction& a, const Fraction& b);
	friend Fraction operator-(const Fraction& a, const Fraction& b);
	friend Fraction operator*(const Fraction& a, const Fraction& b);
	friend Fraction operator/(const Fraction& a, const Fraction& b);
	void simplify();
	friend bool operator==(const Fraction& a, const Fraction& b);
	friend bool operator!=(const Fraction& a, const Fraction& b);
	friend bool operator<(const Fraction& a, const Fraction& b);
	friend bool operator>(const Fraction& a, const Fraction& b);
	static Fraction maxFraction(Fraction* arr, int n);
	static Fraction minFraction(Fraction* arr, int n);
};

