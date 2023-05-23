#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

/* KHAI BAO CAU TRUC CLASS CHA - LOP CO SO */
class Developer {
// De nhung thuoc tinh chung trong protected
// de class con co the dung lai nhung thuoc tinh chung
protected:
	string name;
	int age;
	string gender;
	string address;
	string phoneNumber;
	float height;
	float weight;
public:
	void printInfo();
	void inputInfo();

	Developer();
	~Developer();

};
