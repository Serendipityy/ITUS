//Viết hàm tìm tất cả các vị trí của x xuất hiện trên mảng, sử dụng con trỏ.
#include<iostream>
using namespace std;
void NhapMang(int* a, int& n) {
	cout << "Nhap so luong phan tu cua mang: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao a[" << i << "] = ";
		cin >> a[i];
	}
}
void XuatMang(int* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
}
void TimViTriGanXNhat (int* a, int n, int x) {
	int min = abs(a[0]-x);
	for (int i = 1; i < n; i++) {
		if (abs(a[i]-x) < min) {
			min = abs(a[i]-x);
		}
	}
	for (int i = 1; i < n; i++) {
		if (abs(a[i] - x) == min) {
			cout << i << "  ";
		}
	}
}

int main() {
	int* a = new int[100];
	int n;
	NhapMang(a, n);
	XuatMang(a, n);
	int x;
	cout << "\nNhap vao gia tri x: ";
	cin >> x;
	int min = 0;
	cout << "\nTat ca cac vi tri cua cac phan tu tren mang gan x nhat la: ";
	TimViTriGanXNhat(a, n, x);
	system("pause");
	return 0;
}