#include "Library.h"

Library::Library() {

}

Library::~Library() {

}

// Phuong thuc nhap thong tin sinh vien
void Library::input() {
	bool quit = false;
	int ch;
	Reader* rd; // Khai bao con tro lop cha
	do {
		system("cls");
		cout << "-----------* LIBRARY MANAGEMENT *-------------" << endl;
		cout << "1. Doc gia tre em" << endl;
		cout << "2. Doc gia nguoi lon" << endl;
		cout << "0. Thoat" << endl;
		cout << "------------------- END ------------------" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch) {
		case 1:
		{
			//ChildrenReader cr; // Khai bao doi tuong doc gia tre em - de nhap thong tin
			//cout << "\n\n\tNHAP THONG  TIN DOC GIA \n";
			//cr.input();
			//childList.push_back(cr); // Them doi tuong doc gia tre em cr vao mang vector doc gia tre em
			
			// Da hinh
			// dung thang cha rd new ra 1 doi tuong con - ChildrenReader
			rd = new ChildrenReader;
			cout << "\n\n\tNHAP THONG  TIN DOC GIA \n";
			rd->input();
			
			rd->setCheckGender(true); // danh dau thang nay la doc gia tre em
			readerList.push_back(rd); // them 1 doi thuong con vao mang doc gia 
			system("pause");
		}
		break;
		case 2:
		{
			//AdultReader ar; // Khai bao doi tuong doc gia nguoi lon - de nhap thong tin
			//cout << "\n\n\tNHAP THONG  TIN DOC GIA \n";
			//ar.input();
			//adultList.push_back(ar); // Them doi tuong doc gia nguoi lon ar vao mang vector doc gia nguoi lon
			
			rd = new AdultReader;
			cout << "\n\n\tNHAP THONG  TIN DOC GIA \n";
			rd->input();
			rd->setCheckGender(false); // danh dau thang nay la doc gia nguoi lon
			readerList.push_back(rd); // them 1 doi thuong con vao mang doc gia 
			system("pause");
		}
		break;
		case 0:
		{
			//exit(0);
			quit = true;
			break;
			//system("pause");
		}
		break;
		default:
		{
			cout << "\nLua chon khong hop le!";
			system("pause");
		}
		break;
		}
	} while (!quit);
}

// Phuong thuc xuat thong tin sinh vien
void Library::print() {
	// xuat danh sach thong tin doc gia tre em
	cout << "\n\n\t ------- DANH SACH DOC GIA TRE EM -------\n";
	//for (int i = 0; i < childList.size(); i++) {
	//	cout << "\n\n\tTHONG TIN DOC GIA TRE EM THU " << i + 1;
	//	childList[i].print();
	//}

	//// xuat danh sach thong tin doc gia nguoi lon
	//cout << "\n\n\t ------- DANH SACH DOC GIA NGUOI LON -------\n";
	//for (int i = 0; i < adultList.size(); i++) {
	//	cout << "\n\n\tTHONG TIN DOC GIA NGUOI LON THU " << i + 1;
	//	adultList[i].print();
	//}

	// Da hinh
	for (int i = 0; i < readerList.size(); i++) {
		if (readerList[i]->getCheckGender() == true) {
			cout << "\n\n\tTHONG TIN DOC GIA TRE EM THU " << i + 1;
			readerList[i]->print();
		}
		else {
			cout << "\n\n\tTHONG TIN DOC GIA NGUOI LON THU " << i + 1;
			readerList[i]->print();
		}
	}
}

// Phuong thuc tinh tong tien lam the
int Library::calcTotalRegistCardMoney() {
	int sum = 0;
	/*for (int i = 0; i < childList.size(); i++) {
		sum += childList[i].caclRegistCardMoney();
	}

	for (int i = 0; i < adultList.size(); i++) {
		sum += adultList[i].calcRegistCardMoney();
	}*/

	for (int i = 0; i < readerList.size(); i++) {
		sum += readerList[i]->calcRegistCardMoney();
	}

	return sum;
}