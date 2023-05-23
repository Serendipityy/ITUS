#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Ngay {
	int ng, th, nam;
};
struct SINHVIEN {
	//char maso[9]; // "19120100",
	//char hoten[30]; // "Nguyen Thanh An"
	string maso;
	string hoten;
	bool GioiTinh; // 1: "Nam"; 0: "Nu"
	Ngay NgaySinh; // 01/01/2000
	float Diem; // 6.75
};
struct Node {
	SINHVIEN data;
	Node* Next;
};
struct List {
	Node* Head;
	Node* Tail;
};
void KhoiTaoDS(List& l) {
	l.Head = l.Tail = NULL;
}
Node* KhoiTaoNode(SINHVIEN x) {
	Node* p = new Node;
	if (p == NULL) {
		cout << "\nCap phat that bai!";
		return NULL;
	}
	p->data = x;
	p->Next = NULL;
	return p;
}
void ThemDau(List& l, Node* p) {
	if (l.Head == NULL) {
		l.Head = l.Tail = p;
	}
	else {
		p->Next = l.Head;
		l.Head = p;
	}
}
void ThemCuoi(List& l, Node* p) {
	if (l.Head == NULL) {
		l.Head = l.Tail = p;
	}
	else {
		l.Tail->Next = p;
		l.Tail = p;
	}
}
void Nhap1SV(SINHVIEN& sv) {
	cout << "\nNhap ma so: ";
	cin.ignore();
	//cin.getline(sv.maso, 9);
	getline(cin, sv.maso);
	cout << "\nNhap ho ten: ";
	/*cin.getline(sv.hoten, 30);*/
	getline(cin, sv.hoten);
	cout << "\nNhap gioi tinh (1-Nam, 0-Nu): ";
	cin >> sv.GioiTinh;
	cout << "\nNhap ngay sinh: ";
	cin >> sv.NgaySinh.ng >> sv.NgaySinh.th >> sv.NgaySinh.nam;
	cout << "\nNhap diem: ";
	cin >> sv.Diem;
}

void NhapDSSV(List& l) {
	int n;
	cout << "\nNhap so luong sinh vien: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t\tNHAP SINH VIEN THU " << i + 1;
		SINHVIEN sv;
		Nhap1SV(sv);
		Node* p = KhoiTaoNode(sv);
		ThemCuoi(l, p);
	}
}

void Ghi1SV(ofstream& fileout, SINHVIEN sv) {
	fileout << sv.hoten << ", ";
	//fileout << sv.GioiTinh << ", ";
	if (sv.GioiTinh == 1) {
		fileout << "Nam, ";
	}
	else {
		fileout << "Nu, ";
	}
	fileout << sv.maso << ", ";
	fileout << sv.NgaySinh.ng << "/" << sv.NgaySinh.th << "/" << sv.NgaySinh.nam << ", ";
	fileout << sv.Diem;
}
void GhiDSSV(List& l) {
	ofstream fileout;
	fileout.open("DSSV.txt", ios::out);
	int dem = 1;
	for (Node* k = l.Head; k != NULL; k = k->Next) {
		Ghi1SV(fileout, k->data);
		fileout << endl;
	}
	fileout.close();
}

void Xuat1SV(SINHVIEN sv) {
	cout << "\nMa so: " << sv.maso;
	cout << "\nHo ten: " << sv.hoten;
	if (sv.GioiTinh == 1) cout << "\nGioi tinh: Nam";
	else cout << "\nGioi tinh: Nu";
	cout << "\nNgay sinh: " << sv.NgaySinh.ng << "/" << sv.NgaySinh.th << "/" << sv.NgaySinh.nam;
	cout << "\nDiem: " << sv.Diem;
}
void XuatDSSV(List l) {
	int dem = 1;
	for (Node* k = l.Head; k != NULL; k = k->Next) {
		cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << dem++;
		Xuat1SV(k->data);
	}
}
void DocNgaySinh(ifstream& filein, Ngay& date) {
	filein >> date.ng;
	filein.seekg(1, 1);
	filein >> date.th;
	filein.seekg(1, 1);
	filein >> date.nam;
}
void Doc1SV(ifstream& filein, SINHVIEN& sv) {
	//filein.getline(sv.hoten, 30, ',');
	getline(filein, sv.hoten, ',');
	filein.seekg(1, 1);
	/*filein >> sv.GioiTinh;
	filein.seekg(1, 1);*/
	/*filein.getline(sv.maso, 9, ',');*/
	filein >> sv.GioiTinh;
	filein.seekg(1, 1);
	getline(filein, sv.maso, ',');
	filein.seekg(1, 1);
	DocNgaySinh(filein, sv.NgaySinh);
	filein.seekg(2, 1);
	filein >> sv.Diem;
	string temp;
	getline(filein, temp);

}

