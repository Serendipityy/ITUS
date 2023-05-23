#ifndef NVCONGNHAT_H
#define NVCONGNHAT_H

#pragma warning(disable: 4996)
#pragma once

#include "NhanVien.h"

class NVCongNhat : public NhanVien {
private:
    double soNgayLam;

public:
    NVCongNhat();
    void nhap() override;
    void xuat() override;
    double tinhLuong() override;

    double getSoNgayLam();
    void setSoNgayLam(double soNgay);
    void ghi(ofstream& file);
    void doc(ifstream& file);
    NVCongNhat& operator=(const NVCongNhat& other);
};

#endif 

