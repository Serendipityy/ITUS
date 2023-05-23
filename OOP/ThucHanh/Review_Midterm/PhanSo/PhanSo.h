#pragma once
#include<iostream>
using namespace std;

class PhanSo {
private:
	int tu;
	int mau;
public:
	PhanSo();
	PhanSo(int _tu, int _mau);
	PhanSo(const PhanSo&p);
	int UCLN(int a, int b);
	void toiGian();
	PhanSo operator+(const PhanSo&p);
	PhanSo operator-(const PhanSo&p);
	PhanSo operator*(const PhanSo&p);
	PhanSo operator/(const PhanSo&p);
	bool operator>(const PhanSo&p);
	bool operator<(const PhanSo&p);
	bool operator==(const PhanSo&p);
	friend ostream& operator<<(ostream& out, const PhanSo& p);
	friend istream& operator>>(istream& in, PhanSo& p);
};