#include "KhachHang.h"
#include"KHNuocNgoai.h"
#include "KHVietNam.h"
#include "QLKhachHang.h"

int main() {

	QLKhachHang ds;
	ds.nhapDS();
	ds.xuatDS();
	ds.tinhTongKhachHang();
	ds.timHoaDonMax();
	ds.xuatHoaDonThang03();
	

	ds.docFile();
}	
