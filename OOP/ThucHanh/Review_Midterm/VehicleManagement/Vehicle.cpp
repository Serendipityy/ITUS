#include "Vehicle.h"
Vehicle::Vehicle() {

}

Vehicle::~Vehicle() {

}

void Vehicle::input() {
	// Co the dat lenh nay o dau de xoa bo nho dem
	// ĐÚNG trong moi tinh huong (can include thu vien conio.h)
	// while(getchar() != '\n');
	cout << "Nhap ho ten nguoi thue: ";
	cin.ignore();
	getline(cin, rentName);
	cout << "Nhap so gio thue: ";
	cin >> rentHour;
}

void Vehicle::print() {
	cout << "\nHo ten nguoi thue: " << rentName << endl;
	cout << "So gio thue: " << rentHour;
}