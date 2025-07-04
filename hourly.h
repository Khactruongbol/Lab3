#pragma once
#include "employee.h"
class HourlyEmployee : public Employee
{
private:
	double wage; // Lương giờ
	double hours; //Số giờ
public:
	HourlyEmployee(string firstName = "", string lastName = "", string socialSecurityNumber = "", double wage = 0, double hours = 0)
		: Employee(firstName, lastName, socialSecurityNumber), wage(wage), hours(hours){}
	friend istream& operator>>(istream& in, HourlyEmployee & ho) {
		string first;
		string last;
		string num;
		in.ignore();
		getline(in, first);
		ho.setFirstName(first);
		getline(in, last);
		ho.setLastName(last);
		getline(in, num);
		ho.setSocialSecurityNumber(num);
		in >> ho.wage;
		in >> ho.hours;
		return in;
	}
	void print() const override {
		Employee::print();
		cout << "Hourly Wage: " << wage;
		cout << "	Hours Worked: " << hours << endl;
	}
	void setWage(double wa) {
		wage = wa;
	}
	void setHours(double ho) {
		hours = ho;
	}
	double getWage() const {
		return wage;
	}
	double getHours() const {
		return hours;
	}
	double earnings() override {
		if (hours > 40) {
			return wage * 40 + (hours - 40) * wage*1.5;
		}
		else {
			return wage * hours;
		}
	}
};

