#ifndef NVSANXUAT_H
#define NVSANXUAT_H

#pragma warning(disable: 4996)
#pragma once

#include "NhanVien.h"

class NVSanXuat : public NhanVien {
private:
    int soSanPham;

public:
    NVSanXuat();
    void nhap() override;
    void xuat() override;
    double tinhLuong() override;

    int getSoSanPham();
    void setSoSanPham(int _soSP);
    void ghi(ofstream& file);

    void doc(ifstream& file);
    NVSanXuat& operator=(const NVSanXuat& other);

};

#endif 