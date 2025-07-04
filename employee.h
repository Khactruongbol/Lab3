#pragma once
#include<iostream>
#include<string>
using namespace std;
class Employee
{
private:
	string socialSecurityNumber;
protected:
	string firstName;
	string lastName;
public:
	Employee(string firstName = "", string lastName= "", string socialSecurityNumber = "")
		: firstName(firstName), lastName(lastName), socialSecurityNumber(socialSecurityNumber) {
	}
	virtual double earnings() = 0;
	virtual void print() const {
		cout << "First Name: " << firstName;
		cout << "	Last Name: " << lastName << endl;
		cout << "Social Security Number: " << socialSecurityNumber << endl;
	}
	void setFirstName(string& fn) {
		firstName = fn;
	}
	void setLastName(string& ln) {
		lastName = ln;
	}
	void setSocialSecurityNumber(string& nu) {
		socialSecurityNumber = nu;
	}
	string getFirstName() const {
		return firstName;
	}
	string getLastName() const {
		return lastName;
	}
	string getSocialSecurityNumber() const {
		return socialSecurityNumber;
	}
	virtual ~Employee(){}
};

