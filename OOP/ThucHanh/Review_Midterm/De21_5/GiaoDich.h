#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include<cstring>
using namespace std;

class GiaoDich {
protected:
	char* maGD;
	char* ngayGD;
	double donGia;
	int soLuong;
public:
	GiaoDich();
	GiaoDich(char* _maGD, char* _ngayGD, double _donGia, int _soLuong);
	GiaoDich(const GiaoDich&gd);
	~GiaoDich();
	virtual void nhap();
	virtual void xuat();
	virtual double thanhTien() = 0;
	virtual int getSoLuong();

	virtual char* getNgayGD();

};