#pragma once
#include "GiaoDich.h"
#include<iostream>
#include<string>
using namespace std;

class GDDat :public GiaoDich {
private:
	char loaiDat;
public:
	GDDat();
	GDDat(string _maGD, int _ngay, int _thang, int _nam, double _donGia, double _dienTich, char _loaiDat);
	void nhap();
	void xuat();
	double tinhThanhTien();
};
