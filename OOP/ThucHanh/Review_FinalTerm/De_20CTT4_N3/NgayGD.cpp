#include "NgayGD.h"

NgayGD::NgayGD() {
	ngay = thang = nam = 0;
}

NgayGD::NgayGD(int _ngay, int _thang, int _nam) {
	ngay = _ngay;
	thang = _thang;
	nam = _nam;
}

int NgayGD::getNgay() { return ngay; }
int NgayGD::getThang() { return thang; }
int NgayGD::getNam() { return nam; }
void NgayGD::setNgay(int _ngay) { ngay = _ngay; }
void NgayGD::setThang(int _thang) { thang = _thang; }
void NgayGD::setNam(int _nam) { nam = _nam; }

void NgayGD::nhapNgayGD() {
	cout << "Nhap ngay giao dich (ngay thang nam): ";
	cin >> ngay >> thang >> nam;
}
void NgayGD::xuatNgayGD() {
	cout <<"Ngay giao dich: " << ngay << "/" << thang << "/" << nam << endl;
}