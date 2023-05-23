#pragma once
#include "Reader.h"
#include <iostream>
#include <string>
using namespace std;

// lop con ChildrenReader ke thua lai lop cha Reader
class ChildrenReader : public Reader {
private:
	string representativeName;

public:
	ChildrenReader();
	~ChildrenReader();
	void input();
	void print();
	int calcRegistCardMoney();

};