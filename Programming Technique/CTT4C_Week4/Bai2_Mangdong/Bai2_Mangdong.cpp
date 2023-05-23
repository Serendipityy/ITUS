#include<iostream>
#include<string>
using namespace std;

/* Ngay sinh */
typedef struct NgaySinh {
	int ngay;
	int thang;
	int nam;
}NGAYSINH;
/* Khai bao Sinh Vien */
typedef struct SinhVien {
	char maso[9];
	char hoten[40];
	NGAYSINH ngsinh;
	float diem;
}SINHVIEN;
/*5. Xếp loại sinh viên theo điểm*/
void XepLoai(SINHVIEN sv) {
	if (sv.diem < 5) {
		cout << "Yeu" << endl;
	}
	if (sv.diem >= 5 && sv.diem < 7) {
		cout << "Trung binh" << endl;
	}
	if (sv.diem >= 7 && sv.diem < 8) {
		cout << "Kha" << endl;
	}
	if (sv.diem >= 8) {
		cout << "Gioi" << endl;
	}
}
/*1. Cài đặt danh sách sinh viên*/
// Hàm khởi tạo mảng động
void SVInit(SINHVIEN*& ds, int& n) {
	ds = new SINHVIEN[n]; // Cấp phát bộ nhớ cho mảng động
}
// Hàm nhập thông tin 1 sinh viên
void NhapSV(SINHVIEN& sv) {
	cout << "\nNhap ma so sinh vien: ";
	cin.ignore();
	cin.getline(sv.maso, 9);
	cout << "\nNhap ho ten sinh vien: ";
	cin.getline(sv.hoten, 40);
	cout << "\nNhap ngay thang nam sinh: ";
	cin >> sv.ngsinh.ngay >> sv.ngsinh.thang >> sv.ngsinh.nam;
	cout << "\nNhap diem: ";
	cin >> sv.diem;
}
// Hàm nhập danh sách sinh viên
void Nhap_DSSV(SINHVIEN*& ds, int& n) {
	// Gọi hàm khởi tạo
	SVInit(ds, n);
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t\tNHAP THONG TIN SINH VIEN THU " << i + 1;
		NhapSV(ds[i]);
	}
}
// Hàm xuất thông tin 1 sinh viên
void XuatSV(SINHVIEN sv) {
	cout << "\nMa so sinh vien: " << sv.maso;
	cout << "\nHo ten sinh vien: " << sv.hoten;
	cout << "\nNgay thang nam sinh: " << sv.ngsinh.ngay << "/" << sv.ngsinh.thang << "/" << sv.ngsinh.nam;
	cout << "\nDiem: " << sv.diem;
	cout << "\nXep loai: ";
	XepLoai(sv);
}
// Hàm xuất danh sách sinh viên
void XuatDSSV(SINHVIEN*& ds, int& n) {
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << i + 1;
		XuatSV(ds[i]);
	}
}
/*2. Đếm số node của danh sách*/

/*3. Thêm một sinh viên có mã số sinh viên đã cho vào danh sách*/
// Hàm mở rộng vùng nhớ
void ThemVungNho(SINHVIEN*& ds, int& n) {
	// Tạo mảng phụ temp chứa các phần tử của ds
	SINHVIEN* temp = new SINHVIEN[n];
	for (int i = 0; i < n; i++) {
		temp[i] = ds[i]; // Bỏ các phần tử của mảng ds sang mảng temp
	}
	delete[] ds; // Giải phóng vùng nhớ cũ của ds

	// Cấp phát lại vùng nhớ mới cho ds với số lượng phần tử tăng lên 1 ô nhớ
	ds = new SINHVIEN[n+1];
	for (int i = 0; i < n; i++) {
		ds[i] = temp[i]; // Bỏ các phần tử của mảng temp về lại mảng ds
	}
	delete[] temp; // Giải phóng vùng nhớ temp khi không dùng nữa
}
// Thuật toán thêm
void ThemSV(SINHVIEN*& ds, int& n, int vitrithem, SINHVIEN &x) {
	ThemVungNho(ds, n);
	for (int i = n - 1; i >= vitrithem; i--) {
		ds[i + 1] = ds[i];
	}
	ds[vitrithem] = x;
	n++;
}

