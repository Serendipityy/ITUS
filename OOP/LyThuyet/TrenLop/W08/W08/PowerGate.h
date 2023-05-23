#pragma once
#include "Gate.h"

class PowerGate : public Gate
{
private:
	int power;
public:
	PowerGate();
	~PowerGate();
	virtual void input();
	virtual void print();
	virtual int condition();
};
