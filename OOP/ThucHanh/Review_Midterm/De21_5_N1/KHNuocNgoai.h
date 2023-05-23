#pragma once
#include"KhachHang.h"
class KHNuocNgoai : public KhachHang{
private:
	char* quocTich;
public:
	KHNuocNgoai();
	KHNuocNgoai(char* _maKH, char* _hoTen, char* _ngayHoaDon, double _soLuong, double _donGia, char* _quocTich);
	void nhap();
	void xuat();
	double tinhThanhTien();
};