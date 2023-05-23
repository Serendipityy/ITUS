#include "FrontEndDev.h"
#include "BackEndDev.h"
#include "FullStackDev.h"
#include "Developer.h"

// Tinh tong tien luong cua cac front-end dev
double totalSalaryFeDev(FrontEndDev* feList[], int nFe) {
	double sum = 0;
	for (int i = 0; i < nFe; i++) {
		sum += feList[i]->calcSalary();
	}
	return sum;
}

// Tinh tong tien luong cua cac back-end dev
double totalSalaryBeDev(BackEndDev* beList[], int nBe) {
	double sum = 0;
	for (int i = 0; i < nBe; i++) {
		sum += beList[i]->calcSalary();
	}
	return sum;
}

// Tinh tong tien luong cua cac fullstack dev
double totalSalaryFsDev(FullStackDev* fsList[], int nFs) {
	double sum = 0;
	for (int i = 0; i < nFs; i++) {
		sum += fsList[i]->calcSalary();
	}
	return sum;
}

//// Hoan vi 2 doi tuong front-end dev
//void swapFeDev(FrontEndDev* fe1, FrontEndDev* fe2) {
//	FrontEndDev *temp = fe1;
//	fe1 = fe2;
//	fe2 = temp;
//}
//
//// Hoan vi 2 doi tuong back-end dev
//void swapBeDev(BackEndDev* be1, BackEndDev* be2) {
//	BackEndDev* temp = be1;
//	be1 = be2;
//	be2 = temp;
//}
//
//// Hoan vi 2 doi tuong fullstack dev
//void swapFsDev(FullStackDev* fs1, FullStackDev* fs2) {
//	FullStackDev* temp = fs1;
//	fs1 = fs2;
//	fs2 = temp;
//}


// Sap xep danh sach front-end dev giam dan theo luong
void sortSalaryFeDev(FrontEndDev* feList[], int nFe) {
	for (int i = 0; i < nFe - 1; i++) {
		for (int j = i + 1; j < nFe; j++) {
			if (feList[i]->calcSalary() < feList[j]->calcSalary()) {
				//swapFeDev(feList[i], feList[j]);
				swap(feList[i], feList[j]);
			}
		}
	}
}

// Sap xep danh sach back-end dev giam dan theo luong
void sortSalaryBeDev(BackEndDev* beList[], int nBe) {
	for (int i = 0; i < nBe - 1; i++) {
		for (int j = i + 1; j < nBe; j++) {
			if (beList[i]->calcSalary() < beList[j]->calcSalary()) {
				swap(beList[i], beList[j]);
			}
		}
	}
}

// Sap xep danh sach fullstack dev giam dan theo luong
void sortSalaryFsDev(FullStackDev* fsList[], int nFs) {
	for (int i = 0; i < nFs - 1; i++) {
		for (int j = i + 1; j < nFs; j++) {
			if (fsList[i]->calcSalary() < fsList[j]->calcSalary()) {
				swap(fsList[i], fsList[j]);
			}
		}
	}
}

