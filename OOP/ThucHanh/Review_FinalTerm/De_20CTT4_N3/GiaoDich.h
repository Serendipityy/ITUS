#ifndef GIAODICH_H
#define GIAODICH_H

#include "NgayGD.h"
#include "DiaChi.h"

class GiaoDich {
protected:
	char* maGD;
	char* hoTen;
	DiaChi diaChi;
	NgayGD ngayGD;
	int donGia;
	int soLuong;
public:
	GiaoDich();
	GiaoDich(char* _maGD, char* _hoTen,DiaChi _diaChi, NgayGD _ngayGD, int _donGia, int _soLuong);
	GiaoDich(const GiaoDich& other);
	~GiaoDich();
	virtual void nhap();
	virtual void xuat();
	virtual double tinhThanhTien();

	int getSoLuong();

};

#endif // !GIAODICH_H




