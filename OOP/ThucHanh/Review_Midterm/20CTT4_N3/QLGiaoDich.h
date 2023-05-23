#pragma once
#include "GiaoDich.h"
#include <vector>

class QLGiaoDich {
private:
	vector<GiaoDich*>ds;
public:
	void nhapDS();
	void xuatDS();
	void tinhTrungBinhThanhTienDat();
	void timGiaoDichCoSoTienLonNhat();

	GiaoDich* timGiaoDichLonNhat();
	void xuatGiaoDichThang1Nam2022();

};