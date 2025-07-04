#pragma once
#include "commission.h"
class BasePlusCommissionEmployee : public CommissionEmployee
{
private:
	double baseSalary; //Lương cơ bản/tuần
public:
	BasePlusCommissionEmployee(string firstName = "", string lastName = "", string socialSecurityNumber = "", double grossSales = 0, double commissionRate = 0, double baseSalary = 0)
		: CommissionEmployee(firstName, lastName, socialSecurityNumber, grossSales, commissionRate), baseSalary(baseSalary) {
	}
	friend istream& operator>>(istream& in, BasePlusCommissionEmployee& ba) {
		string first;
		string last;
		string num;
		double sale;
		double rate;
		double base;
		in.ignore();
		getline(in, first);
		ba.setFirstName(first);
		getline(in, last);
		ba.setLastName(last);
		getline(in, num);
		ba.setSocialSecurityNumber(num);
		in >> sale;
		ba.setGrossSales(sale);
		in >> rate;
		ba.setCommissionRate(rate);
		in >> base;
		ba.setBaseSalary(base);
		return in;
	}
	void setBaseSalary(double bs) {
		baseSalary = bs;
	}
	double getBaseSalary() const {
		return baseSalary;
	}
	void print() const override {
		CommissionEmployee::print();
		cout << "Base Salary: $" << baseSalary << endl;
	}
	double earnings() override {
		return baseSalary + CommissionEmployee::earnings();
	}
};

