#pragma once
#include "Gate.h"

class PowerGate : public Gate
{
protected:
	int power;
public:
	PowerGate();
	~PowerGate();
	void input() {
		cout << "--> Nhap suc manh dung si: ";
		cin >> power;
	}
	int feature() {
		return power;
	}
};
