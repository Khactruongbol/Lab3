#pragma once
#include "employee.h"
class SalariedEmployee : public Employee
{
private:
	double weeklySalary; //Lương tuần
public:
	SalariedEmployee(string firstName = "", string lastName = "", string socialSecurityNumber = "", double weeklySalary = 0)
		: Employee(firstName, lastName, socialSecurityNumber), weeklySalary(weeklySalary){}
	friend istream& operator>>(istream& in, SalariedEmployee & sa) {
		string first;
		string last;
		string num;
		double salary;
		in.ignore();
		getline(in, first);
		sa.setFirstName(first);
		getline(in, last);
		sa.setLastName(last);
		getline(in, num);
		sa.setSocialSecurityNumber(num);
		in >> salary;
		sa.setWeeklySalary(salary);
		return in;
	}
	void print() const override {
		Employee::print();
		cout << "Weekly Salary: $" << weeklySalary << endl;
	}
	void setWeeklySalary(double w) {
		weeklySalary = w;
	}
	double getWeeklySalary() const {
		return weeklySalary;
	}
	double earnings() override {
		return weeklySalary;
	}
};

