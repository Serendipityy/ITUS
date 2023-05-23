#include "DiaChi.h"

DiaChi::DiaChi() {
	soNha = new char[11];
	tenDuong = new char[51];
	phuong = new char[51];
	quan = new char[51];
	tp = new char[51];
}
DiaChi::DiaChi(char* _soNha, char* _tenDuong, char* _phuong, char* _quan, char* _tp) {
	soNha = new char[11];
	strcpy(soNha, _soNha);
	tenDuong = new char[51];
	strcpy(tenDuong, _tenDuong);
	phuong = new char[51];
	strcpy(phuong, _phuong);
	quan = new char[51];
	strcpy(quan, _quan);
	tp = new char[51];
	strcpy(tp, _tp);
}
DiaChi::DiaChi(const DiaChi& other) {
	soNha = new char[11];
	strcpy(soNha, other.soNha);
	tenDuong = new char[51];
	strcpy(tenDuong, other.tenDuong);
	phuong = new char[51];
	strcpy(phuong, other.phuong);
	quan = new char[51];
	strcpy(quan, other.quan);
	tp = new char[51];
	strcpy(tp, other.tp);
}

DiaChi::~DiaChi() {
	delete[] soNha;
	delete[] tenDuong;
	delete[] phuong;
	delete[] quan;
	delete[] tp;
}

// NOTE: BỊ LỖI CHỖ ĐỊA CHỈ (CIN.IGNORE())
// PHẢI CÁCH MỘT DÒNG TRỐNG RỒI NHẬP ĐỊA CHỈ MỚI IN RA ĐÚNG
void DiaChi::nhapDC() {
	cout << "------Nhap dia chi-------" << endl;
	cin.ignore();
	cout << "Nhap so nha: ";
	cin.getline(soNha, 11);
	cout << "Nhap ten duong: ";
	cin.getline(tenDuong, 51);
	cout << "Nhap phuong: ";
	cin.getline(phuong, 51);
	cout << "Nhap quan: ";
	cin.getline(quan, 51);
	cout << "Nhap thanh pho: ";
	cin.getline(tp, 51);
	cout << "-------------------------" << endl;
}

void DiaChi::xuatDC() {
	cout << "Dia chi: " << soNha << " " << tenDuong << " " << phuong << " " << quan << " " << tp << endl;
}