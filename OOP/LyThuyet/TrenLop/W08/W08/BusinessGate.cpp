#include "BusinessGate.h"

BusinessGate::BusinessGate()
{
}


BusinessGate::~BusinessGate()
{
}

void BusinessGate::input()
{
	Gate::input();
	cout << "Nhap don gia: "; cin >> price;
	cout << "Nhap so luong hang: "; cin >> quantity;
}

void BusinessGate::print()
{
	cout << "Don gia: " << price << endl;
	cout << "So luong hang: " << quantity << endl;
}

int BusinessGate::condition()
{
	return price * quantity;
}
