#pragma once
#include "ChuyenXe.h"

class ChuyenXeNgoaiThanh : public ChuyenXe {
private:
    string noiDen;
    int soNgay;
public:
    ChuyenXeNgoaiThanh() : ChuyenXe() {};
    ChuyenXeNgoaiThanh(string ms, string ht, string sx, int dt, string nd, int sn) : ChuyenXe(ms, ht, sx, dt) {
        noiDen = nd;
        soNgay = sn;
    }
    void Nhap();
    void Xuat();
    int TinhDoanhThu();
};
