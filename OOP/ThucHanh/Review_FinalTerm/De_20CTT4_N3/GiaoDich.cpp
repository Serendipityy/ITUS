#include "GiaoDich.h"

GiaoDich::GiaoDich() {
	maGD = new char[6];
	hoTen = new char[51];
	donGia = 0.0;
	soLuong = 0;
}
GiaoDich::GiaoDich(char* _maGD, char* _hoTen, DiaChi _diaChi, NgayGD _ngayGD, int _donGia, int _soLuong) {
	maGD = new char[6];
	strcpy(maGD, _maGD);
	hoTen = new char[51];
	strcpy(hoTen, _hoTen);
	diaChi = _diaChi;
	ngayGD = _ngayGD;
	donGia = _donGia;
	soLuong = _soLuong;
}

GiaoDich::GiaoDich(const GiaoDich& other) {
	maGD = new char[6];
	strcpy(maGD, other.maGD);
	hoTen = new char[51];
	strcpy(hoTen, other.hoTen);
	diaChi = other.diaChi;
	ngayGD = other.ngayGD;
	donGia = other.donGia;
	soLuong = other.soLuong;
}

GiaoDich::~GiaoDich() {
	delete[] maGD;
	delete[] hoTen;
}

void GiaoDich::nhap() {
	do {
		cout << "Nhap ma giao dich (5 ki tu so): ";
		cin >> maGD;
		if (strlen(maGD) != 5) {
			cout << "Ma giao dich khong hop le!" << endl;
		}
	} while (strlen(maGD) != 5);
	cin.ignore();
	cout << "Nhap ho ten khach hang: ";
	cin.getline(hoTen, 51);
	diaChi.nhapDC();
	ngayGD.nhapNgayGD();
	do {
		cout << "Nhap don gia: ";
		cin >> donGia;
		if (donGia != 1000 && donGia != 2000 && donGia != 5000
			&& donGia != 10000 && donGia != 20000 && donGia != 50000
			&& donGia != 100000 && donGia != 200000 && donGia != 500000) {
			cout << "Don gia khong hop le!" << endl;
		}
	} while (donGia != 1000 && donGia != 2000 && donGia != 5000
	&& donGia != 10000 && donGia != 20000 && donGia != 50000
	&& donGia != 100000 && donGia != 200000 && donGia != 500000);
	cout << "Nhap so luong: ";
	cin >> soLuong;
}

void GiaoDich::xuat() {
	cout << "Ma giao dich: " << maGD << endl;
	cout << "Ho ten khach hang: " << hoTen << endl;
	diaChi.xuatDC();
	ngayGD.xuatNgayGD();
	cout << "Don gia: " << donGia << endl;
	cout << "So luong: " << soLuong << endl;
}

 
double GiaoDich::tinhThanhTien() {
	return soLuong * donGia;
}

int GiaoDich::getSoLuong() { return soLuong; }
