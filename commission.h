#pragma once
#include "employee.h"
class CommissionEmployee : public Employee
{
private:
	double grossSales; //Doanh số
	double commissionRate; //Tỉ lệ hoa hồng
public:
	CommissionEmployee(string firstName = "", string lastName = "", string socialSecurityNumber = "", double grossSales = 0, double commissionRate = 0)
		:Employee(firstName, lastName, socialSecurityNumber), grossSales(grossSales), commissionRate(commissionRate){ }
	friend istream& operator>>(istream& in, CommissionEmployee& co) {
		string first;
		string last;
		string num;
		double sale;
		double rate;
		in.ignore();
		getline(in, first);
		co.setFirstName(first);
		getline(in, last);
		co.setLastName(last);
		getline(in, num);
		co.setSocialSecurityNumber(num);
		in >> sale;
		co.setGrossSales(sale);
		in >> rate;
		co.setCommissionRate(rate);
		return in;
	}
	void print() const override {
		Employee::print();
		cout << "Gross Sales: " << grossSales;
		cout << "	Commission Rate: " << commissionRate << endl;
	}
	void setGrossSales(double gr) {
		grossSales = gr;
	}
	void setCommissionRate(double co) {
		commissionRate = co;
	}
	double getGrossSales() const {
		return grossSales;
	}
	double getCommissionRate() const {
		return commissionRate;
	}
	double earnings() override {
		return grossSales * commissionRate;
	}
};

