#include "GDDat.h"
#include "GiaoDich.h"

GDDat::GDDat() : GiaoDich() {
	loaiDat = 0;
	dienTich = 0.0;
}
GDDat::GDDat(string _maGD, int _ngay, int _thang, int _nam, double _donGia, double _dienTich, char _loaiDat)
	: GiaoDich(_maGD, _ngay, _thang, _nam, _donGia, _dienTich) {
	loaiDat = _loaiDat;
}
void GDDat::nhap() {
	GiaoDich::nhap();
	cout << "Nhap loai dat (A / B / C): ";
	cin >> loaiDat;
}
double GDDat::tinhThanhTien() {
	if (loaiDat == 'B' or loaiDat == 'C') {
		return dienTich * donGia;
	}
	else if (loaiDat == 'A') {
		return dienTich * donGia * 1.5;
	}
}

void GDDat::xuat() {
	GiaoDich::xuat();
	cout << "Loai dat: " << loaiDat << endl;
	cout << "Thanh tien: " << tinhThanhTien() << endl;
}

