#include "Phim.h"
Phim::Phim() {
	maSo = new char[10];
	tenPhim = new char[50];
	theLoai = new char[20];
	nhaSX = new char[50];
	namSX = 0;
	xepHang = 0.0;
}

Phim::~Phim() {
	delete maSo;
	maSo = NULL;
	delete tenPhim;
	tenPhim = NULL;
	delete theLoai;
	theLoai = NULL;
	delete nhaSX;
	nhaSX = NULL;
}

void Phim::Nhap() {
	cin.ignore();
	cout << "Nhap ma so: ";
	cin.getline(maSo, 10);
	cout << "Nhap ten phim: ";
	cin.getline(tenPhim, 50);
	cout << "Nhap the loai: ";
	cin.getline(theLoai, 20);
	cout << "Nhap nha san xuat: ";
	cin.getline(nhaSX, 50);
	cout << "Nhap nam san xuat: ";
	cin >> namSX;
	cout << "Nhap xep hang: ";
	cin >> xepHang;
}

void Phim::Xuat() {
	cout << "Ma so: " << maSo << endl;
	cout << "Ten phim: " << tenPhim << endl;
	cout << "The loai: " << theLoai << endl;
	cout << "Nha san xuat: " << nhaSX << endl;
	cout << "Nam san xuat: " << namSX << endl;
	cout << "Xep hang: " << xepHang << endl;
}

char* Phim::getTheLoai() {
	return theLoai;
}

float Phim::getXepHang() {
	return xepHang;
}
char* Phim::getNhaSX() {
	return nhaSX;
}

int Phim::getNamSX() {
	return namSX;
}
//
//Phim&Phim::operator=(const Phim& p) {
//	if (this == &p) {
//		return *this;
//	}
//	if (maSo != NULL) {
//		delete maSo;
//		maSo = new char[10];
//		strcpy(maSo, p.maSo);
//	}
//	if (tenPhim != NULL) {
//		delete tenPhim;
//		tenPhim = new char[50];
//		strcpy(tenPhim, p.tenPhim);
//	}
//
//	if (theLoai != NULL) {
//		delete theLoai;
//		theLoai = new char[20];
//		strcpy(theLoai, p.theLoai);
//	}
//
//	if (nhaSX != NULL) {
//		delete nhaSX;
//		nhaSX = new char[50];
//		strcpy(nhaSX, p.nhaSX);
//	}
//
//	namSX = p.namSX;
//	xepHang = p.xepHang;
//	
//}

bool Phim::operator==(const Phim& other) const {
	return (strcmp(maSo, other.maSo) == 0
		&& strcmp(tenPhim, other.tenPhim) == 0
		&& strcmp(theLoai, other.theLoai) == 0
		&& strcmp(nhaSX, other.nhaSX) == 0
		&& namSX == other.namSX
		&& xepHang == other.xepHang);
}