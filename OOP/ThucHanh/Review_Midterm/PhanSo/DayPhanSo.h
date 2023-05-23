#pragma once
#include "PhanSo.h"
#include<iostream>
using namespace std;

class DayPhanSo {
private:
	PhanSo* ds;
	int n;
public:
	DayPhanSo();
	DayPhanSo(int _n);
	DayPhanSo(const DayPhanSo& other);
	~DayPhanSo();
	void nhap();
	void xuat();
	PhanSo min();
	PhanSo max();
	void sapXepTang();
	void sapXepGiam();

	bool operator>(const DayPhanSo& other) const;
	bool operator<(const DayPhanSo& other) const;
	bool operator==(const DayPhanSo& other) const;

	//PhanSo& operator[](int index);
};