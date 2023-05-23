#pragma once
#include "GiaoDich.h"

class GDTienTe : public GiaoDich{
private:
	int loaiTien;
	double tiGia;
public:
	GDTienTe();
	GDTienTe(char* _maGD, char* _ngayGD, double _donGia, int _soLuong, int _loaiTien, double _tiGia);
	GDTienTe(const GDTienTe& gdtt);
	void nhap();
	void xuat();
	double thanhTien();

	int getLoaiTien();
};