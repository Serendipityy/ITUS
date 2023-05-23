#ifndef GDVANG_H
#define GDVANG_H

#include "GiaoDich.h"
class GDVang : public GiaoDich
{
public:
	GDVang();
	GDVang(char* _maGD, char* _hoTen, DiaChi _diaChi, NgayGD _ngayGD, int _donGia, int _soLuong);
	void nhap();
	void xuat();
	double tinhThanhTien();


};

#endif // !GDVANG_H


