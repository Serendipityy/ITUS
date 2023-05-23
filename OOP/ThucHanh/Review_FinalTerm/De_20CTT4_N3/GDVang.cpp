#include "GDVang.h"

GDVang::GDVang() : GiaoDich() {}

GDVang::GDVang(char* _maGD, char* _hoTen, DiaChi _diaChi, NgayGD _ngayGD, int _donGia, int _soLuong)
	: GiaoDich(_maGD, _hoTen, _diaChi, _ngayGD, _donGia, _soLuong) { }

void GDVang::nhap() {
	GiaoDich::nhap();
}
void GDVang::xuat() {
	GiaoDich::xuat();
	cout << "Thanh tien: " << tinhThanhTien() << endl;
}
double GDVang::tinhThanhTien() {
	return soLuong * donGia;
}

