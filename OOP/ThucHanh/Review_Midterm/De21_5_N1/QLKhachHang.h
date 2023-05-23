#pragma once
#include "KhachHang.h"
#include "KHNuocNgoai.h"
#include "KHVietNam.h"
#include<fstream>

class QLKhachHang {
private:
	KhachHang** ds;
	int n;
public:
	QLKhachHang();
	~QLKhachHang();
	void nhapDS();
	void xuatDS();
	void tinhTongKhachHang();
	void timHoaDonMax();
	void xuatHoaDonThang03();
	void docFile();
};