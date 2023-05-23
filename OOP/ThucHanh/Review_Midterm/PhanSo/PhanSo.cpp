#include "PhanSo.h"


PhanSo::PhanSo() {
	tu = 0;
	mau = 1;
}

PhanSo::PhanSo(int _tu, int _mau) {
	tu = _tu;
	mau = _mau;
}

PhanSo::PhanSo(const PhanSo& p) {
	tu = p.tu;
	mau = p.mau;
}

int PhanSo::UCLN(int a, int b) {
	if (b == 0) return a;
	return UCLN(b, a % b);
}

void PhanSo::toiGian() {
	int ucln = UCLN(tu, mau);
	tu /= ucln;
	mau /= ucln;
	if (mau < 0) {
		tu = -tu;
		mau = -mau;
	}
}

PhanSo PhanSo::operator+(const PhanSo& p) {
	PhanSo temp;
	temp.tu = tu * p.mau + mau * p.tu;
	temp.mau = mau * p.mau;
	temp.toiGian();
	return temp;
}

PhanSo PhanSo::operator-(const PhanSo& p) {
	PhanSo temp;
	temp.tu = tu * p.mau - mau * p.tu;
	temp.mau = mau * p.mau;
	temp.toiGian();
	return temp;
}

PhanSo PhanSo::operator*(const PhanSo& p) {
	PhanSo temp;
	temp.tu = tu * p.tu;
	temp.mau = mau * p.mau;
	temp.toiGian();
	return temp;
}

PhanSo PhanSo::operator/(const PhanSo& p) {
	PhanSo temp;
	temp.tu = tu * p.mau;
	temp.mau = mau * p.tu;
	temp.toiGian();
	return temp;
}

bool PhanSo::operator>(const PhanSo& p) {
	return tu * p.mau > mau * p.tu;
}
bool PhanSo::operator<(const PhanSo& p) {
	return tu * p.mau < mau* p.tu;
}

bool PhanSo::operator==(const PhanSo& p) {
	return tu * p.mau == -mau * p.tu;
}


ostream& operator <<(ostream& os, const PhanSo& p) {
	os << p.tu << "/" << p.mau;
	return os;
}
istream& operator>>(istream& is, PhanSo& p) {
	is >> p.tu >> p.mau;
	p.toiGian();
	return is;
}
