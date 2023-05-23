#pragma once
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class DonThuc {
private:
    float coeff;
    int degree;
public:
    DonThuc();
    DonThuc(float, int);

    int getDegree();
    float getCoeff();
    void nhap();
    void xuat();
    float tinhGiaTri(float);
    DonThuc operator + (const DonThuc&);
    DonThuc operator - (const DonThuc&);
    DonThuc operator * (const DonThuc&);
    DonThuc operator / (const DonThuc&);

    // Hàm trả về đối của đơn thức hiện tại
    DonThuc operator-() const;
};

void menu();