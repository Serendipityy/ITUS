#pragma once
#include "PhanSo.h"
// Class MangPS
class MangPS {
    PhanSo* ds;
    int size;

public:
    MangPS();
    ~MangPS();
    void nhapDS();
    void xuatDS();

    PhanSo tong();
    void sapXep();
    void ghiFile();
    void docFile();
};

