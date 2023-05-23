#pragma once
#include "GiaoDich.h"
#include<iostream>
#include<string>
using namespace std;

class GDNha : public GiaoDich {
private:
	string loaiNha;
	string diaChi;
public:
	GDNha();
	GDNha(string _maGD, int _ngay, int _thang, int _nam, double _donGia, double _dienTich, string _loaiNha, string _diaChi);
	void nhap();
	void xuat();
	double tinhThanhTien();

};