#pragma once
#include "ChuyenXe.h"
class ChuyenXeNoiThanh : public ChuyenXe {
private:
    int soTuyen;
    int soKm;
public:
    ChuyenXeNoiThanh() : ChuyenXe() {};
    ChuyenXeNoiThanh(string ms, string ht, string sx, int dt, int st, int sk) : ChuyenXe(ms, ht, sx, dt) {
        soTuyen = st;
        soKm = sk;
    }
    void Nhap();
    void Xuat();
    int TinhDoanhThu();
};
