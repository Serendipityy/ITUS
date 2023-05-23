#include "Class.h"

Class::Class() {
	cName = "";
	num = 0;
	sList = NULL;
	n = 0;
}
Class::~Class() {
	delete[] sList;
}

void Class::input() {
	cout << "Nhap ten lop: ";
	getline(cin, cName);
	cout << "Nhap si so: ";
	cin >> num;
	cin.ignore();
	// Nhap danh sach hoc sinh
	cout << "Nhap danh sach hoc sinh: " << endl;
	sList = new Student[num];
	for (int i = 0; i < num; i++) {
		cout << "\nNhap thong tin hoc sinh thu " << i + 1 << endl;
		cin >> sList[i];
		bool checkID = false;
		for (int j = 0; j < i; j++) {
			if (sList[i].getID() == sList[j].getID()) {
				checkID = true;
				break;
			}
		}
		if (checkID) {
			cout << "Ma hoc sinh da co trong danh sach. Vui long nhap lai";
			i--;
		}
	}

}
void Class::print() {
	cout << "Ten lop: " << cName << endl;
	cout << "Si so: " << num << endl;
	cout << "Danh sach hoc sinh: " << endl;
	for (int i = 0; i < num; i++) {
		cout << "Hoc sinh thu " << i + 1 << endl;
		cout << sList[i] << endl;
	}
}
void searchDOB();
//Class& operator=(const Class& other);