#include<iostream>
using namespace std;

/*Dinh nghia DArray*/
struct DArray {
	int size;
	int* ptr;
};

/*Khoi tao DArray*/
void DAInit(DArray& A, int n) {
	A.size = n;
	A.ptr = new int[n];
}

/*Ham giai phong bo nho*/
void DAFree(DArray& A) {
	delete[] A.ptr;
}
/*Nhap mang*/
void DAInput(DArray& A) {
	int n;
	cout << "\nNhap so luong phan tu cua mang: ";
	cin >> n;
	// Gọi hàm khởi tạo mảng
	DAInit(A, n);
	for (int i = 0; i < A.size; i++) {
		cout << "\nNhap A.ptr[" << i << "]: ";
		cin >> A.ptr[i];
	}
}

/*Hàm xuat mang*/
void DAOutput(DArray A) {
	// Duyệt qua mảng và xuất các phần tử
	for (int i = 0; i < A.size; i++) {
		cout << A.ptr[i] << "   ";
	}
}
/*Them 1 phan tu x tai vi tri k*/
void addEntry(DArray& A, int x, int k) {
	// Tạo mảng phụ chứa các phần tử của mảng A
	int* temp = new int[A.size];
	for (int i = 0; i < A.size; i++) {
		temp[i] = A.ptr[i]; // Bỏ lần lượt các phần tử của mảng A sang mảng temp
	}

	// Giải phóng vùng nhớ cũ của A
	DAFree(A);

	// Cấp phát lại vùng nhớ mới cho A => mảng A sẽ tăng lên 1 ô nhớ
	A.ptr = new int[A.size + 1]; // Cấp phát lại vùng nhớ cho mảng A với số lượng phần tử mảng tăng lên 1 ô nhớ

	// Đổ tất cả các phần tử trong mảng temp về lại cho mảng A
	for (int i = 0; i < A.size; i++) {
		A.ptr[i] = temp[i];
	}
	delete[] temp; // Giải phóng vùng nhớ temp khi không cần dùng nữa

	// Thuật toán thêm
	for (int i = A.size - 1; i >= k; i--) {
		A.ptr[i + 1] = A.ptr[i];
	}
	A.ptr[k] = x;
	A.size++; // Tăng số lượng phần tử mảng
}
/*Xoa 1 phan tu tai vi tri k khoi mang*/
void removeEntry(DArray& A, int k) {
	for (int i = k + 1; i < A.size; i++) {
		A.ptr[i - 1] = A.ptr[i];
	}
	A.size--; // Số lượng phần tử mảng giảm 1 đơn vị
	int* temp = new int[A.size];
	for (int i = 0; i < A.size; i++) {
		temp[i] = A.ptr[i];
	}
	DAFree(A);

	A.ptr = new int[A.size];
	for (int i = 0; i < A.size; i++) {
		A.ptr[i] = temp[i];
	}
	delete[] temp;
}
int main() {
	DArray A;
	DAInput(A);
	DAOutput(A);

	int x, k;
	cout << "\nNhap vao phan tu can them x: ";
	cin >> x;
	cout << "\nNhap vao vi tri can them k: ";
	cin >> k;
	addEntry(A, x, k);
	cout << "\nMang sau khi them: ";
	DAOutput(A);
	cout << "\nNhap vao vi tri can xoa: ";
	cin >> k;
	removeEntry(A, k);
	cout << "\nMang sau khi xoa: ";
	DAOutput(A);
	DAFree(A);
}