/***********************************************************
* Divide two integer and exception handle 'Divide by zero'
* File divde_two_integer.h
************************************************************/
#include <iostream>
using namespace std;
#include "myexception.h";
class Divide {
	int num1;
	int num2;
public:
	Divide() {
		num1 = 0;
		num2 = 0;
	}
	~Divide() {

	}
	void input() {
		cout << "Enter first number: ";
		cin >> num1;
		cout << "Enter second number: ";
		cin >> num2;
	}
	double division() {
		if (num2 == 0) {
			throw myException("Divide by zero exception");
		}
		return static_cast<double>(num1) / num2;
	}
};