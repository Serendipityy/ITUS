#include "Vehicle.h"
#include "Bike.h"
#include "Motorbike.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// xuat tat ca thong tin thue xe
void printAllRentInfo(Bike bList[], int nBike, Motorbike mList[], int nMBike) {
	int cnt = 1;
	cout << "\n\n\t DANH SACH THUE XE DAP\n";
	for (int i = 0; i < nBike; i++) {
		cout << "\n\n\t THONG TIN THUE XE DAP THU " << cnt++;
		bList[i].print();
		cout << "\nTien thue: " << fixed << setprecision(0) << bList[i].calcRentMoney();
	}

	cout << "\n\n\t DANH SACH THUE XE MAY\n";
	for (int i = 0; i < nMBike; i++) {
		cout << "\n\n\t THONG TIN THUE XE MAY THU " << cnt++;
		mList[i].print();
		cout << "\nTien thue: " << fixed << setprecision(0) << mList[i].calcRentMoney();
	}
}

// tinh tong tien thue xe dap va xe may
double calcTotalRentMoney(Bike bList[], int nBike, Motorbike mList[], int nMBike) {
	double sum = 0;
	for (int i = 0; i < nBike; i++) {
		sum += bList[i].calcRentMoney();
	}
	for (int i = 0; i < nMBike; i++) {
		sum += mList[i].calcRentMoney();
	}
	return sum;
}

void Menu(Bike bList[], int nBike, Motorbike mList[], int nMBike) {
	int ch;
	bool quit = false;
	do {
		system("cls");
		cout << "----------* VEHICLE MANAGEMENT *---------" << endl;
		cout << "1. Nhap danh sach thue xe dap va xe may" << endl;
		cout << "2. Xuat tat ca thong tin thue xe" << endl;
		cout << "3. Tinh tong so tien cho thue xe dap va xe may" << endl;
		cout << "4. Xuat tat ca cac thong tin lien quan den viec cho thue xe dap" << endl;
		cout << "5. Tinh tong so tien cho thue xe may loai 250 phan khoi" << endl;
		cout << "0. Ket thuc" << endl;
		cout << "-----------------------------------------" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch) {
		case 1:
		{
			int ch;
			system("cls");
			cout << "1. Thue XE DAP" << endl;
			cout << "2. Thue XE MAY" << endl;
			cout << "0. Ket thuc" << endl;
			cout << "Nhap loai xe muon thue: ";
			cin >> ch;
			if (ch == 1) {
				Bike b;
				cout << "\n\n\t NHAP THONG TIN THUE XE DAP \n";
				b.input();
				bList[nBike] = b;
				nBike++;
			}
			else if (ch == 2) {
				Motorbike mB;
				cout << "\n\n\t NHAP THONG TIN THUE XE MAY \n";
				mB.input();
				mList[nMBike] = mB;
				nMBike++;
			}
			else break; // thoat khoi menu nho
		}
		break;
		case 2:
		{
			printAllRentInfo(bList, nBike, mList, nMBike);
			system("pause");
		}
		break;
		case 3:
		{
			cout << "\n\n\tTONG TIEN THUE XE: " << fixed << setprecision(0) << calcTotalRentMoney(bList, nBike, mList, nMBike);
			system("pause");
		}
		break;
		case 4:
		{
			for (int i = 0; i < nBike; i++) {
				cout << "\n\tTHONG TIN XE DAP THU " << i + 1 << endl;
				bList[i].print();
				cout << "\nTien thue xe: " << fixed << setprecision(0) << bList[i].calcRentMoney();
			}
			system("pause");
		}
		break;
		case 5:
		{
			int cnt = 0;
			cout << "\n\n\tDANH SACH THUE XE MAY \n";
			
			for (int i = 0; i < nMBike; i++) {
				if (mList[i].getType() == 250) {
					cout << "\n\tTHONG TIN THUE XE MAY THU " << ++cnt << endl;
					mList[i].print();
					cout << "\nTien thue xe: " << fixed << setprecision(0) << mList[i].calcRentMoney();
				}
				
			}
			system("pause");
		}
		break;
		}
	} while (!quit);

}



int main() {
	Bike bList[100];
	int nBike = 0; 
	Motorbike mList[100];
	int nMBike = 0;
	Menu(bList, nBike, mList, nMBike);
	return 0;
}