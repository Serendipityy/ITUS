#include<iostream>
#include<fstream>
#include<string>
using namespace std;


struct SINHVIEN {
	string maso;
	string hoten;
	float Diem_LT = 0;
	float Diem_TH = 0;
	float Diem_TB = 0;
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
void ThemBatKi(List& l, Node* p, int vt, int n) {
	if (l.Head == NULL || vt == 1) {
		ThemDau(l, p);
	}
	else if (vt == n + 1) {
		ThemCuoi(l, p);
	}
	else {
		int dem = 0; // Để xác định vị trí cần thêm
		Node* g = new Node;
		for (Node* k = l.Head; k != NULL; k = k->Next) {
			// Tìm vị trí vt cần thêm
			dem++;
			if (dem == vt) {
				Node* h = KhoiTaoNode(p->data);
				h->Next = k;
				g->Next = h;
				break;
			}
			g = k;
		}
	}
}
void Nhap1SV(SINHVIEN& sv) {
	cout << "\nNhap ma so: ";
	cin.ignore();
	getline(cin, sv.maso);
	cout << "\nNhap ho ten: ";
	getline(cin, sv.hoten);
	cout << "\nNhap diem ly thuyet: ";
	cin >> sv.Diem_LT;
	cout << "\nNhap diem thuc hanh: ";
	cin >> sv.Diem_TH;
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

void Xuat1SV(SINHVIEN sv) {
	cout << "\nMa so: " << sv.maso;
	cout << "\nHo ten: " << sv.hoten;
	cout << "\nDiem ly thuyet: " << sv.Diem_LT;
	cout << "\nDiem thuc hanh: " << sv.Diem_TH;
	sv.Diem_TB = sv.Diem_LT * 0.7 + sv.Diem_TH * 0.3;
	cout << "\nDiem trung binh: " << sv.Diem_TB;
}
void XuatDSSV(List l) {
	int dem = 1;
	for (Node* k = l.Head; k != NULL; k = k->Next) {
		cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << dem++;
		Xuat1SV(k->data);
	}
}
void Doc1SV(ifstream& filein, SINHVIEN& sv) {
	//filein.getline(sv.hoten, 30, ',');
	getline(filein, sv.hoten, ',');
	filein.seekg(1, 1);
	/*filein >> sv.GioiTinh;
	filein.seekg(1, 1);*/
	/*filein.getline(sv.maso, 9, ',');*/
	getline(filein, sv.maso, ',');
	filein.seekg(1, 1);
	filein >> sv.Diem_LT;
	filein.seekg(1, 1);
	filein >> sv.Diem_TH;
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
		cout << "\n\t1.Danh sach sinh vien doc tu file";
		cout << "\n\t2.Xuat danh sach sinh vien";
		cout << "\n\t3.Sap xep DSSV theo MSSV";
		cout << "\n\t4.Them 1 SV vao vi tri bat ky trong danh sach";
		cout << "\n\t5.Xoa SV co ma so da cho ra khoi danh sach";
		cout << "\n\t0.Thoat";
		cout << "\n\t-----------END----------";

		int lc;
		cout << "\nNhap lua chon: ";
		cin >> lc;
		switch (lc) {
		case 1:
		{
			ifstream filein;
			filein.open("SINHVIEN.txt", ios::in);
			DocDSSV(filein, l);
			XuatDSSV(l);
			filein.close();
			system("pause");
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
			SapXep(l);
			system("pause");
			break;
		}
		case 4:
		{
			int n = 0; // Biến n để đếm số lượng phần tử
			for (Node* k = l.Head; k != NULL; k = k->Next) {
				n++;
			}
			SINHVIEN sv;
			cout << "\nNhap thong tin sinh vien can them: ";
			Nhap1SV(sv);
			Node* p = KhoiTaoNode(sv);
			int vt;
			do {
				cout << "\nNhap vi tri can them: ";
				cin >> vt;
				if (vt<1 || vt>n - 1) {
					cout << "\nVi tri can them khong hop le !";
					system("pause");
				}
			} while (vt <1 || vt > n - 1);
			ThemBatKi(l, p, vt,n);
			cout << "\n======DANH SACH SV SAU KHI THEM======\n";
			XuatDSSV(l);
			system("pause");
			break;
		}
		case 5:
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
	menu();
	return 0;
}