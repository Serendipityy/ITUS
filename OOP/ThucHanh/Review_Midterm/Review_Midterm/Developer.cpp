#include "Developer.h"


Developer::Developer() {

}

Developer::~Developer() {

}

// Ham nhap thong tin developer cua lop cha
void Developer::inputInfo() {
	//fflush(stdin);
	cout << "Nhap ho ten: ";
	cin.ignore();
	getline(cin, name);
	cout << "Nhap tuoi: ";
	cin >> age;
	cout << "Nhap gioi tinh: ";
	cin.ignore();
	getline(cin, gender);
	cout << "Nhap dia chi: ";
	getline(cin, address);
	cout << "Nhap so dien thoai: ";
	getline(cin, phoneNumber);
	cout << "Nhap chieu cao: ";
	cin >> height;
	cout << "Nhap can nang: ";
	cin >> weight;
}

// Ham xuat thong tin developer cua lop cha
void Developer::printInfo() {
	cout << "\nHo ten: " << name << endl;
	cout << "Tuoi: " << age << endl;
	cout << "Gioi tinh: " << gender << endl;
	cout << "Dia chi: " << address << endl;
	cout << "So dien thoai: " << phoneNumber << endl;
	cout << "Chieu cao: " << height << endl;
	cout << "Can nang: " << weight << endl;
}
