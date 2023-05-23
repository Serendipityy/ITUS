#include "QLGiaoDich.h"
#include "GDNha.h"
#include "GDDat.h"
#include "GiaoDich.h"

void QLGiaoDich::nhapDS() {
	int n;
	cout << "Nhap so luong giao dich: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t NHAP THONG TIN GIAO DICH THU " << i + 1 << endl;
		cout << "Nhap loai giao dich (1: dat, 2: nha): ";
		int choice;
		cin >> choice;
		if (choice == 1) {
			GiaoDich* gd = new GDDat;
			gd->nhap();
			ds.push_back(gd);

		}
		else if (choice == 2) {
			GiaoDich* gd = new GDNha;
			gd->nhap();
			ds.push_back(gd);
		}
		else {
			cout << "Lua chon khong hop le!";
			i--;
		}
	}
}

void QLGiaoDich::xuatDS() {
	if (ds.empty()) {
		cout << "Danh sach giao dich rong" << endl;
	}
	else {
		cout << "---------DANH SACH GIAO DICH----------- " << endl;
		for (int i = 0; i < ds.size(); i++) {
			cout << "\n\n\tGIAO DICH THU " << i + 1 << endl;
			ds[i]->xuat();
		}
	}
}
void QLGiaoDich::tinhTrungBinhThanhTienDat() {
	double sum = 0;
	int count = 0;
	for (int i = 0; i < ds.size(); i++) {
		GiaoDich* gd = ds[i];
		if (typeid(*gd) == typeid(GDDat)) {
			sum += gd->tinhThanhTien();
			count++;
		}
	}
	if (count > 0) {
		double avg = sum / count;
		cout << "\n\nTrung binh thanh tien cua giao dich dat: " << avg << endl;
	}
	else {
		cout << "Khong co giao dich dat nao trong danh sach!" << endl;
	}
}
//void timGiaoDichCoSoTienLonNhat();

GiaoDich* QLGiaoDich::timGiaoDichLonNhat() {
	if (ds.empty()) { // kiểm tra danh sách có rỗng hay không
		return nullptr;
	}
	GiaoDich* gdLonNhat = ds[0]; // giả sử giao dịch đầu tiên là lớn nhất
	for (int i = 1; i < ds.size(); i++) { // duyệt qua các giao dịch còn lại
		if (ds[i]->tinhThanhTien() > gdLonNhat->tinhThanhTien()) { // so sánh số tiền
			gdLonNhat = ds[i]; // gán lại giao dịch lớn nhất
		}
	}
	return gdLonNhat; // trả về con trỏ đến giao dịch lớn nhất
}

void QLGiaoDich::xuatGiaoDichThang1Nam2022() {
	int count = 0;
	for (int i = 0; i < ds.size(); i++) {
		if (ds[i]->getThang() == 1 && ds[i]->getNam() == 2022) {
			count++;
			cout << "Giao dich " << count << ":" << endl;
			ds[i]->xuat();
		}
	}
	if (count == 0) {
		cout << "Khong co giao dich nao thoa man dieu kien." << endl;
	}
}
