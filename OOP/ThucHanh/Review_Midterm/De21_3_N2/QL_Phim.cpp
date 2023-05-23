#include "QL_Phim.h"
#include "Phim.h"
QL_Phim::QL_Phim() {
	sz = 0;
	ds_phim = NULL;
}

QL_Phim::~QL_Phim() {
	delete[] ds_phim;
	ds_phim = NULL;
}

void QL_Phim::nhap_dsPhim() {
	cout << "\nNhap so luong phim: ";
	cin >> sz;
	ds_phim = new Phim[sz];
	for (int i = 0; i < sz; i++) {
		cout << "\n\n\t NHAP THONG TIN PHIM THU " << i + 1 << endl;
		ds_phim[i].Nhap();
	}
}
void QL_Phim::xuat_dsPhim() {
	for (int i = 0; i < sz; i++) {
		cout << "\n\n\t THONG TIN PHIM THU " << i + 1 << endl;
		ds_phim[i].Xuat();
	}
}


Phim* QL_Phim::timPhimXepHangCaoNhatTheoTheLoai(char* theLoai) {
	float max_xepHang = 0;
	Phim* phimMaxXepHang = nullptr;
	for (int i = 0; i < sz; i++) {
		if (strcmp(ds_phim[i].getTheLoai(), theLoai) == 0 && ds_phim[i].getXepHang() > max_xepHang) {
			max_xepHang = ds_phim[i].getXepHang();
			phimMaxXepHang = &ds_phim[i];
		}
	}
	return phimMaxXepHang;
}

void QL_Phim::xepHangCaoNhatTheoTheLoai() {
	char theLoai[20];
	cout << "Nhap the loai phim: ";
	cin.ignore();
	cin.getline(theLoai, 20);

	Phim* phimMaxXepHang = timPhimXepHangCaoNhatTheoTheLoai(theLoai);
	if (phimMaxXepHang != nullptr) {
		cout << "Phim co xep hang cao nhat theo the loai " << theLoai << " la: \n";
		phimMaxXepHang->Xuat();
	}
	else {
		cout << "Khong tim thay phim thuoc the loai " << theLoai << endl;
	}

}

void QL_Phim::xoaPhimHBOTruocNam2000() {
	int count = 0;
	Phim* ds_xoa = new Phim[sz]; // Tạo mảng để lưu các phim cần xóa
	// Tìm các phim có nhà sản xuất là HBO và năm sản xuất trước năm 2000
	for (int i = 0; i < sz; i++) {
		if (strcmp(ds_phim[i].getNhaSX(), "HBO") == 0 && ds_phim[i].getNamSX() < 2000) {
			ds_xoa[count] = ds_phim[i];
			count++;
		}
	}
	// Xóa các phim đã tìm được
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < sz; j++) {
			if (ds_xoa[i] == ds_phim[j]) {
				for (int k = j; k < sz - 1; k++) {
					ds_phim[k] = ds_phim[k + 1];
				}
				sz--;
				break;
			}
		}
	}
	// Xuất ra danh sách sau khi xóa
	xuat_dsPhim();
	delete[] ds_xoa; // Giải phóng bộ nhớ đã cấp phát cho mảng ds_xoa
}

