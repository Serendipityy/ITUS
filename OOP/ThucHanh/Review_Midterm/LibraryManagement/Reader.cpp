#include "Reader.h"

Reader::Reader() {

}

Reader::~Reader() {

}

void Reader::input() {
	//fflush(stdin);
	cout << "Nhap ho ten doc gia: ";
	cin.ignore();
	getline(cin, name);
	cout << "Nhap ngay lap the (dd/mm/yyyy): ";
	getline(cin, registCardDate);
	cout << "Nhap so thang co hieu luc: ";
	cin >> validMonth;
}

void Reader::print() {
	cout << "\nHo ten doc gia: " << name << endl;
	cout << "Ngay lap the (dd/mm/yyyy): " << registCardDate << endl;
	cout << "So thang co hieu luc: " << validMonth << endl;
}