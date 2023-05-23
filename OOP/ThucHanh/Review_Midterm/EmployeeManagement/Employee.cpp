#include "Employee.h"

Employee::Employee() {

}

Employee::~Employee() {

}
// Cai dat phuong thuc doc file cua lop cha
// chi doc nhung thuoc tinh chung (trong class cha)
void Employee::readFile(ifstream& filein) {
	getline(filein, id, ',');
	// (so byte can dich, vi tri hien tai can dich)
	filein.seekg(1, 1); // dich con tro chi vi tai vi tri hien tai sang phai 1 byte
	getline(filein, name, ',');
	filein.seekg(1, 1);
	int date;
	filein >> date;
	dob.setDate(date);
	filein.seekg(1, 1);
	int month;
	filein >> month;
	dob.setDate(month);
	filein.seekg(1, 1);
	int year;
	filein >> year;
	dob.setDate(year);
	filein.seekg(2, 1); // dich 2 byte (dau phay, khoang trang)
	getline(filein, address, ',');
	filein >> coeffSalary;
	// doc so no khong lay khoang trang
	filein.seekg(1, 1);
	filein >> salary;
	filein.seekg(1, 1);
}

void Employee::printFromFile() {
	cout << "\nMa nhan vien: " << id << endl;
	cout << "Ho ten nhan vien: " << name << endl;
	cout << "Ngay thang nam sinh: " << dob.getDate() << "/" << dob.getMonth() << "/" << dob.getYear() << endl;
	cout << "Dia chi nhan vien: " << address << endl;
	cout << "He so luong: " << coeffSalary << endl;
	cout << "Luong co ban: " << fixed << setprecision(0) << salary;
}