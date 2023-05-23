#pragma once
#include "Gate.h"

class BusinessGate : public Gate
{
protected:
	int price, quantity;
public:
	BusinessGate();
	~BusinessGate();
	void input() {
		cout << "--> Nhap don gia: ";
		cin >> price;
		cout << "--> Nhap so luong hang: ";
		cin >> quantity;
	}
	int feature() {
		return price * quantity;
	}
};




