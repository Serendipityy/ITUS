#include "GiaoDich.h"

GiaoDich::GiaoDich() {
	maGD = "";
	ngay = thang = nam = 0;
	donGia = dienTich = 0.0;
}

GiaoDich::GiaoDich(string _maGD, int _ngay, int _thang, int _nam, double _donGia, double _dienTich) {
	maGD = _maGD;
	ngay = _ngay;
	thang = _thang;
	nam = _nam;
	donGia = _donGia;
	dienTich=_dienTich;
}

void GiaoDich::nhap() {
	cin.ignore();
	cout << "Nhap ma giao dich: ";
	getline(cin, maGD);
	cout << "Nhap ngay thang nam: ";
	cin >> ngay >> thang >> nam;
	cout << "Nhap don gia: ";
	cin >> donGia;
	cout << "Nhap dien tich: ";
	cin >> dienTich;
	//cin.ignore();
}
void GiaoDich::xuat() {
	cout << "Ma giao dich: " << maGD << endl;
	cout << "Ngay giao dich: " << ngay << "/" << thang << "/" << nam << endl;
	cout << "Don gia: " << donGia << endl;
	cout << "Dien tich: " << dienTich << endl;
}
