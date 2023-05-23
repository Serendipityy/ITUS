#include "QLGiaoDich.h"
#include "GDVang.h"
#include "GDTienTe.h"
#include "GiaoDich.h"

QLGiaoDich::QLGiaoDich() {
	ds = NULL;
	n = 0;
}
QLGiaoDich::~QLGiaoDich() {
	if (ds != NULL) {
		for (int i = 0; i < n; i++) {
			delete ds[i];
		}
		delete[] ds;
	}
}
void QLGiaoDich::nhapDS() {
	cout << "Nhap so luong giao dich: ";
	cin >> n;
	ds = new GiaoDich * [n];
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t NHAP GIAO DICH THU " << i + 1 << endl;
		int loaiGD;
		cout << "Nhap loai giao dich (1: Vang, 2: Tien te): ";
		cin >> loaiGD;
		if (loaiGD == 1) {
			ds[i] = new GDVang();
		}
		else if (loaiGD == 2) {
			ds[i] = new GDTienTe();
		}
		else {
			cout << "Loai giao dich khong hop le!" << endl;
			i--;
			continue;
		}
		ds[i]->nhap();
	}
}
void QLGiaoDich::xuatDS() {
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t GIAO DICH THU " << i + 1 << endl;
		ds[i]->xuat();
		cout << "\nThanh tien: " << ds[i]->thanhTien();
	}
}
void QLGiaoDich::TongSoLuongTungLoaiGD()
{
	int tongSoLuongVang = 0;
	int tongSoLuongUSD = 0;
	int tongSoLuongEUR = 0;
	int tongSoLuongVND = 0;

	for (int i = 0; i < n; i++) {
		if (dynamic_cast<GDVang*>(ds[i])) {
			tongSoLuongVang += ds[i]->getSoLuong();
		}
		else if (dynamic_cast<GDTienTe*>(ds[i])) {
			int loaiTienTe = dynamic_cast<GDTienTe*>(ds[i])->getLoaiTien();
			switch (loaiTienTe) {
			case 1: tongSoLuongVND += ds[i]->getSoLuong(); break;
			case 2: tongSoLuongUSD += ds[i]->getSoLuong(); break;
			case 3: tongSoLuongEUR += ds[i]->getSoLuong(); break;
			}
		}
	}
	cout << "\n\n\t THONG KE SO LUONG GIAO DICH" << endl;
	cout << "Tong so luong giao dich vang: " << tongSoLuongVang << endl;
	cout << "Tong so luong giao dich tien USD: " << tongSoLuongUSD << endl;
	cout << "Tong so luong giao dich tien Euro: " << tongSoLuongEUR << endl;
	cout << "Tong so luong giao dich tien VN: " << tongSoLuongVND << endl;
}

void QLGiaoDich::timGiaoDichTienTeMax() {
	double maxVnd = 0;
	double maxUsd = 0;
	double maxEuro = 0;
	GDTienTe* maxGdVnd = nullptr;
	GDTienTe* maxGdUsd = nullptr;
	GDTienTe* maxGdEuro = nullptr;

	// Duyệt qua danh sách giao dịch
	for (int i = 0; i < n; i++) {
		GDTienTe* gdTienTe = dynamic_cast<GDTienTe*>(ds[i]); // Ép kiểu động về GDTienTe
		if (gdTienTe) { // Nếu là giao dịch tiền tệ
			double thanhTien = gdTienTe->thanhTien();
			if (gdTienTe->getLoaiTien() == 1) { // Loại tiền VND
				if (thanhTien > maxVnd) {
					maxVnd = thanhTien;
					maxGdVnd = gdTienTe;
				}
			}
			else if (gdTienTe->getLoaiTien() == 2) { // Loại tiền USD
				if (thanhTien > maxUsd) {
					maxUsd = thanhTien;
					maxGdUsd = gdTienTe;
				}
			}
			else if (gdTienTe->getLoaiTien() == 3) { // Loại tiền Euro
				if (thanhTien > maxEuro) {
					maxEuro = thanhTien;
					maxGdEuro = gdTienTe;
				}
			}
		}
	}

	// Xuất thông tin giao dịch có số tiền lớn nhất cho từng loại tiền
	if (maxGdVnd) {
		cout << "Giao dich VND co so tien lon nhat la: " << endl;
		maxGdVnd->xuat();
	}
	if (maxGdUsd) {
		cout << "Giao dich USD co so tien lon nhat la: " << endl;
		maxGdUsd->xuat();
	}
	if (maxGdEuro) {
		cout << "Giao dich Euro co so tien lon nhat la: " << endl;
		maxGdEuro->xuat();
	}
}

bool checkDate(char* ngayGD) {
	int ngay, thang, nam;
	sscanf(ngayGD, "%d/%d/%d", &ngay, &thang, &nam);
	if (thang == 3 && nam == 2021) {
		return true;
	}
	return false;
}

void QLGiaoDich::xuatGiaoDichThang01() {
	cout << "\nCac giao dich trong thang 03 nam 2021:" << endl;
	for (int i = 0; i < n; i++) {
		if (checkDate(ds[i]->getNgayGD())) {
			ds[i]->xuat();
			cout << "Thanh tien: " << ds[i]->thanhTien() << endl;
		}
	}
}

