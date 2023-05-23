/********************************************************
* File giao dien cho lop myexception, myexception.h
*********************************************************/
#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <iostream>
#include <string>
using namespace std;
class myException {
private:
	string message;
public:
	myException() {
		message = "";
	}
	myException(string msg) {
		message = msg;
	}
	string getMessage() {
		return message;
	}

	const char* what() const noexcept {
		return message.c_str();
	}
};
#endif