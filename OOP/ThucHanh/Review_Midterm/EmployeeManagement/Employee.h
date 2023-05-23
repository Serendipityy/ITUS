#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

class DOB {
private:
	int date, month, year;
public:
	int getDate() { return date; }
	void setDate(int _date) { date = _date; }
	int getMonth() { return month; }
	void setMonth(int _month) { month = _month; }
	int getYear() { return year; }
	void setYear(int _year) { year = _year; }

};
class Employee {
protected:
	string id;
	string name;
	DOB dob;
	string address;
	double coeffSalary; // he so luong
	double salary;
public:
	Employee();
	~Employee();

	virtual void readFile(ifstream&);
	virtual void printFromFile();
};