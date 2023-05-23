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
	Divide();
	~Divide();
	void input();
	double division();
};