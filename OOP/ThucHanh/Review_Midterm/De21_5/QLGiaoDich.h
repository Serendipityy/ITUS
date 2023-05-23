#pragma once
#include "GiaoDich.h"

class QLGiaoDich {
private:
	GiaoDich** ds;
	int n; // so luong
public:
	QLGiaoDich();
	~QLGiaoDich();
	void nhapDS();
	void xuatDS();
	void TongSoLuongTungLoaiGD();
	void timGiaoDichTienTeMax();
	void xuatGiaoDichThang01();
	void xuatHoaDonThang03();

}; 