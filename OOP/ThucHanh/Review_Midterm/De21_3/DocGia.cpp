#include "DocGia.h"

DocGia::DocGia() {
	MaDG = new char[10];
	HoTen = new char[50];
	NgayExpire = new char[11];
	SachMuon = 0;
	LoaiDG = new char[20];
}
//DocGia::DocGia(char* _maDG, char* _hoTen, char* _ngayExpire, int _sachMuon, char* _loaiDG) {
//	//MaDG = new char[strlen(_maDG) + 1];
//	MaDG = new char[10];
//
//	strcpy(MaDG, _maDG);
//	//HoTen = new char[strlen(_hoTen) + 1];
//	HoTen = new char[50];
//
//	strcpy(HoTen, _hoTen);
//	//NgayExpire = new char[strlen(_ngayExpire) + 1];
//	NgayExpire = new char[11];
//
//	strcpy(NgayExpire, _ngayExpire);
//	SachMuon = _sachMuon;
//	//LoaiDG = new char[strlen(_loaiDG) + 1];
//	LoaiDG = new char[20];
//
//	strcpy(LoaiDG, _loaiDG);
//}

DocGia::DocGia(const DocGia& dg) {
	//MaDG = new char[strlen(dg.MaDG) + 1];
	MaDG = new char[10];
	strcpy(MaDG, dg.MaDG);

	HoTen = new char[50];
	//HoTen = new char[strlen(dg.HoTen) + 1];
	strcpy(HoTen, dg.HoTen);

	//NgayExpire = new char[strlen(dg.NgayExpire) + 1];
	NgayExpire = new char[11];
	strcpy(NgayExpire, dg.NgayExpire);

	SachMuon = dg.SachMuon;

	LoaiDG = new char[20];
	//LoaiDG = new char[strlen(dg.LoaiDG) + 1];
	strcpy(LoaiDG, dg.LoaiDG);
}

 
// Destructor
DocGia::~DocGia() {
	delete[] MaDG;
	MaDG = NULL;
	delete[] HoTen;
	HoTen = NULL;
	delete[] NgayExpire;
	NgayExpire = NULL;
	delete[] LoaiDG;
	LoaiDG = NULL;
}

void DocGia::Nhap() {
	//while(getchar() != '\n');
	cout << "Nhap ma doc gia: ";
	cin.ignore();
	cin.getline(MaDG, 10);
	cout << "Nhap ho ten doc gia: ";
	cin.getline(HoTen, 50);
	cout << "Nhap ngay het han: ";
	cin.getline(NgayExpire, 11);
	cout << "Nhap so sach muon: ";
	cin >> SachMuon;
	cin.ignore();
	cout << "Nhap loai doc gia (Thuong - VIP): ";
	cin.getline(LoaiDG, 20);
}
void DocGia::Xuat() {
	cout << "\nMa doc gia: " << MaDG << endl;
	cout << "Ho ten doc gia: " << HoTen << endl;
	cout << "Ngay het han: " << NgayExpire << endl;
	cout << "So sach muon: " << SachMuon << endl;
	cout << "Loai doc gia: " << LoaiDG;
}
float DocGia::TinhPhi() {
	if (strcmp(LoaiDG,"Thuong")==0) {
		return SachMuon * 5000.0;
	}
	else if (strcmp(LoaiDG,"VIP")==0) {
		return 100000.0;
	}
}

bool DocGia::kiemTraHetHan(string ngayCanKiemTra) {
	int ngayHetHan, thangHetHan, namHetHan;
	int ngayKiemTra, thangKiemTra, namKiemTra;
	sscanf(NgayExpire, "%d/%d/%d", &ngayHetHan, &thangHetHan, &namHetHan);
	sscanf(ngayCanKiemTra.c_str(), "%d/%d/%d", &ngayKiemTra, &thangKiemTra, &namKiemTra);

	if (namHetHan < namKiemTra
		|| namHetHan == namKiemTra && thangHetHan < thangKiemTra
		|| namHetHan == namKiemTra && thangHetHan == thangKiemTra && ngayHetHan < ngayKiemTra) {
		return true;
	}
	return false;

}

