#pragma once
#include "Reader.h"
#include <iostream>
#include <string>
using namespace std;

class AdultReader : public Reader {
private:
	string identityCard;
public:
	AdultReader();
	~AdultReader();

	void input();
	void print();
	int calcRegistCardMoney();


};