#include "Phim.h"
#include "QL_Phim.h"
int main() {
	QL_Phim ds;
	ds.nhap_dsPhim();
	ds.xuat_dsPhim();
	ds.xepHangCaoNhatTheoTheLoai();
	cout << "Xoa danh sach truoc 2000:";
	ds.xoaPhimHBOTruocNam2000();
}