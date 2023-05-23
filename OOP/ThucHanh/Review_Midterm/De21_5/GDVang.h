#pragma once
#include "GiaoDich.h"

class GDVang : public GiaoDich{
private:
	char* loaiVang;
public:
	GDVang();
	GDVang(char* _maGD, char* _ngayGD, double _donGia, int _soLuong, char* _loaiVang);
	//GDVang(const GDVang& gdv);
	~GDVang();
	void nhap();
	void xuat();
	double thanhTien();
};