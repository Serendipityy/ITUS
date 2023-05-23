#pragma once
#include "Gate.h"

class AcademicGate : public Gate
{
protected:
	int intellectual;
public:
	AcademicGate();
	~AcademicGate();
	void input();
	void print();
	int condition();
};

