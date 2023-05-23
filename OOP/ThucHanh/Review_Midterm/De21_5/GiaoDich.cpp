#include "GiaoDich.h"
GiaoDich::GiaoDich() {
	maGD = new char[6];
	ngayGD = new char[11];
	donGia = 0.0;
	soLuong = 0;
}

GiaoDich::GiaoDich(char* _maGD, char* _ngayGD, double _donGia, int _soLuong) {
	maGD = new char[6];
	ngayGD = new char[11];
	strcpy(maGD, _maGD);
	strcpy(ngayGD, _ngayGD);
	donGia = _donGia;
	soLuong = _soLuong;
}
//
//GiaoDich::GiaoDich(const GiaoDich&gd) {
//	maGD = new char[6];
//	ngayGD = new char[11];
//	strcpy(maGD, gd.maGD);
//	strcpy(ngayGD, gd.ngayGD);
//	donGia = gd.donGia;
//	soLuong = gd.soLuong;
//}

GiaoDich::~GiaoDich() {
	delete[] maGD;
	delete[] ngayGD;
}

void GiaoDich::nhap() {
	cout << "Nhap ma giao dich: ";
	cin.ignore();
	cin.getline(maGD, 6);
	cout << "Nhap ngay giao dich: ";
	cin.getline(ngayGD, 11);
	cout << "Nhap don gia: ";
	cin >> donGia;
	cout << "Nhap so luong: ";
	cin >> soLuong;
}
void GiaoDich::xuat() {
	cout << "\nMa giao dich: " << maGD << endl;
	cout << "Ngay giao dich: " << ngayGD << endl;
	cout << "Don gia: " << donGia << endl;
	cout << "So luong: " << soLuong << endl;
}

int GiaoDich::getSoLuong() {
	return soLuong;
}

char* GiaoDich::getNgayGD() {
	return ngayGD;
}

//bool GiaoDich::checkDate(char* ngayGD) {
//	int ngay, thang, nam;
//	sscanf(ngayGD, "%d/%d/%d", &ngay, &thang, &nam);
//	if (thang == 1 && nam == 2021) {
//		return true;
//	}
//	return false;
//}

//void GiaoDich::xuatGiaoDich01Nam2021(GiaoDich* listGD, int n) {
//	for (int i = 0; i < n; i++) {
//		if (checkDate(listGD[i].getNgayGD())) {
//			cout << "Thong tin giao dich " << i + 1 << ":" << endl;
//			listGD[i].xuat();
//		}
//	}
//}
