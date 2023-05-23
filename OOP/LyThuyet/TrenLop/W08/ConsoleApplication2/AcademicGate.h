#pragma once
#include "Gate.h"

class AcademicGate : public Gate
{
protected:
	int intellectual;
public:
	AcademicGate();
	~AcademicGate();
	void input() {
		cout << "--> Nhap tri tue cua nha hien triet: ";
		cin >> intellectual;
	}
	int feature() {
		return intellectual;
	}
};

