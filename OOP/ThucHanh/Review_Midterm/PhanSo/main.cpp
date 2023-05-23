#include "PhanSo.h"
#include "DayPhanSo.h"

int main() {
	int ch;
	bool quit = false;
	DayPhanSo ds;
	do {
		system("cls");
		cout << "---------* CLASS PHAN SO - DAY PHAN SO *----------" << endl;
		cout << "1. Nhap day phan so" << endl;
		cout << "2. Xuat day phan so" << endl;
		cout << "3. Phan so nho nhat trong day phan so" << endl;
		cout << "4. Phan so lon nhat trong day phan so" << endl;
		cout << "5. Sap xep cac phan so" << endl;
		cout << "6. So sanh tong cac phan so cua 2 day so" << endl;
		cout << "0. Thoat" << endl;
		cout << "---------------------* END *---------------------" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch) {
		case 1:
		{
			ds.nhap();
			system("pause");
		}
		break;
		case 2:
		{
			ds.xuat();
			system("pause");
		}
		break;
		case 3:
		{

			PhanSo minPS = ds.min();
			cout << "Phan so nho nhat trong day phan so: " << minPS << endl;
			system("pause");
		}
		break;
		case 4:
		{
			PhanSo maxPS = ds.max();
			cout << "Phan so lon nhat trong day phan so: " << maxPS << endl;
			system("pause");
		}
		break;
		case 5:
		{
			cout << "\nTang dan: ";
			ds.sapXepTang();
			ds.xuat();

			cout << "\nGiam dan: ";
			ds.sapXepGiam();
			ds.xuat();
			system("pause");
		}
		break;
		case 6:
		{
			DayPhanSo d1, d2;
			cout << "\nNhap day phan so thu nhat: ";
			d1.nhap();
			cout << "\nNhap day phan so thu hai: ";
			d2.nhap();
			if (d1 > d2) {
				cout << "Tong cua day phan so 1 lon hon tong cua day phan so 2" << endl;
			}
			else if (d1 < d2) {
				cout << "Tong cua day phan so 1 nho hon tong cua day phan so 2" << endl;
			}
			else {
				cout << "Tong cua hai day phan so bang nhau" << endl;
			}
			system("pause");
		}
		break;
		}
		
	} while (!quit);
}