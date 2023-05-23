#include "BackEndDev.h"

BackEndDev::BackEndDev() {

}
BackEndDev::~BackEndDev() {

}


// Ham nhap front-end developer
void BackEndDev::inputInfo() {
	Developer::inputInfo();

	cout << "Nhap so gio lam viec: ";
	cin >> workingHours;
}

void BackEndDev::printInfo() {
	Developer::printInfo();

	cout << "So gio lam viec: " << workingHours << endl;
	cout << "Luong: " << fixed << setprecision(0) << calcSalary();
}

float BackEndDev::calcSalary() {
	return workingHours * 500000;
}

//// Tinh tong tien luong cua cac back-end dev
//double BackEndDev::totalSalaryBeDev(BackEndDev* beList[], int nBe) {
//	double sum = 0;
//	for (int i = 0; i < nBe; i++) {
//		sum += beList[i]->calcSalary();
//	}
//	return sum;
//}
