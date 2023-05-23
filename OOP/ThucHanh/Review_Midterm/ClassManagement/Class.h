#pragma once
#include"Student.h"
#include<iostream>
#include<string>
using namespace std;

class Class {
private:
	string cName;
	int num;
	Student* sList;
	int n; // so luong hoc sinh
public:
	Class();
	~Class();
	void input();
	void print();
	void searchDOB();
	Class& operator=(const Class& other);
};