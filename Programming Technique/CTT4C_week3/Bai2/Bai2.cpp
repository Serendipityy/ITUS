#include<iostream>
using namespace std;

// Hàm giải phóng bộ nhớ
template <class T>
void arr2D_free(T** a, int m) {
	for (int i = 0; i < m; i++)
		delete[]a[i];
	delete[]a;
}
// Hàm cấp phát bộ nhớ
template <class T>
void arr2D_Alloc(T**& a, int m, int n) {
	a = new T* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new T[n];
	}
}
// Hàm nhập mảng
template <class T>
void arr2D_input(T**& a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\nNhap vao a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}
// Hàm xuất mảng
template <class T>
void arr2D_output(T** a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}

int main() {
	int** a = NULL, m, n;
	cout << "\nNhap vao so dong: ";
	cin >> m;
	cout << "\nNhap vao so cot: ";
	cin >> n;
	arr2D_Alloc(a, m, n);
	arr2D_input(a, m, n);
	cout << "\nMang ban vua nhap la: \n";
	arr2D_output(a, m, n);
	arr2D_free(a, m);
}