/*4. Tính điểm trung bình của danh sách*/
float TinhDTB(SINHVIEN*& ds, int& n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + ds[i].diem;
	}
	float tb = sum / n;
	return tb;
}
/*6. Lưu các sinh viên có điểm nhỏ hơn điểm trung bình vào một mảng động*/
void LuuVaoMangDong(SINHVIEN*& a, SINHVIEN* ds, int n, int& nSV) {
	int k = 0;
	float tb = TinhDTB(ds, n);
	for (int i = 0; i < n; i++) {
		if (ds[i].diem < tb) {
			nSV++;
		}
	}
	SVInit(ds, n);
	for (int i = 0; i < n; i++) {
		if (ds[i].diem < tb) {
			a[k] = ds[i];
			k++;
		}
	}
}
/*7. Xóa một sinh viên có mã số sinh viên đã cho khỏi danh sách*/
// Thuật toán xóa
void XoaSV(SINHVIEN*& ds, int vitrixoa, int& n) {
	for (int i = vitrixoa + 1; i < n; i++) {
		ds[i - 1] = ds[i];
	}
	n--;
}
void ThuHep(SINHVIEN*& ds, int& n) {
	SINHVIEN* temp = new SINHVIEN[n];
	for (int i = 0; i < n; i++) {
		temp[i] = ds[i];
	}
	delete[] ds;
	ds = new SINHVIEN[n];
	for (int i = 0; i < n; i++) {
		ds[i] = temp[i];
	}
	delete[] temp;
}
// Xóa sinh viên theo MSSV
void XoaTheoMSSV(SINHVIEN*& ds, int& n, char maso[9]) {
	for (int i = 0; i < n; i++) {
		if (strcmp(ds[i].maso, maso) == 0) {
			XoaSV(ds, i, n);
			i--;
			ThuHep(ds, n);
		}
	}
}
/*8. Sắp xếp danh sách tăng dần theo mã số sinh viên*/
void SapXep(SINHVIEN*& ds, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(ds[i].maso, ds[j].maso) > 0) {
				SINHVIEN temp = ds[i];
				ds[i] = ds[j];
				ds[j] = temp;
			}
		}
	}
}
int main() {
	SINHVIEN *sv = NULL;
	int n;
	cout << "\nNhap so luong sinh vien: ";
	cin >> n;
	cout << "\n\n\t\tNHAP DANH SACH SINH VIEN: \n";
	Nhap_DSSV(sv, n);
	cout << "\n\n\t\tDANH SACH SINH VIEN: \n";
	XuatDSSV(sv, n);
	cout << "\n\n\t\tTHEM SINH VIEN: \n";
	SINHVIEN x;
	int vitrithem;
	cout << "\nNhap vao vi tri can them: ";
	cin >> vitrithem;
	NhapSV(x);
	ThemSV(sv, n, vitrithem, x);
	cout << "\nDanh sach sinh vien sau khi them: ";
	XuatDSSV(sv, n);
	cout << "\n\n\t\tDIEM TRUNG BINH CUA DANH SACH: " << TinhDTB(sv, n);
	cout << "\nDANH SACH SINH VIEN CO XEP LOAI: ";
	XuatDSSV(sv, n);
	//SINHVIEN* a = NULL;
	//int nSV;
	//cout << "\n\n\t\tLUU CAC SINH VIEN CO DIEM NHO HON DIEM TRUNG BINH VAO MANG DONG: \n";
	//LuuVaoMangDong(a, sv, n, nSV);
	//XuatDSSV(a, n);
	char maso[9];
	cout << "\nNhap ma so sinh vien can xoa: ";
	cin >> maso;
	XoaTheoMSSV(sv, n, maso);
	cout << "\nDANH SACH SINH VIEN SAU KHI XOA SINH VIEN CO MA SO " << maso << " LA: ";
	XuatDSSV(sv, n);
	SapXep(sv, n);
	cout << "\nDANH SACH SINH VIEN TANG DAN THEO MA SO SINH VIEN: ";
	XuatDSSV(sv, n);
	delete[] sv;
}