void DocDSSV(ifstream& filein, List& l) {
	while (!filein.eof()) {
		SINHVIEN sv;
		Doc1SV(filein, sv);
		Node* p = KhoiTaoNode(sv);
		ThemCuoi(l, p);
	}
}
void SapXep(List& l) {
	for (Node* k = l.Head; k->Next != NULL; k = k->Next) {
		for (Node* h = k->Next; h != NULL; h = h->Next) {
			if (_stricmp(k->data.maso.c_str(), h->data.maso.c_str()) > 0) {
				swap(k->data, h->data);
			}
		}
	}
	cout << "\n=====DANH SACH SINH VIEN THEO MA SO TANG DAN=====";
	XuatDSSV(l);
}
void DiemTBDuoi5(List l) {
	for (Node* k = l.Head; k->Next != NULL; k = k->Next) {
		if (k->data.Diem < 5) {
			Xuat1SV(k->data);
		}
	}
}

void GhiFileSVDTBDuoi5(List l) {
	ofstream fileout;
	fileout.open("DIEMTRUNGBINHDUOI5.txt", ios::out);
	for (Node* k = l.Head; k != NULL; k = k->Next) {
		if (k->data.Diem < 5) {
			Ghi1SV(fileout, k->data);
			fileout << endl;
		}
	}
	fileout.close();
}
void XoaSV(List& l, string maso) {
	Node* h = NULL;
	for (Node* k = l.Head; k != NULL;) {
		if ((_stricmp(k->data.maso.c_str(), maso.c_str()) == 0) && (k == l.Head)) {
			l.Head = l.Head->Next;
			delete k;
			k = l.Head;
		}
		else {
			if (_stricmp(k->data.maso.c_str(), maso.c_str()) == 0) {
				h->Next = k->Next;
				delete k;
				k = h;

				if (h->Next == NULL) {
					l.Tail = h;
					return;
				}
			}
			h = k;
			k = k->Next;
		}
	}
}
void menu() {
	List l;
	KhoiTaoDS(l);
	bool kt = true;
	while (kt == true) {
		system("cls");
		cout << "\n\t-----------MENU---------";
		cout << "\n\t1.Nhap danh sach sinh vien";
		cout << "\n\t2.Xuat danh sach sinh vien";
		cout << "\n\t3.Ghi file DSSV vao tap tin";
		cout << "\n\t4.Doc DSSV tu file";
		cout << "\n\t5.Sap xep DSSV theo MSSV";
		cout << "\n\t6.Them 1 SV co ma so da cho vao danh sach";
		cout << "\n\t7.Xuat DSSV co diem trung binh duoi 5";
		cout << "\n\t8.Ghi DSSV co diem trung binh duoi 5 vao file";
		cout << "\n\t9.Xoa SV co ma so da cho ra khoi danh sach";
		cout << "\n\t0.Thoat";
		cout << "\n\t-----------END----------";

		int lc;
		cout << "\nNhap lua chon: ";
		cin >> lc;
		switch (lc) {
		case 1:
		{
			NhapDSSV(l);
			break;
		}
		case 2:
		{
			XuatDSSV(l);
			system("pause");
			break;
		}
		case 3:
		{
			GhiDSSV(l);
			cout << "\nDa ghi file thanh cong. Mo file DSSV.txt de kiem tra!";
			system("pause");
			break;
		}
		case 4:
		{
			ifstream filein;
			filein.open("SINHVIEN.txt", ios::in);
			DocDSSV(filein, l);
			XuatDSSV(l);
			filein.close();		
			system("pause");
			break;
		}
		case 5:
		{
			SapXep(l);
			system("pause");
			break;
		}
		case 6:
		{
			SINHVIEN sv;
			cout << "\nNhap thong tin sinh vien can them: ";
			Nhap1SV(sv);
			Node* p = KhoiTaoNode(sv);
			ThemCuoi(l, p);
			cout << "\n======DANH SACH SV SAU KHI THEM======\n";
			XuatDSSV(l);
			system("pause");
			break;
		}
		case 7:
		{
			cout << "\n======DANH SACH SINH VIEN CO DIEM TRUNG BINH DUOI 5======\n";
			DiemTBDuoi5(l);
			system("pause");
			break;
		}
		case 8:
		{
			GhiFileSVDTBDuoi5(l);
			cout << "\nDa ghi DSSV co DTB duoi 5 vao file. Mo file de kiem tra!";
			system("pause");
			break;
		}
		case 9:
		{
			string maso;
			cout << "\nNhap vao ma so sinh vien can xoa: ";
			cin >> maso;
			XoaSV(l, maso);
			cout << "\n======SAU KHI XOA======\n";
			XuatDSSV(l);
			system("pause");
			break;
		}
		case 0:
		{
			kt = false;
			break;
		}
		}
	}
}
int main() {
	//List l;
	//KhoiTaoDS(l);
	////NhapDSSV(l);
	//GhiDSSV(l);
	////XuatDSSV(l);
	//ifstream filein;
	//filein.open("SINHVIEN.txt", ios::in);
	//DocDSSV(filein, l);
	//XuatDSSV(l);
	//filein.close();
	menu();
	return 0;
}