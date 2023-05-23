#include <iostream>
#include <string>

using namespace std;
typedef struct {
	char id[9];
	char name[20];
	float Marks[3];
	float DTB;
}Student;


// a) Hàm xếp loại sinh viên
void XepLoai(Student sv) {
	if (sv.DTB < 5) {
		cout << "Yeu" << endl;
	}
	if (sv.DTB >= 5 && sv.DTB < 7) {
		cout << "Trung binh" << endl;
	}
	if (sv.DTB >= 7 && sv.DTB < 8) {
		cout << "Kha" << endl;
	}
	if (sv.DTB >= 8) {
		cout << "Gioi" << endl;
	}
}

// b) Hàm nhập danh sách sinh viên

//Khởi tạo mảng động
void SvInit(Student*& ds, int& n) {
	ds = new Student[n]; //Cấp phát bộ nhớ cho mảng động
}

//Hàm nhập thông tin 1 sinh viên
void Nhap_SV(Student& sv) {
	cout << "\nNhap ma so sinh vien: ";
	cin >> sv.id;
	cout << "\nNhap ten sinh vien: ";
	cin.ignore();
	cin.getline(sv.name, 20);
	cout << "\nNhap diem bai tap, diem giua ky, diem cuoi ky:";
	for (int i = 0; i < 3; i++) {
		cout << "\nMarks[" << i << "] = ";
		cin >> sv.Marks[i];
	}
	sv.DTB = float(sv.Marks[0] * 0.25 + sv.Marks[1] * 0.25 + sv.Marks[2] * 0.5);
}

// Hàm nhập danh sách sinh viên
void NhapDS_SV(Student*& ds, int& n) {
	//Nhap thong tin tung sinh vien
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t\tNHAP THONG TIN SINH VIEN THU " << i + 1;
		Nhap_SV(ds[i]);
		cout << endl;
	}
}

// c) Hàm xuất danh sách sinh viên có thông tin xếp loại 

// Hàm xuất thông tin 1 sinh viên
void Xuat_SV(Student sv) {
	cout << "\nMa so sinh vien: " << sv.id << endl;
	cout << "\nTen sinh vien: " << sv.name << endl;
	cout << "\nDiem bai tap, diem giua ky, diem cuoi ky lan luot la: ";
	for (int i = 0; i < 3; i++) {
		cout << sv.Marks[i] << " ";
	}
	cout << endl;
	cout << "\nXep loai: ";
	XepLoai(sv);
}

// Hàm xuất danh sách sinh viên có xếp loại
void XuatDS_SV(Student* ds, int n) {
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << i + 1;
		Xuat_SV(ds[i]);
		cout << endl;
	}
}

// d) Hàm thêm 1 sinh viên vào vị trí bất kỳ
void ThemSv(Student*& ds, int vitri, int& n) {
	n++;
	// Cấp phát bộ nhớ cho sinh viên thêm vào
	Student* a = (Student*)realloc(ds, n * sizeof(Student));
	if (a != NULL) {
		// Thêm thông tin sinh viên vào danh sách
		for (int i = n - 1; i >= vitri; i--) {
			a[i] = a[i - 1];
		}
		cout << "\nThem thong tin sinh vien thu " << vitri << endl;
		Nhap_SV(a[vitri]);
		ds = a;
	}
}


// e) Hàm xóa sinh viên có điểm trung bình dưới 5

//Hàm xóa sinh viên ở vị trí bất kỳ
void XoaSV(Student*& ds, int vt_xoa, int& n) {
	for (int i = vt_xoa + 1; i < n; i++) {
		ds[i - 1] = ds[i];
	}
	n--;
}

void ThuHep(Student*& ds, int& n) {
	// Sau khi xóa đi 1 phần tử, cần thu hẹp vùng nhớ về 1 ô nhớ
	Student* temp = new Student[n];
	for (int i = 0; i < n; i++) {
		temp[i] = ds[i];
	}
	delete[] ds;
	ds = new Student[n];
	for (int i = 0; i < n; i++) {
		ds[i] = temp[i];
	}
	delete[] temp;
}

void XoaSVDuoi5(Student*& ds, int& n) {
	for (int i = 0; i < n; i++) {
		if (ds[i].DTB < 5) {
			XoaSV(ds, i, n);
			i--;
			ThuHep(ds, n);
		}
	}
}
int main()
{
	Student* sv = NULL;
	int vt = 0; 
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	cout << "\n\n\t\tNHAP DANH SACH SINH VIEN: ";
	NhapDS_SV(sv, n);
	cout << "\n\n\t\tXUAT DANH SACH SINH VIEN:" << endl;
	XuatDS_SV(sv, n);
	cout << "Nhap vao vi tri can them: ";
	cin >> vt;

	ThemSv(sv, vt, n);
	cout << "\n\n\t\tDANH SACH SINH VIEN SAU KHI THEM: " << endl;
	XuatDS_SV(sv, n);

	XoaSVDuoi5(sv, n);
	cout << "\n\n\t\tDANH SACH SINH VIEN SAU KHI XOA CAC SINH VIEN CO DIEM TRUNG BINH NHO HON 5: ";
	XuatDS_SV(sv, n);
	// Giải phóng bộ nhớ mảng động
	delete[] sv;
	return 0;
}