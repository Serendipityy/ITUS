#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct diem {
	float dai_so = 0;
	float Mac = 0;
	float cpp = 0;
}; typedef struct diem diem;
struct sinhvien {
	string ho;
	string ten;
	string ma_sv;
	string phai;
	diem ds_diem;
}; typedef struct sinhvien sv;
struct node_sv {
	sv data;
	node_sv* pnext;
}; typedef struct node_sv node_sv;
struct danh_sach_sv {
	node_sv* phead = NULL;
	node_sv* ptail = NULL;
}; typedef struct danh_sach_sv danh_sach_sv;

//---------------------
void menu();
istream& operator>>(istream& is, sv& a);
node_sv* khoi_tao_node(sv x);
void them(danh_sach_sv& ds_sv, sv x);
void xuat(danh_sach_sv ds_sv);
//void load_file(danh_sach_sv& ds_sv);
void xoa_sv(danh_sach_sv& ds_sv, string vt);
void sap_xep(danh_sach_sv& ds_sv);
//---------------------
istream& operator>>(istream& is, sv &a) {
	cout << "\nNhap ho: ";
	cin.ignore();
	getline(is, a.ho);
	cout << "\nNhap ten: ";
	getline(is, a.ten);
	cout << "\nNhap phai: ";
	getline(is, a.phai);
	cout << "\nNhap ma so sv: ";
	getline(is, a.ma_sv);
	cout << "\nNhap diem dai so: ";
	is >> a.ds_diem.dai_so;
	cout << "\nNhap diem Mac: ";
	is >> a.ds_diem.Mac;
	cout << "\nNhap diem C++: ";
	is >> a.ds_diem.cpp;
	return is;
}
node_sv *khoi_tao_node(sv x) { // x đã lưu data người dùng nhập vào
	node_sv* p = new node_sv;
	p->data = x;
	p->pnext = NULL;
	return p;
}
void them(danh_sach_sv &ds_sv, sv x) {
	node_sv* p = khoi_tao_node(x);
	if (ds_sv.phead == NULL) { // rỗng => đầu cuối = p
		ds_sv.phead = ds_sv.ptail = p;
	}
	else { // n phần tử => thêm cuối
		ds_sv.ptail->pnext = p;
		ds_sv.ptail = p;
	}
}
void xuat(danh_sach_sv ds_sv) {
	int i = 1;
	for (node_sv* k = ds_sv.phead; k != NULL; k = k->pnext) {
		cout << "\n\n\t\tSINH VIEN THU " << i++;
		cout << "\nMa so sinh vien: " << k->data.ma_sv;
		cout << "\nHo ten: " << k->data.ho << " " << k->data.ten;
		cout << "\nPhai: " << k->data.phai;
		cout << "\n----Diem----: ";
		cout << "\nDai so: " << k->data.ds_diem.dai_so;
		cout << "\nMac: " << k->data.ds_diem.Mac;
		cout << "\nC++ :" << k->data.ds_diem.cpp;

	}
}
//void load_file(danh_sach_sv &ds_sv) {
//	//ifstream filein("dslk.txt");
//	fstream filein;
//	filein.open("dslk.txt", ios::in);
//	// đọc file
//
//	while (filein.eof() == false) {
//		sv a; // để lưu tạm dữ liệu load từ file
//		getline(filein, a.ho, ',');
//		getline(filein, a.ten, ',');
//		getline(filein, a.ma_sv, ',');
//		getline(filein, a.phai, ',');
//		filein >> a.ds_diem.dai_so;
//		filein.ignore(); // bỏ dấu phẩy
//		filein >> a.ds_diem.Mac;
//		filein.ignore();
//		filein >> a.ds_diem.cpp;
//		filein.ignore(); // bỏ \n
//	// thêm
//		them(ds_sv, a);
//	}
//	filein.close();
//}
void xoa_sv(danh_sach_sv &ds_sv, string vt) { //vt là mssv cần tìm
	//C1: Sử dụng kỹ thuật 100% vt không nằm ở đầu
	//C2: thực hiện xóa đầu => for khuyết để không nhảy bước
	node_sv* h = NULL;
	for (node_sv* k = ds_sv.phead; k != NULL;) {
		if (_stricmp(k->data.ma_sv.c_str(), vt.c_str()) == 0 && k == ds_sv.phead) {
			// vt ở đầu =>xóa đầu
			ds_sv.phead = ds_sv.phead->pnext;
			delete k; // k vô định
			k = ds_sv.phead; // nhảy về đầu - nếu lên bước lặp => sót phần tử
			// không được nhảy bước => sử dụng for khuyết
		}
		else { // khác vt và bằng vt nhưng không phải đầu
			if (_stricmp(k->data.ma_sv.c_str(), vt.c_str()) == 0) { // so sánh bất kể in hoa in thường
				h->pnext = k->pnext;
				delete k; // vô định
				k = h; // nhảy lại: giữa/ vt liên tiếp/ vt cách xa
				if (h->pnext == NULL) { //h đang là cuối => chúng ta vừa xóa cuối
					ds_sv.ptail = h;
					return;
				}
			}
			h = k; // nhảy theo k = pt 2
			k = k->pnext;
		}
	}
}
void sap_xep(danh_sach_sv& ds_sv) { // hoán vị data
	for (node_sv* k = ds_sv.phead; k->pnext != NULL; k = k->pnext) { // áp cuối
		for (node_sv* h = k->pnext; h != NULL; h = h->pnext) {
			if (_stricmp(h->data.ten.c_str(), k->data.ten.c_str()) < 0) {
				swap(k->data, h->data);
			}
			else if (_stricmp(h->data.ten.c_str(), k->data.ten.c_str()) == 0) {
				if (_stricmp(h->data.ho.c_str(), k->data.ho.c_str()) < 0) {
					swap(k->data, h->data);
				}
			}
		}
	}
}
void menu() {
	//setting
	danh_sach_sv ds_sv;
	//load file
	/*load_file(ds_sv);*/
	//menu
	bool kt_menu = true;
	while (kt_menu == true) {
		system("cls");
		cout << "\n\t1.Nhap sinh vien";
		cout << "\n\t2.Xuat danh sach sinh vien";
		cout << "\n\t3.Xoa sinh vien co ma sinh vien nhap tu ban phim";
		cout << "\n\t4.Sap xep";
		cout << "\n\t0.Thoat";
		int lc;
		cout << "\nNhap lua chon: ";
		cin >> lc;
		switch (lc) {
		case 1:
		{
			int sl;
			cout << "\nNhap so luong sinh vien can them: ";
			cin >> sl;
	
			for (int i = 1; i <= sl; i++) {
				cout << "\n\n\t\tNHAP SINH VIEN THU " << i;
				// Thêm 1 sv vào danh sách
				sv x; //dùng để tạm lưu dữ liệu người dùng nhập vào
				cin >> x;
				them(ds_sv, x);
			}	
			break;
		}
		case 2:
		{
			xuat(ds_sv);
			system("pause");
			break;
		}
		case 3:
		{
			string vt;
			cout << "\nNhap ma sinh vien can xoa: ";
			cin.ignore();
			getline(cin, vt);
			xoa_sv(ds_sv, vt);
			break;

		}
		case 4:
		{
			sap_xep(ds_sv);
			break;
		}
		case 0:
		{
			kt_menu = false;
			break;
		}
		}
	}
}
int main() {
	menu();
	return 0;
}