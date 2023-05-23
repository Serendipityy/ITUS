#include "GDVang.h"

GDVang::GDVang() : GiaoDich() {
	loaiVang = new char[21];
}

GDVang::GDVang(char* _maGD, char* _ngayGD, double _donGia, int _soLuong, char* _loaiVang) : GiaoDich(_maGD, _ngayGD, _donGia, _soLuong) {
	loaiVang = new char[21];
	strcpy(loaiVang, _loaiVang);
}

//GDVang::GDVang(const GDVang& gdv) : GiaoDich() {
//	loaiVang = new char[21];
//	strcpy(loaiVang, gdv.loaiVang);
//}

GDVang::~GDVang() {
	delete[] loaiVang;
}
void GDVang::nhap() {
	GiaoDich::nhap();
	cout << "Nhap loai vang: ";
	cin.ignore();
	cin.getline(loaiVang, 21);
}

void GDVang::xuat() {
	GiaoDich::xuat();
	cout << "Loai vang: " << loaiVang;
}

double GDVang::thanhTien() {
	return soLuong * donGia;
}