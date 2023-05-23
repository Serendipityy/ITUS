#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<iomanip>
#include<sstream>

using namespace std;

class NhanVien {
protected:
    string maNV;
    string hoTen;
    string ngaySinh;
    string diaChi;
public:
    NhanVien();
    NhanVien(string ma, string ten, string ngay, string diaChi);
    virtual void nhapThongTin();
    virtual void xuatThongTin();
    virtual double tinhLuong() = 0;
    string getMaNV();
    string getTenNV();
    string getNgaySinh();
};

class NVSanXuat : public NhanVien {
private:
    int soSanPham;
public:
    NVSanXuat();
    NVSanXuat(string ma, string ten, string ngay, string diaChi, int soSP);
    void nhapThongTin();
    void xuatThongTin();
    double tinhLuong();
};

class NVCongNhat : public NhanVien {
private:
    int soNgay;
public:
    NVCongNhat();
    NVCongNhat(string ma, string ten, string ngay, string diaChi, int soNgay);
    void nhapThongTin();
    void xuatThongTin();
    double tinhLuong();
};

class CongTy {
private:
    vector<NhanVien*> danhSachNV;
public:
    CongTy();
    CongTy(const CongTy& ct);
    CongTy& operator=(const CongTy& ct);
    void docNV(string fileName);
    void nhap();
    void xuat();
    double tinhTongLuongNV();
    NhanVien* timNhanVienLuongCaoNhat();
    double tinhLuongTrungBinh();
    void timNhanVienTheoMa();
    void timNhanVienTheoTen();
    void demNVThang5();
    void themNhanVien();
    void xoaNhanVien(string maNV);
    void ghiNV_LowerAvgSalary();
    ~CongTy();
};
