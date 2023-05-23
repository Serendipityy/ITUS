#pragma once
#include<iostream>
#include<string>
using namespace std;

class Vehicle {
protected:
	string rentName;
	double rentHour;
public:
	Vehicle();
	~Vehicle();

	void input();
	void print();
};