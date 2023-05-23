#include "ChuyenXeNoiThanh.h"

void ChuyenXeNoiThanh::Nhap() {
    ChuyenXe::Nhap();
    cout << "Nhap so tuyen: ";
    cin >> soTuyen;
    cout << "Nhap so km di duoc: ";
    cin >> soKm;
}

void ChuyenXeNoiThanh::Xuat() {
    ChuyenXe::Xuat();
    cout << "So tuyen: " << soTuyen << endl;
    cout << "So km di duoc: " << soKm << endl;
}

int ChuyenXeNoiThanh::TinhDoanhThu() {
    return doanhThu;
}