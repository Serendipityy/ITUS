#pragma once
#include "DonThuc.h"
class DaThuc {
private:
    int num_of_monomials;
    DonThuc* list_of_monomials;
public:
    DaThuc();
    void nhap();
    void xuat();
    float tinhGiaTri(float);
    DaThuc operator + (const DaThuc& p2);
    DaThuc operator - (const DaThuc& p2);
    DaThuc operator * (const DaThuc& p2);
    DaThuc operator / (const DaThuc& p2);
};