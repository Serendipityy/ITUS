#pragma once
#include "DocGia.h"
#include<iostream>
#include<cstring>
#include<iomanip>
#include<conio.h>
using namespace std;

class QLThuVien {
private:
	int size;
	DocGia* dsdg;
public:
	// Constructors
	QLThuVien();
	QLThuVien(int n);
	// Destructor
	~QLThuVien();
	
	void NhapDSDG();
	void XuatDSDG();
	float tinhTongTien();
	void lietKeDocGiaHetHan();
	void themDocGia();
	void themDocGia(DocGia dg);
};