void menu(FrontEndDev* feList[], BackEndDev* beList[], FullStackDev* fsList[], int nFe, int nBe, int nFs) {
	bool quit = false;
	int ch;
	do {
		system("cls");
		cout << "------------* DEVELOPERS MANAGEMENT *--------------" << endl;
		cout << "1. Nhap danh sach front-end developer" << endl;
		cout << "2. Nhap danh sach back-end developer" << endl;
		cout << "3. Nhap danh sach fullstack developer" << endl;
		cout << "4. Danh sach front-end developer" << endl;
		cout << "5. Danh sach back-end developer" << endl;
		cout << "6. Danh sach fullstack developer" << endl;
		cout << "7. Tong tien luong cua tat ca devloper trong cong ty" << endl;
		cout << "8. Sap xep danh sach developer theo luong giam dan" << endl;
		cout << "------------------------END------------------------" << endl;

		cout << "\nNhap lua chon cua ban: "; cin >> ch;
		switch (ch) {
		case 1:
		{
			FrontEndDev* fe = new FrontEndDev(); // doi tuong con tro
			cout << "\n\n\tNHAP THONG TIN FRONT-END DEV" << endl;
			fe->inputInfo();

			// Them doi tuong con tro "fe' vao danh sach con tro "feList"
			feList[nFe] = fe;
			nFe++;

			system("pause");
		}
		break;
		case 2:
		{
			BackEndDev* be = new BackEndDev(); 
			cout << "\n\n\tNHAP THONG TIN BACK-END DEV" << endl;
			be->inputInfo();

			beList[nBe] = be;
			nBe++;

			system("pause");
		}
		break;
		case 3:
		{
			FullStackDev* fs = new FullStackDev(); 
			cout << "\n\n\tNHAP THONG TIN FULLSTACK DEV" << endl;
			fs->inputInfo();

			fsList[nFs] = fs;
			nFs++;

			system("pause");
		}
		break;
		case 4:
		{
			cout << "\n\n\tDANH SACH THONG TIN FRONT-END DEV" << endl;
			for (int i = 0; i < nFe; i++) {
				cout << "\n\n\tTHONG TIN FRONT-END DEV THU " << i + 1;
				feList[i]->printInfo();
			}
			cout << "\n\n\tTONG TIEN LUONG: " << fixed << setprecision(0) << totalSalaryFeDev(feList, nFe);
			system("pause");
		}
		break;
		case 5:
		{
			cout << "\n\n\tDANH SACH THONG TIN BACK-END DEV" << endl;
			for (int i = 0; i < nBe; i++) {
				cout << "\n\n\tTHONG TIN BACK-END DEV THU " << i + 1;
				beList[i]->printInfo();
			}
			cout << "\n\n\tTONG TIEN LUONG: " << fixed << setprecision(0) << totalSalaryBeDev(beList, nBe);
			system("pause");
		}
		break;
		case 6:
		{
			cout << "\n\n\tDANH SACH THONG TIN FULLSTACK DEV" << endl;
			for (int i = 0; i < nFs; i++) {
				cout << "\n\n\tTHONG TIN FULLSTACK DEV THU " << i + 1;
				fsList[i]->printInfo();
			}
			cout << "\n\n\tTONG TIEN LUONG: " << fixed << setprecision(0) << totalSalaryFsDev(fsList, nFs);
			system("pause");
		}
		break;
		case 7:
		{
			cout << "\n\n\tTONG TIEN CONG TY CAN TRA HANG THANG: "
				<< fixed << setprecision(0) << totalSalaryFeDev(feList, nFe)
				+ totalSalaryBeDev(beList, nBe) + totalSalaryFsDev(fsList, nFs);
			system("pause");
		}
		break;
		case 8:
		{
			cout << "\n\n\tDANH SACH GIAM DAN LUONG FRONT-END DEV " << endl;
			sortSalaryFeDev(feList, nFe);
			for (int i = 0; i < nFe; i++) {
				cout << "\n\n\tTHONG TIN FRONT-END DEV THU " << i + 1;
				feList[i]->printInfo();
			}


			cout << "\n\n\tDANH SACH GIAM DAN LUONG BACK-END DEV " << endl;
			sortSalaryBeDev(beList, nBe);
			for (int i = 0; i < nBe; i++) {
				cout << "\n\n\tTHONG TIN BACK-END DEV THU " << i + 1;
				beList[i]->printInfo();
			}

			cout << "\n\n\tDANH SACH GIAM DAN LUONG FULLSTACK DEV " << endl;
			sortSalaryFsDev(fsList, nFs);
			for (int i = 0; i < nFs; i++) {
				cout << "\n\n\tTHONG TIN FULLSTACK DEV THU " << i + 1;
				fsList[i]->printInfo();
			}

			system("pause");
		}
		break;
		default:
		{
			cout << "\nLua chon khong hop le";
			system("pause");
		}
		break;
		}
	} while (!quit);
}
int main() {
	
	// Khai bao danh sach chua toi da 100 cac doi tuong
	// con tro <=> moi o nho la 1 con tro de quan ly
	FrontEndDev* feList[100];
	BackEndDev* beList[100];
	FullStackDev* fsList[100];
	int nFe = 0; // so luong front-end dev
	int nBe = 0; // so luong back-end dev
	int nFs = 0; // so luong fullstack dev
	menu(feList, beList, fsList, nFe, nBe, nFs);

	// Giai phong cac doi tuong con tro cho danh sach front-end dev
	for (int i = 0; i < nFe; i++) {
		delete feList[i];
	}

	// Giai phong cac doi tuong con tro cho danh sach back-end dev
	for (int i = 0; i < nBe; i++) {
		delete beList[i];
	}

	// Giai phong cac doi tuong con tro cho danh sach fullstack dev
	for (int i = 0; i < nFs; i++) {
		delete fsList[i];
	}
	return 0;

}