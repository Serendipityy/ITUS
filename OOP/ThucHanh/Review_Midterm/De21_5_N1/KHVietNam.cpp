#include "KhachHang.h"
#include "KHVietNam.h"

KHVietNam::KHVietNam() : KhachHang() {
	doiTuongKH = new char[100];
	dinhMuc = 0.0;
}

KHVietNam::KHVietNam(char* _maKH, char* _hoTen, char* _ngayHoaDon, double _soLuong, double _donGia, char* _doiTuong, double _dinhMuc)
	: KhachHang(_maKH, _hoTen, _ngayHoaDon, _soLuong, _donGia) {
	doiTuongKH = new char[100];
	strcpy(doiTuongKH, _doiTuong);
	dinhMuc = _dinhMuc;
}
void KHVietNam::nhap() {
	KhachHang::nhap();
	cout << "Doi tuong (sinh hoat/kinh doanh/san xuat): ";
	cin.ignore();
	cin.getline(doiTuongKH, 100);
	if (strcmp(doiTuongKH, "sinh hoat") == 0) {
		dinhMuc = 200;
	}
	else if (strcmp(doiTuongKH, "kinh doanh") == 0) {
		dinhMuc = 600;
	}
	else if (strcmp(doiTuongKH, "san xuat") == 0) {
		dinhMuc = 900;
	}
}
void KHVietNam::xuat() {
	KhachHang::xuat();
	cout << "Doi tuong: " << doiTuongKH << endl;
	cout << "Dinh muc: " << dinhMuc << endl;
	cout << "Thanh tien: " <<tinhThanhTien() << endl;
}

double KHVietNam::tinhThanhTien() {
	if (soLuong < dinhMuc) {
		return soLuong * donGia;
	}
	else {
		return (donGia * dinhMuc) + ((soLuong - dinhMuc) * donGia * 2.5);
	}
}

char* KHVietNam::getDoiTuong() {
	return doiTuongKH;
}