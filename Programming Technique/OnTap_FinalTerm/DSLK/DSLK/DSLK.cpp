#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct date {
	int ngay;
	int thang; 
	int nam;
}; typedef struct date DATE;
struct sinhvien {
	string hoten;
	string masv;
	DATE ngaysinh;
	float dtb;
}; typedef struct sinhvien SINHVIEN;
void Doc_Ngay_Thang_Nam(ifstream &filein, DATE &date) {
	filein >> date.ngay;
	filein.seekg(1, 1);
	filein >> date.thang;
	filein.seekg(1, 1);
	filein >> date.nam;
}
struct node {
	SINHVIEN data;
	struct node* pNext;
}; typedef struct node NODE;
struct list {
	NODE* pHead;
	NODE* pTail;
}; typedef struct list LIST;
void KhoiTaoDanhSach(LIST& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE* KhoiTaoNode(SINHVIEN x) {
	NODE* p = new NODE;
	if (p == NULL) {
		cout << "\nCap phat that bai!";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void ThemDau(LIST& l, NODE* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void ThemCuoi(list& l, NODE* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Doc_Thong_Tin_1_SV(ifstream& filein, SINHVIEN& sv) {
	getline(filein, sv.hoten,',');
	filein.seekg(1, 1);
	getline(filein, sv.masv, ',');
	filein.seekg(1, 1);
	Doc_Ngay_Thang_Nam(filein, sv.ngaysinh);
	filein.seekg(2, 1);
	filein >> sv.dtb;
	string temp;
	getline(filein, temp);
}
void Doc_DSSV(ifstream& filein, LIST& l) {
	while (!filein.eof()) {
		SINHVIEN sv;
		Doc_Thong_Tin_1_SV(filein, sv);
		NODE* p = KhoiTaoNode(sv);
		ThemCuoi(l, p);
	}
}
void GiaiPhong(LIST &l) {
	NODE* p = NULL;
	while (l.pHead != NULL) {
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void Ghi_Thong_Tin_1_SV(ofstream &fileout, SINHVIEN sv) {
	fileout << sv.hoten << ", ";
	fileout << sv.masv << ", ";
	fileout << sv.ngaysinh.ngay<<"/"<<sv.ngaysinh.thang<<"/"<<sv.ngaysinh.nam<< ", ";
	fileout << sv.dtb;
}
void HoanVi(SINHVIEN& x, SINHVIEN& y) {
	SINHVIEN tam = x;
	x = y;
	y = tam;
}
void SapXepTangDan(LIST& l) {
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		for (NODE* h = k->pNext; h != NULL; h = h->pNext) {
			if (k->data.dtb > h->data.dtb) {
				HoanVi(k->data, h->data);
			}
		}
	}
}
void LuuFileSapXepTangDanDTB(LIST l) {
	ofstream fileout;
	fileout.open("SAPXEPDIEMMAX.txt", ios::out);
	SapXepTangDan(l);
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		Ghi_Thong_Tin_1_SV(fileout, k->data);
		fileout << endl;
	}
	fileout.close();
}
void GhiFileSVDTBMax(LIST l) {
	float max = l.pHead->data.dtb;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data.dtb > max) {
			max = k->data.dtb;
		}
	}
	ofstream fileout;
	fileout.open("DIEMTRUNGBINHMAX.txt",ios::out);
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		if (max==k->data.dtb) {
			Ghi_Thong_Tin_1_SV(fileout, k->data);
			fileout << endl;
		}
	}
	fileout.close();
}
string Ten_SV(string tensv) {
	int length = tensv.length();
	int i;
	for (i = length - 1; i >= 0; i--) {
		if (tensv[i] == ' ') {
			break;
		}
	}
	return tensv.substr(i + 1);
}
void Xuat(SINHVIEN sv) {
	cout << "\nHo ten: " << sv.hoten;
	cout << "\nMa sinh vien: " << sv.masv;
	cout << "\nNgay sinh: " << sv.ngaysinh.ngay << "/" << sv.ngaysinh.thang << "/" << sv.ngaysinh.nam;
	cout << "\nDTB: " << sv.dtb;
}

void Xuat_DSSV(LIST l) {
	int dem = 1;
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		cout << "\n\n\t\tSINH VIEN THU " << dem++;
		Xuat(k->data);
	}
}
void TimKiemSVDuaVaoTen(LIST l, string tensv) {
	for (NODE* k = l.pHead; k != NULL; k = k->pNext) {
		string ten = Ten_SV(k->data.hoten);
		if (_stricmp((char*)ten.c_str(), (char*)tensv.c_str()) == 0) {
			Xuat(k->data);
			cout << endl;
		}
	}
}
void XoaSV(LIST& l, string maso) {
	NODE* h = NULL;
	for (NODE* k = l.pHead; k != NULL;) {
		if ((_stricmp(k->data.masv.c_str(), maso.c_str()) == 0) && (k == l.pHead)) {
			l.pHead = l.pHead->pNext;
			delete k;
			k = l.pHead;
		}
		else {
			if (_stricmp(k->data.masv.c_str(), maso.c_str()) == 0) {
				h->pNext = k->pNext;
				delete k;
				k = h;

				if (h->pNext == NULL) {
					l.pTail = h;
					return;
				}
			}
			h = k;
			k = k->pNext;
		}
	}
}
void menu() {
	LIST l;
	KhoiTaoDanhSach(l);
	bool kt = true;
	while (kt == true) {
		system("cls");
		cout << "\n\t--MENU--";
		cout << "\n\t1.Doc file";
		cout << "\n\t2.Sap xep";
		cout << "\n\t3.Tim ten";
		cout << "\n\t4.Xoa";
		int lc;
		cout << "\nNhap lua chon: ";
		cin >> lc;
		switch (lc) {
		case 1:
		{
			ifstream filein;
			filein.open("SINHVIEN.txt", ios::in);
			//Doc_Thong_Tin_1_SV(filein, sv);
			//Xuat(sv);
			Doc_DSSV(filein, l);
			Xuat_DSSV(l);
			filein.close();
			system("pause");
			break;
		}
		case 2:
		{
			LuuFileSapXepTangDanDTB(l);
			GhiFileSVDTBMax(l);
			system("pause");
			break;
		}
		case 3:
		{
			string tensv;
			cout << "\nNhap ho ten sinh vien can tim kiem: ";
			cin.ignore();
			getline(cin, tensv);
			TimKiemSVDuaVaoTen(l, tensv);
			system("pause");
			break;
		}
		case 4:
		{
			string maso;
			cout << "\nNhap vao ma so sinh vien can xoa: ";
			cin >> maso;
			XoaSV(l, maso);
			cout << "\n======SAU KHI XOA======\n";
			Xuat_DSSV(l);
			system("pause");
			break;
		}
		}
	}
}
int main() {
	//SINHVIEN sv;
	//LIST l;
	//KhoiTaoDanhSach(l);
	//ifstream filein;
	//filein.open("SINHVIEN.txt",ios::in);
	///*Doc_Thong_Tin_1_SV(filein, sv);
	//Xuat(sv);*/
	//Doc_DSSV(filein, l);
	//Xuat_DSSV(l);
	//LuuFileSapXepTangDanDTB(l);
	//GhiFileSVDTBMax(l);
	//string tensv;
	//cout << "\nNhap ho ten sinh vien can tim kiem: ";
	//getline(cin, tensv);
	//TimKiemSVDuaVaoTen(l, tensv);
	//GiaiPhong(l);
	//filein.close();
	menu();
	return 0;
}