#pragma once
#include "Developer.h"
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

/* FRONT-END DEVELOPER CLASS STRUCTURE */
class FrontEndDev : public Developer {
private:
	int projects;
public:
	void inputInfo();
	void printInfo();
	float calcSalary();
	//double totalSalaryFeDev(FrontEndDev* feList[], int nFe);
	
	FrontEndDev();
	~FrontEndDev();
};


