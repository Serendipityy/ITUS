#pragma once
#include "Developer.h"
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/* BACK-END DEVELOPER CLASS STRUCTURE */
// LOP DAN XUAT
// Ke thua nhung gi co ben lop cha
class BackEndDev : public Developer{
private:
	float workingHours;
public:
	void inputInfo();
	void printInfo();
	float calcSalary();
	//double totalSalaryBeDev(BackEndDev* beList[], int nBe);
	
	BackEndDev();
	~BackEndDev();
};



