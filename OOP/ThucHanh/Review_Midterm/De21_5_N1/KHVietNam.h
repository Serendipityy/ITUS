#pragma once
#include "KhachHang.h"

class KHVietNam : public KhachHang {
private:
	char* doiTuongKH;
	double dinhMuc;
public:
	KHVietNam();
	KHVietNam(char* _maKH, char* _hoTen, char* _ngayHoaDon, double _soLuong, double _donGia, char* _doiTuong, double _dinhMuc);
	void nhap();
	void xuat();
	double tinhThanhTien();

	char* getDoiTuong();
};