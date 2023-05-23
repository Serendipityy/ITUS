#include "GiaoDich.h"
#include "GDNha.h"

GDNha::GDNha() : GiaoDich() {
	loaiNha = "";
	diaChi = "";

}
GDNha::GDNha(string _maGD, int _ngay, int _thang, int _nam, double _donGia, double _dienTich, string _loaiNha, string _diaChi)
	: GiaoDich(_maGD, _ngay, _thang, _nam, _donGia, _dienTich) {
	loaiNha = _loaiNha;
	diaChi = _diaChi;

}
void GDNha::nhap() {
	GiaoDich::nhap();
	cin.ignore();
	cout << "Nhap loai nha (cao cap / thuong): ";
	getline(cin, loaiNha);
	cout << "Nhap dia chi: ";
	getline(cin, diaChi);
}

double GDNha::tinhThanhTien() {
	if (loaiNha == "cao cap") {
		return dienTich * donGia;
	}
	else if (loaiNha == "thuong") {
		return dienTich * donGia * 0.9;
	}
}
void GDNha::xuat() {
	GiaoDich::xuat();
	cout << "Loai nha: " << loaiNha << endl;
	cout << "Dia chi: " << diaChi << endl;
	cout << "Thanh tien: " << tinhThanhTien() << endl;
}

