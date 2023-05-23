#include "PhanSo.h"


PhanSo::PhanSo() {
    tuSo = 0;
    mauSo = 1;
}

PhanSo::PhanSo(int _tuSo, int _mauSo) {
    tuSo = _tuSo;
    mauSo = _mauSo;
}

// Getter, Setter
int PhanSo::getTuSo() {
    return tuSo;
}
int PhanSo::getMauSo() {
    return mauSo;
}

void PhanSo::nhap() {
    cout << "Nhap tu so: ";
    cin >> tuSo;
    cout << "Nhap mau so: ";
    cin >> mauSo;
    while (mauSo == 0) {
        cout << "Mau so khong duoc bang 0, vui long nhap lai: ";
        cin >> mauSo;
    }
}

void PhanSo::xuat() {
    cout << tuSo << "/" << mauSo << endl;
}

int PhanSo::ucln(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (a * b != 0) {
        if (a > b) {
            a %= b;
        }
        else {
            b %= a;
        }
    }
    return a + b;
}

void PhanSo::toiGian() {
    int u = ucln(tuSo, mauSo);
    tuSo /= u;
    mauSo /= u;
}

PhanSo PhanSo::operator+(const PhanSo& p) {
    PhanSo temp;
    temp.tuSo = tuSo * p.mauSo + p.tuSo * mauSo;
    temp.mauSo = mauSo * p.mauSo;
    temp.toiGian();
    return temp;
}

PhanSo PhanSo::operator-(const PhanSo& p) {
    PhanSo temp;
    temp.tuSo = tuSo * p.mauSo - p.tuSo * mauSo;
    temp.mauSo = mauSo * p.mauSo;
    temp.toiGian();
    return temp;
}

PhanSo PhanSo::operator*(const PhanSo& p) {
    PhanSo temp;
    temp.tuSo = tuSo * p.tuSo;
    temp.mauSo = mauSo * p.mauSo;
    temp.toiGian();
    return temp;
}

PhanSo PhanSo::operator/(const PhanSo& p) {
    PhanSo temp;
    temp.tuSo = tuSo * p.mauSo;
    temp.mauSo = mauSo * p.tuSo;
    temp.toiGian();
    return temp;
}

