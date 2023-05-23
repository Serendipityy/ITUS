#include"KhachHang.h"
#include "KHNuocNgoai.h"

KHNuocNgoai::KHNuocNgoai() : KhachHang() {
	quocTich = new char[20];
}

KHNuocNgoai::KHNuocNgoai(char* _maKH, char* _hoTen, char* _ngayHoaDon, double _soLuong, double _donGia, char* _quocTich)
	:KhachHang(_maKH, _hoTen, _ngayHoaDon, _soLuong, _donGia) {
	quocTich = new char[20];
	strcpy(quocTich, _quocTich);
}
void KHNuocNgoai::nhap() {
	KhachHang::nhap();
	cout << "Nhap quoc tich: ";
	cin.ignore();
	cin.getline(quocTich, 20);

}
void KHNuocNgoai::xuat() {
	KhachHang::xuat();
	cout << "Quoc tich: " << quocTich << endl;
	cout << "Thanh tien: " << tinhThanhTien() << endl;
}
double KHNuocNgoai::tinhThanhTien() {
	return soLuong * donGia;
}