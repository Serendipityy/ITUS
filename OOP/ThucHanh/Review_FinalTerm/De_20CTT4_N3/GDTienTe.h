#ifndef GDTIENTE_H
#define GDTIENTE_H

#include "GiaoDich.h"
class GDTienTe : public GiaoDich
{
private:
	double tiGia;
	int loaiTienTe;
public:
	GDTienTe();
	GDTienTe(char* _maGD, char* _hoTen, DiaChi _diaChi, NgayGD _ngayGD, int _donGia, int _soLuong, double _tiGia, int _loaiTienTe);
	void nhap();
	void xuat();
	double tinhThanhTien();
};

#endif // !GDTIENTE_H


