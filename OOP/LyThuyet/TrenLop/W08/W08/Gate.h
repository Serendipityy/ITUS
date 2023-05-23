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
	virtual void input();
	virtual void print();
	virtual int condition();
};
