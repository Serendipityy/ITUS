#pragma once
#include "Gate.h"

class BusinessGate : public Gate
{
protected:
	int price, quantity;
public:
	BusinessGate();
	~BusinessGate();
	void input();
	void print();
	int condition();
};


