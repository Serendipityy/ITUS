#include "FullStackDev.h"

FullStackDev::FullStackDev() {

}
FullStackDev::~FullStackDev() {

}
// Ham nhap full-stack developer
void FullStackDev::inputInfo() {
	Developer::inputInfo();

	cout << "Nhap ti le phan tram hoan thanh: ";
	cin >> completedPercent;
}

void FullStackDev::printInfo() {
	Developer::printInfo();

	cout << "Ti le phan tram hoan thanh: " << completedPercent << endl;
	cout << "Luong: " << fixed << setprecision(0) << calcSalary();
}

float FullStackDev::calcSalary() {
	return completedPercent * 650000;
}


//// Tinh tong tien luong cua cac fullstack dev
//double FullStackDev::totalSalaryFsDev(FullStackDev* fsList[], int nFs) {
//	double sum = 0;
//	for (int i = 0; i < nFs; i++) {
//		sum += fsList[i]->calcSalary();
//	}
//	return sum;
//}

