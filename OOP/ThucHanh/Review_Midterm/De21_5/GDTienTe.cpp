#include "GDTienTe.h"

GDTienTe::GDTienTe() {
	loaiTien = 0;
	tiGia = 0.0;
}
//GDTienTe::GDTienTe(const GDTienTe& gdtt) {
//	loaiTien = gdtt.loaiTien;
//	tiGia = gdtt.tiGia;
//}

GDTienTe::GDTienTe(char* _maGD, char* _ngayGD, double _donGia, int _soLuong, int _loaiTien, double _tiGia) : GiaoDich(_maGD, _ngayGD, _donGia, _soLuong) {
    loaiTien = _loaiTien;
    tiGia = _tiGia;
}

void GDTienTe::nhap() {
	GiaoDich::nhap();
	cout << "Loai tien te (1: VND, 2: USD, 3: Euro): ";
	cin >> loaiTien;
	cout << "Ti gia: ";
	cin >> tiGia;
}
void GDTienTe::xuat() {
    GiaoDich::xuat();
    cout << "Loai tien te: ";
    switch (loaiTien) {
    case 1:
        cout << "VND";
        break;
    case 2:
        cout << "USD";
        break;
    case 3:
        cout << "Euro";
        break;
    default:
        cout << "Khong xac dinh";
        break;
    }
    cout << endl;
    cout << "Ti gia: " << tiGia << endl;
}
double GDTienTe::thanhTien() {
    double thanhTien = 0;
    switch (loaiTien) {
    case 1:
        thanhTien = soLuong * donGia;
        break;
    case 2:
    case 3:
        thanhTien = soLuong * donGia * tiGia;
        break;
    default:
        break;
    }
    return thanhTien;
}
int GDTienTe::getLoaiTien() {
    return loaiTien;
}