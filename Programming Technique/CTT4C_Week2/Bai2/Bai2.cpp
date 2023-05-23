#include<iostream>
using namespace std;
// Khai báo mảng động 1 chiều
// Sử dụng biến cấu trúc
struct Darray {
	int sz; // Kích thước của mảng
	int* ptr;
};

// Viết hàm khởi tạo mảng động
void DAInit(Darray& A, int n) {
	A.sz = n;
	// Cấp phát bộ nhớ cho mảng động
	A.ptr = new int[n];
}
// Hàm nhập mảng
void DAInput(Darray& A) {
	int n;
	cout << "Nhap kich thuoc mang n: ";
	cin >> n;
	// Gọi hàm khởi tạo mảng
	DAInit(A, n);
	// Nhập các phần tử của mảng A
	for (int i = 0; i < A.sz; i++) {
		cout << "A.ptr[" << i << "]: ";
		cin >> A.ptr[i];
	}
}
// Hàm xuất mảng
void DAOutput(Darray A) {
	// Duyệt qua mảng và xuất các phần tử
	for (int i = 0; i < A.sz; i++) {
		cout << A.ptr[i] << "   ";
	}
}
// Hàm tìm kiếm vị trí phần tử x xuất hiện trong mảng
void TimKiemViTriPhanTuXTrongMang(Darray A, int x) {
	for (int i = 0; i < A.sz; i++) {
		if (A.ptr[i] == x) {
			cout << i << "  ";
		}
	}
}
// *--------Testing---------* //
int main() {
	Darray A;
	DAInput(A);
	DAOutput(A);
	int x;
	cout << "\nNhap vao phan tu can tim kiem x: ";
	cin >> x;
	cout << "\nTat ca cac vi tri xuat hien tren mang cua x la: ";
	TimKiemViTriPhanTuXTrongMang(A, x);
	system("pause");
	return 0;
}