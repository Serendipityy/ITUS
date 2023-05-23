#include "DayPhanSo.h"

DayPhanSo::DayPhanSo() {
	ds = NULL;
	n = 0;
}

DayPhanSo::DayPhanSo(int _n) {
	ds = new PhanSo[n];
	n = _n;
}
DayPhanSo::DayPhanSo(const DayPhanSo& other) {
	n = other.n;
	ds = new PhanSo[n];
	for (int i = 0; i < n; i++) {
		ds[i] = other.ds[i];
	}
}

DayPhanSo::~DayPhanSo() {
	if (ds != NULL) {
		delete[] ds;
	}
}

void DayPhanSo::nhap() {
	cout << "Nhap so luong phan so: ";
	cin >> n;
	ds = new PhanSo[n];
	for (int i = 0; i < n; i++) {
		cout << "Nhap phan so thu " << i + 1 << ": ";
		cin >> ds[i];
	}
}


void DayPhanSo::xuat() {
	cout << "Danh sach phan so: " << endl;
	for (int i = 0; i < n; i++) {
		cout << ds[i] << " ";
	}
	cout << endl;
}

PhanSo DayPhanSo::min() {
	PhanSo minPS = ds[0];
	for (int i = 1; i < n; i++) {
		if (ds[i] < minPS) {
			minPS = ds[i];
		}
	}
	return minPS;
}

PhanSo DayPhanSo::max() {
	PhanSo maxPS = ds[0];
	for (int i = 1; i < n; i++) {
		if (ds[i] > maxPS) {
			maxPS = ds[i];
		}
	}
	return maxPS;
}

void DayPhanSo::sapXepTang() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ds[i] > ds[j]) {
				swap(ds[i], ds[j]);
			}
		}
	}
}

void DayPhanSo::sapXepGiam() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ds[i] < ds[j]) {
				swap(ds[i], ds[j]);
			}
		}
	}
}
//PhanSo& DayPhanSo::operator[](int index) {
//	return ds[index];
//}

bool DayPhanSo::operator>(const DayPhanSo& other) const {
	PhanSo sum1, sum2;
	for (int i = 1; i < n; i++) {
		sum1 = sum1 + ds[i];
	}
	for (int i = 0; i < other.n; i++) {
		sum2 = sum2 + other.ds[i];
	}
	return sum1 > sum2;
}

bool DayPhanSo::operator<(const DayPhanSo& other) const {
	PhanSo sum1, sum2;
	for (int i = 1; i < n; i++) {
		sum1 = sum1 + ds[i];
	}
	for (int i = 0; i < other.n; i++) {
		sum2 = sum2 + other.ds[i];
	}
	return sum1 < sum2;
}
bool DayPhanSo::operator==(const DayPhanSo& other) const {
	PhanSo sum1, sum2;
	for (int i = 1; i < n; i++) {
		sum1 = sum1 + ds[i];
	}
	for (int i = 0; i < other.n; i++) {
		sum2 = sum2 + other.ds[i];
	}
	return sum1 == sum2;
}
