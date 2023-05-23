#include "ChuyenXe.h"

void ChuyenXe::Nhap() {
    cout << "Nhap ma so: ";
    cin >> maSo;
    cout << "Nhap ho ten tai xe: ";
    cin.ignore();
    getline(cin, hoTenTaiXe);
    cout << "Nhap so xe: ";
    cin >> soXe;
    cout << "Nhap doanh thu: ";
    cin >> doanhThu;
}

void ChuyenXe::Xuat() {
    cout << "Ma so chuyen xe: " << maSo << endl;
    cout << "Ho ten tai xe: " << hoTenTaiXe << endl;
    cout << "So xe: " << soXe << endl;
    cout << "Doanh thu: " << doanhThu << endl;
}