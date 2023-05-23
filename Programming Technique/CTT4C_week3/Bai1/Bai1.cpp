#include<iostream>
using namespace std;

// Ham cap phat bo nho

int** arr2D_Alloc(int m, int n) {
	int** a = new int* [m];
	for (int i = 0; i < m; i++)
	{
		a[i] = new int[n];
	}
	return a;
}
// Ham giai phong bo nho
void arr2D_free(int** a, int m) {
	for (int i = 0; i < m; i++)
		delete[] a[i];
	delete[] a;
}
// Ham nhap mang
void arr2D_input(int** a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "\nNhap vao a[" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
}
// Ham xuat mang
void arr2D_output(int** a, int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << "   ";
		}
		cout << endl;
	}
}
// Luu cac so nguyen to co trong mang a vao mot mang dong

// Ham kiem tra so nguyen to
bool KiemTraSNT(int x) {
	if (x < 2) {
		return 0;
	}
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}
// Ham liet ke cac so nguyen to trong mang a
int LK_SNT(int** a, int m, int n) {
	int dem = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (KiemTraSNT(a[i][j]) == 1) {
				dem++;
			}
		}
	}
	return dem;
}
// Ham luu so nguyen to vao mang dong
void LuuSNTVaoMangDong(int** a, int* b, int m, int n) {
	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (KiemTraSNT(a[i][j]) == 1) {
				b[k] = a[i][j];
				k++;
			}
		}
	}
}

int main() {
	int** a = NULL, m, n;
	int* b = NULL;
	cout << "\nNhap so dong: ";
	cin >> m;
	cout << "\nNhap so cot: ";
	cin >> n;
	a = arr2D_Alloc(m, n);
	if (a != NULL) {
		arr2D_input(a, m, n);
		cout << "\nMang ban nhap la: \n";
		arr2D_output(a, m, n);
	}

	int nb = LK_SNT(a, m, n);
	b = new int[nb];
	LuuSNTVaoMangDong(a, b, m, n);
	cout << "Mang sau khi luu cac so nguyen to: ";
	for (int i = 0; i < nb; i++) {
		cout << b[i] << "  ";
	}
	arr2D_free(a, m);
	system("pause");
	return 0;
}