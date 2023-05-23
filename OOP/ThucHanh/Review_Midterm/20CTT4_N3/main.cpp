#include "GiaoDich.h"
#include "GDNha.h"
#include "GDDat.h"
#include "QLGiaoDich.h"
#include<iostream>
using namespace std;

int main() {
	QLGiaoDich ds;
	ds.nhapDS();
	ds.xuatDS();
	ds.tinhTrungBinhThanhTienDat();

	GiaoDich* gdLonNhat = ds.timGiaoDichLonNhat();
	if (gdLonNhat == nullptr) {
		cout << "Danh sach giao dich rong!";
	}
	else {
		cout << "\nThong tin giao dich lon nhat:\n";
		gdLonNhat->xuat();
	}

	cout << "\nGiao dich thang 1 nam 2022: " << endl;
	ds.xuatGiaoDichThang1Nam2022();
}