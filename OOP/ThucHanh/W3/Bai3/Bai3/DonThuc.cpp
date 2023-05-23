#include "DonThuc.h"
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


DonThuc::DonThuc() {
    coeff = 0;
    degree = 0;
} 
DonThuc::DonThuc(float c, int d) {
    coeff = c;
    degree = d;
}

int DonThuc::getDegree() {
    return degree;
}
float DonThuc::getCoeff() {
    return coeff;
}
void DonThuc::nhap() {
    cout << "Nhap he so: "; cin >> coeff;
    cout << "Nhap bac: "; cin >> degree;
}

void DonThuc::xuat() {
    if (degree == 0) {
        cout << coeff;
        return;
    }
    if (coeff == 1)
        cout << "x^" << degree;
    else if (coeff == -1)
        cout << "-x^" << degree;
    else
        cout << coeff << "x^" << degree;
}
float DonThuc::tinhGiaTri(float x) {
    return coeff * pow(x, degree);
}

DonThuc DonThuc::operator + (const DonThuc& d2) {
    DonThuc d;
    if (this->degree == d2.degree) {
        d.degree = this->degree;
        d.coeff = this->coeff + d2.coeff;
    }
    else if (this->degree > d2.degree) {
        d.degree = this->degree;
        d.coeff = this->coeff;
    }
    else {
        d.degree = d2.degree;
        d.coeff = d2.coeff;
    }
    return d;
}

DonThuc DonThuc::operator - (const DonThuc& d2) {
    DonThuc d;
    if (this->degree == d2.degree) {
        d.degree = this->degree;
        d.coeff = this->coeff - d2.coeff;
    }
    else if (this->degree > d2.degree) {
        d.degree = this->degree;
        d.coeff = this->coeff;
    }
    else {
        d.degree = d2.degree;
        d.coeff = -d2.coeff;
    }
    return d;
}
DonThuc DonThuc::operator * (const DonThuc & d2) {
    DonThuc d;
    d.degree = this->degree + d2.degree;
    d.coeff = this->coeff * d2.coeff;
    return d;
}

//DonThuc DonThuc::operator / (const DonThuc& d2) {
//    DonThuc d;
//    d.degree = this->degree - d2.degree;
//    d.coeff = this->coeff / d2.coeff;
//    return d;
//}
DonThuc DonThuc::operator / (const DonThuc& d2) {
    DonThuc d;
    if (this->degree < d2.degree) {
        d.degree = 0;
        d.coeff = 0;
    }
    else {
        d.degree = this->degree - d2.degree;
        d.coeff = this->coeff / d2.coeff;
    }
    return d;
}

// Hàm trả về đối của đơn thức hiện tại
DonThuc DonThuc::operator-() const {
    if (degree == 0)
        return DonThuc(-coeff, degree);
    return DonThuc(coeff, degree);
}