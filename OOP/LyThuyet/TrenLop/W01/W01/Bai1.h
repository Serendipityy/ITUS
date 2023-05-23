#pragma once
#include<iostream>
using namespace std;

class Car {
private:
	int yearModel;
	string make;
	int speed;
public:
	// Constructor
	Car(int yearModel, string make) {
		this->yearModel = yearModel;
		this->make = make;
		this->speed = 0;
	}
	int getYearModel() {
		return this->yearModel;
	}
	string getMake() {
		return this->make;
	}
	int getSpeed() {
		return this->speed;
	}
	void accelerate() {
		this->speed += 5;
	}
	void brake() {
		this->speed -= 5;
	}

	// Accessor
};