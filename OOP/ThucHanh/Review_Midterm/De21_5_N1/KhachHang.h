#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class KhachHang {
protected:
	char* maKH;
	char* hoTen;
	char* ngayHoaDon;
	double soLuong, donGia;
public:
	KhachHang();
	KhachHang(char* _maKH, char* _hoTen, char* _ngayHoaDon, double _soLuong, double _donGia);
	virtual ~KhachHang();
	virtual void nhap();
	virtual void xuat();
	virtual double tinhThanhTien();

	char* getNgayHoaDon();
	char* getMaKH();
	char* getHoTen();
	double getSoLuong();
	double getDonGia();
};