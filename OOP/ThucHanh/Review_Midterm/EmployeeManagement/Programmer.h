#pragma once
#include "Employee.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Programmer : public Employee {
private:
	double overtimeSalary;
public:

	void readFile(ifstream&);
	void printFromFile();
};