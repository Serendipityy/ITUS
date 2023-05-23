#include "Designer.h"
#include "Programmer.h"
#include "Employee.h"

void menu(Employee *list[], int& n) {
	bool quit = false;
	int ch;
	ifstream filein;
	filein.open("EmployeeList.txt", ios_base::in);
	do {
		system("cls");
		cout << "--------- *EMPLOYEE MANAGEMENT* --------" << endl;
		cout << "1. Doc thong tin nhan vien tu file" << endl;
		cout << "2. Xuat danh sach nhan vien" << endl;
		cout << "0. Ket thuc" << endl;
		cout << "---------------------------------" << endl;
		cout << "\nNhap lua chon cua ban: ";
		cin >> ch;
		switch (ch) {
		case 1: {
			filein >> n;
			Employee* e = NULL;
			for (int i = 0; i < n; i++) {
				char c;
				filein >> c;
				// dich sang trai 1 byte de ve dau dong
				filein.seekg(-1, 1);
				if (c == 'P') {
					e = new Programmer();
					e->readFile(filein);
				}
				else if (c == 'D') {
					e = new Designer();
					e->readFile(filein);
				}
				// Them vao ds nhan vien
				list[i] = e;
			}
			system("pause");
		}
		break;
		case 2:
		{
			for (int i = 0; i < n; i++) {
				cout << "\n\n\tTHONG TIN NHAN VIEN THU " << i + 1;
				list[i]->printFromFile();
			}
			system("pause");
		}
		break;
		}
		filein.close();
	} while (!quit);
}
int main() {
	// Khai bao mang 1 chieu cac con tro luu tru 2 loai nhan vien
	Employee* list[100];
	int n = 0; // so luong nhan vien hien co trong mang
	menu(list, n);
	return 0;
}