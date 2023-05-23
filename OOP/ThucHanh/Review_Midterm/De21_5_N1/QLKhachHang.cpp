#include "QLKhachHang.h"
#include "KHVietNam.h"
#include "KHNuocNgoai.h"


QLKhachHang::QLKhachHang() {
	ds = NULL;
	n = 0;
}
QLKhachHang::~QLKhachHang() {
	delete[] ds;
	ds = NULL;
}
void QLKhachHang::nhapDS() {
	cout << "Nhap so luong khach hang: ";
	cin >> n;
	ds = new KhachHang * [n];
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t NHAP KHACH HANG THU " << i + 1 << endl;
		int loaiGD;
		cout << "Nhap loai khach hang (1: Viet Nam, 2: Nuoc Ngoai): ";
		cin >> loaiGD;
		if (loaiGD == 1) {
			ds[i] = new KHVietNam();
		}
		else if (loaiGD == 2) {
			ds[i] = new KHNuocNgoai();
		}
		else {
			cout << "Loai khach hang khong hop le!" << endl;
			i--;
			continue;
		}
		ds[i]->nhap();
	}
}
void QLKhachHang::xuatDS() {
	for (int i = 0; i < n; i++) {
		cout << "\n\n\tKHACH HANG THU " << i + 1 << endl;
		ds[i]->xuat();
	}
}
void QLKhachHang::tinhTongKhachHang() {
	int countVietNam = 0;
	int countNuocNgoai = 0;

	for (int i = 0; i < n; i++) {
		if (dynamic_cast<KHVietNam*>(ds[i])) {
			countVietNam++;
		}
		else if (dynamic_cast<KHNuocNgoai*>(ds[i])) {
			countNuocNgoai++;
		}
	}

	cout << "Tong so luong khach hang Viet Nam: " << countVietNam << endl;
	cout << "Tong so luong khach hang Nuoc Ngoai: " << countNuocNgoai << endl;
}


void QLKhachHang::timHoaDonMax() {
	double maxSinhHoat = 0;
	double maxKinhDoanh = 0;
	double maxSanXuat = 0;
	KHVietNam* maxKHSH = nullptr;
	KHVietNam* maxKHKD = nullptr;
	KHVietNam* maxKHSX = nullptr;

	for (int i = 0; i < n; i++) {
		KHVietNam* khVN = dynamic_cast<KHVietNam*>(ds[i]); // Ép kiểu động về GDTienTe
		if (khVN) { 
			double thanhTien = khVN->tinhThanhTien();
			if (strcmp(khVN->getDoiTuong(), "sinh hoat") == 0) { // Loại tiền VND
				if (thanhTien > maxSinhHoat) {
					maxSinhHoat = thanhTien;
					maxKHSH = khVN;
				}
			}
			else if (strcmp(khVN->getDoiTuong(), "kinh doanh") == 0) { // Loại tiền USD
				if (thanhTien > maxKinhDoanh) {
					maxKinhDoanh = thanhTien;
					maxKHKD = khVN;
				}
			}
			else if (strcmp(khVN->getDoiTuong(), "san xuat") == 0) { // Loại tiền Euro
				if (thanhTien > maxSanXuat) {
					maxSanXuat = thanhTien;
					maxKHSX = khVN;
				}
			}
		}
	}

	if (maxKHSH) {
		cout << "Khach hang sinh hoat co hoa don tien lon nhat la: " << endl;
		maxKHSH->xuat();
	}
	if (maxKHKD) {
		cout << "Khach hang kinh doanh co hoa don tien lon nhat la: " << endl;
		maxKHKD->xuat();
	}
	if (maxKHSX) {
		cout << "Khach hang san xuat co hoa don tien lon nhat la: " << endl;
		maxKHSX->xuat();
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

//void QLKhachHang::xuatHoaDonThang03() {
//	cout << "Cac giao dich trong thang 03 nam 2021:" << endl;
//	for (int i = 0; i < n; i++) {
//		KHVietNam* khVN = dynamic_cast<KHVietNam*>(ds[i]); // Ép kiểu động về KHVietNam
//		if (khVN && checkDate(khVN->getNgayHoaDon())) {
//			khVN->xuat();
//		}
//	}
//}

void QLKhachHang::xuatHoaDonThang03() {
	ofstream fout("HoaDonThang3.txt");
	if (!fout.is_open()) {
		cout << "Loi mo file!" << endl;
		return;
	}
	fout << "Danh sach hoa don thang 03 nam 2021 cua khach hang Viet Nam:\n\n";
	for (int i = 0; i < n; i++) {
		KHVietNam* khVN = dynamic_cast<KHVietNam*>(ds[i]); // Ép kiểu động về KHVietNam
		if (khVN) {
			char* ngayGD = khVN->getNgayHoaDon();
			if (checkDate(ngayGD)) {
				fout << "Khach hang " << khVN->getHoTen() << " - " << khVN->getMaKH() << ":\n";
				fout << "Ngay hoa don: " << khVN->getNgayHoaDon() << "\n";
				fout << "Loai khach hang: " << khVN->getDoiTuong() << "\n";
				fout << "So luong: " << khVN->getSoLuong() << "\n";
				fout << "Don gia: " << khVN->getDonGia() << "\n";
				fout << "Thanh tien: " << khVN->tinhThanhTien() << "\n\n";
			}
		}
	}
	fout.close();

	//ifstream fin("HoaDonThang3.txt");
	//if (!fin.is_open()) {
	//	cout << "Loi mo file!" << endl;
	//	return;
	//}
	//cout << fin.rdbuf();
	//fin.close();
}

void QLKhachHang::docFile() {
	ifstream fin("HoaDonThang3.txt");
	if (!fin.is_open()) {
		cout << "Loi mo file!" << endl;
		return;
	}
	cout << fin.rdbuf();
	fin.close();
}