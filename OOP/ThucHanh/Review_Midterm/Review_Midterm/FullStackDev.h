#pragma once
#include "Developer.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/* FULLSTACK DEVELOPER CLASS STRUCTURE */

class FullStackDev : public Developer {
private:
	float completedPercent;
public:
	void inputInfo();
	void printInfo();
	float calcSalary();
	//double totalSalaryFsDev(FullStackDev* fsList[], int nFs);
	
	FullStackDev();
	~FullStackDev();
};



