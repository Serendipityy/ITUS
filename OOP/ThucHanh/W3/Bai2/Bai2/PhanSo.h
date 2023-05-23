#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

// Class PhanSo
class PhanSo {
    int tuSo, mauSo;

public:
    // Constructor
    PhanSo();
    PhanSo(int, int);
    // Getter, Setter
    int getTuSo();  
    int getMauSo();
    //----------------------
    void nhap();
    void xuat();
    int ucln(int, int);
    void toiGian();

    // Operator
    PhanSo operator+(const PhanSo&);
    PhanSo operator-(const PhanSo&);
    PhanSo operator*(const PhanSo&);
    PhanSo operator/(const PhanSo&);
};

void menu();