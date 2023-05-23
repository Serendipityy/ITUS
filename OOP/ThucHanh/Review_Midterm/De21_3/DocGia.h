#pragma warning(disable : 4996)
#pragma once
#include<iostream>
#include<cstring>
#include<iomanip>
#include<conio.h>
using namespace std;
class DocGia {
private:
	char* MaDG;
	char* HoTen;
	char* NgayExpire;
	int SachMuon;
	char* LoaiDG;
public:
	// Constructors
	DocGia();
	//DocGia(char* _maDG, char* _hoTen, char* _ngayExpire, int _sachMuon, char* _loaiDG);
	DocGia(const DocGia& dg);
	// Destructor
	~DocGia();
	void Nhap();
	void Xuat();
	float TinhPhi();

	// Them
	bool kiemTraHetHan(string ngayCanKiemTra);

	char* getMaDG() {
		return MaDG;
	}
};