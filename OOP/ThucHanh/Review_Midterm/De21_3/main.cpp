#include "DocGia.h"
#include "QLThuVien.h"
int main() {

	QLThuVien ds;
	ds.NhapDSDG();
	ds.XuatDSDG();
	cout<<"\nTong tien: "<<fixed<<setprecision(0) << ds.tinhTongTien();

	ds.lietKeDocGiaHetHan();
}