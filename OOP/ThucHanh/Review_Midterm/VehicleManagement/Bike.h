#pragma once
#include "Vehicle.h"
#include<iostream>
#include<string>
using namespace std;

class Bike : public Vehicle {
public:
	Bike();
	~Bike();

	void input();
	void print();
	double calcRentMoney(); // tinh tien thue xe
};
