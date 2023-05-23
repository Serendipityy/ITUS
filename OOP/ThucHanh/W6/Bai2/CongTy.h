#ifndef CONGTY_H
#define CONGTY_H

#pragma warning(disable: 4996)
#pragma once

#include "NVSanXuat.h"
#include "NVCongNhat.h"

class CongTy {
private:
    vector<NhanVien*> danhSachNV;

public:
    CongTy();
    ~CongTy();
    void themNhanVien(NhanVien* nv);
    void nhapDanhSachNV();
    void ghiDanhSachNV();
    void docDanhSachNV();

    void xuatDanhSachNV();

    double tinhTongLuong();
    void timNhanVienLuongCaoNhat();

    double tinhLuongTrungBinh();

    void timNhanVienTheoMa();

    void timNhanVienTheoTen();
    void demNhanVienSinhThang5();
    void themNhanVienVaoDanhSach();
    void xoaNhanVienKhoiDanhSach();
    void ghiDanhSachNhanVienLuongThap();
};
#endif 