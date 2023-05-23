#include "FrontEndDev.h"


FrontEndDev::FrontEndDev() {

}
FrontEndDev::~FrontEndDev() {

}

// Ham nhap front-end developer
void FrontEndDev::inputInfo() {
	// Goi lai phuong thuc nhap cua lop cha (lop co so)
	Developer::inputInfo();

	cout << "Nhap so project: ";
	cin >> projects;
}

void FrontEndDev::printInfo() {
	// Goi lai phuong thuc xuat cua lop cha
	Developer::printInfo();

	cout << "Projects: " << projects << endl;
	cout << "Luong: " << fixed << setprecision(0) << calcSalary();
}

float FrontEndDev::calcSalary() {
	return projects * 5000000;
}

//// Tinh tong tien luong cua cac front-end dev
//double FrontEndDev::totalSalaryFeDev(FrontEndDev* feList[], int nFe) {
//	double sum = 0;
//	for (int i = 0; i < nFe; i++) {
//		sum += feList[i]->calcSalary();
//	}
//	return sum;
//}