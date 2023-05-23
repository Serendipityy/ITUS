#include "Motorbike.h"

Motorbike::Motorbike() {

}

Motorbike::~Motorbike() {

}

void Motorbike::input() {
	Vehicle::input();
	cout << "Nhap loai xe can thue (100 - 250 phan khoi): ";
	cin >> type;
	cout << "Nhap bien so xe: ";
	cin.ignore();
	getline(cin, numberPlate);
}

void Motorbike::print() {
	Vehicle::print();
	cout << "Loai xe thue: " << type << endl;
	cout << "Bien so xe: " << numberPlate;
}

double Motorbike::calcRentMoney() {
	double s = 0;
	if(type==100) {
		s = 150000;
	}
	else {
		s = 200000;
	}

	return s + ((rentHour - 1) * 100000);
}