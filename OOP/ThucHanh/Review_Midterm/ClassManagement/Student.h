#pragma once
#include "Date.h"
#include<iostream>
#include<string>
using namespace std;
class Student {
private:
	string id; 
	string name;
	string gender;
	Date dob;
	string address;
public:
	Student();
	friend istream& operator>>(istream& is, Student& s);
	friend ostream& operator<<(ostream& os, const Student& s);

	string getID() {
		return id;
	}
};