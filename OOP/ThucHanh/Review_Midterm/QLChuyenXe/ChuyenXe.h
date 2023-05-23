#pragma once
#include<iostream>
#include<string>
using namespace std;

class ChuyenXe {
protected:
    string maSo;
    string hoTenTaiXe;
    string soXe;
    int doanhThu;
public:
    ChuyenXe() {};
    ChuyenXe(string ms, string ht, string sx, int dt) {
        maSo = ms;
        hoTenTaiXe = ht;
        soXe = sx;
        doanhThu = dt;
    }
    virtual void Nhap();
    virtual void Xuat();
    virtual int TinhDoanhThu() = 0;
};
