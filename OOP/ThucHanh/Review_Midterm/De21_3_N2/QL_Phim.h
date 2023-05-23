#pragma once
#include "Phim.h"
#include<iostream>
#include<cstring>
using namespace std;

class QL_Phim {
private:
	int sz;
	Phim* ds_phim;
public:
	QL_Phim();
	~QL_Phim();

	void nhap_dsPhim();
	void xuat_dsPhim();

	Phim* timPhimXepHangCaoNhatTheoTheLoai(char* theLoai);
	void xepHangCaoNhatTheoTheLoai();
	void xoaPhimHBOTruocNam2000();
};
