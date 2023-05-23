#include "NVSanXuat.h"

NVSanXuat::NVSanXuat() : NhanVien() {
    soSanPham = 0;
}

void NVSanXuat::nhap() {
    NhanVien::nhap();
    do {
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        if (soSanPham < 10 || soSanPham > 15) {
            cout << "So san pham phai tu 10 den 15 san pham!" << endl;
        }
    } while (soSanPham < 10 || soSanPham > 15);
}

void NVSanXuat::xuat() {
    NhanVien::xuat();
    cout << "So san pham: " << soSanPham << endl;
    cout << "Luong: " << fixed << setprecision(0) << tinhLuong() << endl;
}

double NVSanXuat::tinhLuong() {
    return soSanPham * 50000;
}

int NVSanXuat::getSoSanPham() {
    return soSanPham;
}

void NVSanXuat::setSoSanPham(int soSP) {
    soSanPham = soSP;
}

//void NVSanXuat::ghi(ofstream& file) const {
//    NhanVien::ghi(file);
//    file.write(reinterpret_cast<const char*>(&soSanPham), sizeof(soSanPham));
//}
//
//void NVSanXuat::doc(ifstream& file) {
//    NhanVien::doc(file);
//    file.read(reinterpret_cast<char*>(&soSanPham), sizeof(soSanPham));
//}


void NVSanXuat::ghi(ofstream& file) {
    NhanVien::ghi(file);
    // Ghi các thuộc tính riêng của NVSanXuat vào file
    file.write(reinterpret_cast<char*>(this), sizeof(NVSanXuat));
}

void NVSanXuat::doc(ifstream& file) {
    NhanVien::doc(file);
    // Đọc các thuộc tính riêng của NVSanXuat từ file
    file.read(reinterpret_cast<char*>(this), sizeof(NVSanXuat));
}


NVSanXuat& NVSanXuat::operator=(const NVSanXuat& other) {
    if (this != &other) {
        NhanVien::operator=(other);
        soSanPham = other.soSanPham;
    }
    return *this;
}
