#include "Student.h"
Student::Student() {

}
istream& operator>>(istream& is, Student& s) {
	cout << "Nhap ma so: ";
	getline(is, s.id);
	cout << "Nhap ho ten: ";
	getline(is, s.name);
	cout << "Nhap gioi tinh: ";
	getline(is, s.gender);
	cout << "Nhap ngay sinh: ";
	is >> s.dob;
	cout << "Nhap dia chi: ";
	is.ignore();
	getline(is, s.address);
	return is;
}

ostream& operator<<(ostream& os, const Student& s) {
	cout << "Ma so: " << s.id << endl;
	cout << "Ho ten: " << s.name << endl;
	cout << "Gioi tinh: " << s.gender << endl;
	cout << "Ngay sinh: " << s.dob << endl;
	cout << "Dia chi: " << s.address << endl;
	return os;
}
