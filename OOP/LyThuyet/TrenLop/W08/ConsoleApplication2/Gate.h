#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Gate
{
protected:
	int type;
public:
	Gate();
	~Gate();
	virtual void input() = 0;
	virtual int feature() = 0;
	int getType() { return type; }
};