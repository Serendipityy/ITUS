#ifndef NHANVIEN_H
#define NHANVIEN_H

#pragma warning(disable: 4996)
#pragma once

#include "NgaySinh.h"

class NhanVien {
protected:
    char maNV[6];
    char hoTen[51];
    char diaChi[101];
    bool gioiTinh;
    NgaySinh ngaySinh;

public:
    NhanVien();
    virtual void nhap();
    virtual void xuat();
    virtual double tinhLuong();

    void ghiNhanVien(ofstream& ofs) const;
    void docNhanVien(ifstream& ifs);
    char* getMaNV();
    char* getHoTen();
    NgaySinh getNgaySinh();
    virtual void ghi(ofstream& file);
    virtual void doc(ifstream& file);
    NhanVien& operator=(const NhanVien& other);


};

#endif