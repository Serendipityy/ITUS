#include "Prince.h"

Prince::Prince()
{
	
}


Prince::~Prince()
{
}

void Prince::input()
{
	cout << "[Nhap thong so cua hoang tu]" << endl;
	cout << "Nhap so tien cua hoang tu: "; cin >> money;
	cout << "Nhap tri tue cua hoang tu: "; cin >> intellectual;
	cout << "Nhap suc manh cua hoang tu: "; cin >> power;
}