
#include "QLGiaoDich.h"

QLGiaoDich::QLGiaoDich() {
	dsGiaoDich = nullptr;
	sz = 0;
}

QLGiaoDich::~QLGiaoDich() {
	if (dsGiaoDich != nullptr) {
		for (int i = 0; i < sz; i++) {
			delete dsGiaoDich[i];
		}
		delete[] dsGiaoDich;
	}
}

void QLGiaoDich::nhapDS() {
	cout << "Nhap so luong giao dich: ";
	cin >> sz;
	dsGiaoDich = new GiaoDich * [sz];
	for (int i = 0; i < sz; i++) {
		cout << "\n\n\tNHAP GIAO DICH THU " << i + 1 << endl;
		int loaiGD;
		cout << "Nhap loai giao dich (1: Vang, 2: Tien te): ";
		cin >> loaiGD;
		if (loaiGD == 1) {
			dsGiaoDich[i] = new GDVang();
		}
		else if (loaiGD == 2) {
			dsGiaoDich[i] = new GDTienTe();
		}
		else {
			cout << "Loai giao dich khong hop le!" << endl;
			i--;
			continue;
		}
		dsGiaoDich[i]->nhap();
	}
}

void QLGiaoDich::xuatDS() {
	for (int i = 0; i < sz; i++) {
		cout << "\n\n\tGIAO DICH THU " << i + 1 << endl;
		dsGiaoDich[i]->xuat();
	}
}
//
//void QLKhachHang::tinhTongKhachHang() {
//	int countVietNam = 0;
//	int countNuocNgoai = 0;
//
//	for (int i = 0; i < n; i++) {
//		if (dynamic_cast<KHVietNam*>(ds[i])) {
//			countVietNam++;
//		}
//		else if (dynamic_cast<KHNuocNgoai*>(ds[i])) {
//			countNuocNgoai++;
//		}
//	}
//
//	cout << "Tong so luong khach hang Viet Nam: " << countVietNam << endl;
//	cout << "Tong so luong khach hang Nuoc Ngoai: " << countNuocNgoai << endl;
//}

void QLGiaoDich::tinhTrungBinhThanhTien() {
	int countVang = 0;
	double tongThanhTienVang = 0;
	int countTienTe = 0;
	double tongThanhTienTienTe = 0;

	for (int i = 0; i < sz; i++) {
		if (dynamic_cast<GDVang*>(dsGiaoDich[i]) != nullptr) {
			tongThanhTienVang += dsGiaoDich[i]->tinhThanhTien();
			countVang++;
		}
		else if (dynamic_cast<GDTienTe*>(dsGiaoDich[i]) != nullptr) {
			tongThanhTienTienTe += dsGiaoDich[i]->tinhThanhTien();
			countTienTe++;
		}
	}

	double trungBinhVang = (countVang > 0) ? (tongThanhTienVang / countVang) : 0;
	double trungBinhTienTe = (countTienTe > 0) ? (tongThanhTienTienTe / countTienTe) : 0;

	cout << endl;
	cout << "Trung binh thanh tien cua giao dich Vang: " << trungBinhVang << endl;
	cout << "Trung binh thanh tien cua giao dich Tien te: " << trungBinhTienTe << endl;

}
