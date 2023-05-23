#include "KhachHang.h"

KhachHang::KhachHang() {
	maKH = new char[7];
	hoTen = new char[31];
    ngayHoaDon = new char[20];
    soLuong = donGia = 0.0;
}
KhachHang::KhachHang(char* _maKH, char* _hoTen, char* _ngayHoaDon, double _soLuong, double _donGia) {
    maKH = new char[7];
    hoTen = new char[31];
    ngayHoaDon = new char[20];
    strcpy(maKH, _maKH);
    strcpy(hoTen, _hoTen);
    strcpy(ngayHoaDon, _ngayHoaDon);
    soLuong = _soLuong;
    donGia = _donGia;
}

KhachHang::~KhachHang() {
	delete[] maKH;
	delete[] hoTen;
    delete[] ngayHoaDon;
}

void KhachHang::nhap() {
    cout << "Nhap ma khach hang: ";
    cin >> maKH;
    cout << "Nhap ho ten: ";
    cin.ignore();
    cin.getline(hoTen, 30);
    cout << "Nhap ngay ra hoa don (dd mm yyyy): ";
    cin.getline(ngayHoaDon, 20);
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cout << "Nhap don gia: ";
    cin >> donGia;
}
void KhachHang::xuat() {
    cout << "Ma khach hang: " << maKH << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay ra hoa don: " << ngayHoaDon << endl;
    cout << "So luong: " << soLuong << endl;
    cout << "Don gia: " << donGia << endl;
}
double KhachHang::tinhThanhTien() {
    return 0;
}

char* KhachHang::getNgayHoaDon() {
    return ngayHoaDon;
}

char* KhachHang::getMaKH() {
    return maKH;
}
char* KhachHang::getHoTen() {
    return hoTen;
}
double KhachHang::getSoLuong() {
    return soLuong;
}
double KhachHang::getDonGia() {
    return donGia;
}