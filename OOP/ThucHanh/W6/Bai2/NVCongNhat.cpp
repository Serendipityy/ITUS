#include "NVCongNhat.h"

NVCongNhat::NVCongNhat() : NhanVien() {
    soNgayLam = 0;
}

void NVCongNhat::nhap() {
    NhanVien::nhap();
    do {
        cout << "Nhap so ngay lam: ";
        cin >> soNgayLam;
        if (soNgayLam < 22 || soNgayLam > 26) {
            cout << "So ngay lam phai tu 22 den 26 ngay!" << endl;
        }
    } while (soNgayLam < 22 || soNgayLam > 26);
}

void NVCongNhat::xuat() {
    NhanVien::xuat();
    cout << "So ngay lam: " << soNgayLam << endl;
    cout << "Luong: " << fixed << setprecision(0) << tinhLuong() << endl;
}


double NVCongNhat::tinhLuong() {
    return soNgayLam * 500000;
}

double NVCongNhat::getSoNgayLam() {
    return soNgayLam;
}

void NVCongNhat::setSoNgayLam(double soNgay) {
    soNgayLam = soNgay;
}

//void NVCongNhat::ghi(ofstream& file) const {
//    NhanVien::ghi(file);
//    file.write(reinterpret_cast<const char*>(&soNgayLam), sizeof(soNgayLam));
//}
//
//void NVCongNhat::doc(ifstream& file) {
//    NhanVien::doc(file);
//    file.read(reinterpret_cast<char*>(&soNgayLam), sizeof(soNgayLam));
//}

void NVCongNhat::ghi(ofstream& file) {
    NhanVien::ghi(file);
    // Ghi các thuộc tính riêng của NVCongNhat vào file
    file.write(reinterpret_cast<char*>(this), sizeof(NVCongNhat));
}

void NVCongNhat::doc(ifstream& file) {
    NhanVien::doc(file);
    // Đọc các thuộc tính riêng của NVCongNhat từ file
    file.read(reinterpret_cast<char*>(this), sizeof(NVCongNhat));
}

NVCongNhat& NVCongNhat::operator=(const NVCongNhat& other) {
    if (this != &other) {
        NhanVien::operator=(other);
        soNgayLam = other.soNgayLam;
    }
    return *this;
}
