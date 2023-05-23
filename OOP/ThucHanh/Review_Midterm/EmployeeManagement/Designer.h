#pragma once
#include "Employee.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Designer : public Employee {
private:
	double bonusSalary;
public:

	void readFile(ifstream&);
	void printFromFile();
};