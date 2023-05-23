#include "ChuyenXeNgoaiThanh.h"
#include "ChuyenXe.h"
void ChuyenXeNgoaiThanh::Nhap() {
    ChuyenXe::Nhap();
    cout << "Nhap noi den: ";
    cin.ignore();
    getline(cin, noiDen);
    cout << "Nhap so ngay di duoc: ";
    cin >> soNgay;
}

void ChuyenXeNgoaiThanh::Xuat() {
    ChuyenXe::Xuat();
    cout << "Noi den: " << noiDen << endl;
    cout << "So ngay di duoc: " << soNgay << endl;
}

int ChuyenXeNgoaiThanh::TinhDoanhThu() {
    return doanhThu;
}
