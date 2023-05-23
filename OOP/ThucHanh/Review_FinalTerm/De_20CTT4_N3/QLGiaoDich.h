#ifndef QLGIAODICH_H
#define QLGIAODICH_H

#include "GiaoDich.h"
#include "GDVang.h"
#include "GDTienTe.h"

class QLGiaoDich : public GiaoDich
{
private: 
	int sz;
	GiaoDich** dsGiaoDich;
public:
	QLGiaoDich();
	~QLGiaoDich();
	void nhapDS();
	void xuatDS();
	void tinhTrungBinhThanhTien();
};


#endif // !QLGIAODICH_H



