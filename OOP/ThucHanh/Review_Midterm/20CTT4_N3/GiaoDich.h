#pragma once
#include<iostream>
#include<string>
using namespace std;

class GiaoDich {
protected:
	string maGD;
	int ngay, thang, nam;
	double donGia, dienTich;
public:
	GiaoDich();
	GiaoDich(string _maGD, int _ngay, int _thang, int _nam, double _donGia, double _dienTich);
	virtual void nhap();
	virtual void xuat();
	virtual double tinhThanhTien() = 0;
	string getMaGD() { return maGD; }
	int getNgay() { return ngay; }
	int getThang() { return thang; }
	int getNam() { return nam; }
};