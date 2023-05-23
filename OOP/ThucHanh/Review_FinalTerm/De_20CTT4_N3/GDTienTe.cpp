#include "GDTienTe.h"

GDTienTe::GDTienTe() : GiaoDich() {
	tiGia = 0.0;
	loaiTienTe = 0;
}

GDTienTe::GDTienTe(char* _maGD, char* _hoTen, DiaChi _diaChi, NgayGD _ngayGD, int _donGia, int _soLuong, double _tiGia, int _loaiTienTe) 
	: GiaoDich(_maGD, _hoTen, _diaChi, _ngayGD, _donGia, _soLuong) {
	tiGia = _tiGia;
	loaiTienTe = _loaiTienTe;
}

void GDTienTe::nhap() {
	GiaoDich::nhap();
	cout << "Nhap ti gia: ";
	cin >> tiGia;
	cout << "Nhap loai tien te (1: VND, 2: USD, 3: Euro): ";
	cin >> loaiTienTe;
}

void GDTienTe::xuat() {
	GiaoDich::xuat();
	cout << "Ti gia: " << tiGia << endl;
	cout << "Loai tien te: ";
	switch (loaiTienTe) {
	case 1:
		cout << "VND";
		break;
	case 2:
		cout << "USD";
		break;
	case 3:
		cout << "Euro";
		break;
	default:
		cout << "Khong xac dinh";
		break;
	}
	cout << endl;
	cout << "Thanh tien: " << tinhThanhTien() << endl;
}
double GDTienTe::tinhThanhTien() {
	double thanhTien = 0;
	switch (loaiTienTe) {
	case 1:
		thanhTien = soLuong * donGia;
		break;
	case 2:
	case 3:
		thanhTien = soLuong * donGia * tiGia;
		break;
	}
	return thanhTien;
}