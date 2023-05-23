#pragma once
#include "Vehicle.h"
#include<iostream>
#include<string>
using namespace std;

class Motorbike : public Vehicle {
private:
	int type;
	string numberPlate; // bien so xe
public:
	Motorbike();
	~Motorbike();

	void input();
	void print();
	double calcRentMoney();

	int getType() {
		return type;
	}
};