#include<iostream>
#include<string.h>
using namespace std;
typedef struct SinhVien {
	char maso[9]; 
	char hoten[40];
	float dtb;
}SINHVIEN;
typedef struct DSSV {
	int size;
	SINHVIEN* dssv;
}DSSV;

//Khởi tạo mảng động
void SvInit(DSSV& ds, int n) {
	ds.size = n;
	ds.dssv = new SINHVIEN[n]; //Cấp phát bộ nhớ cho mảng động
}

/*1. Nhập xuất danh sách sinh viên, có chuẩn hóa họ tên */

void XoaKyTu(char* s, int vt_xoa) {
	int length = strlen(s);
	if (vt_xoa >= 0 && vt_xoa < length) {
		for (int i = vt_xoa + 1; i < length; i++) {
			s[i - 1] = s[i];
		}
		s[length - 1] = '\0'; // Xóa đi 1 ký tự
	}
}
// Hàm xóa tất cả các khoảng trắng thừa ở đầu
void XoaKhoangTrangDau(char* s) {
	int i = 0;
	while (s[i] == ' ') {
		XoaKyTu(s, i--);
		i++;
	}
}
// Hàm xóa tất cả các khoảng trắng thừa ở cuối
void XoaKhoangTrangCuoi(char* s) {
	int length = strlen(s);
	int i = length - 1;
	while (s[i] == ' ') {
		XoaKyTu(s, i);
		i--;
	}
}
// Hàm xóa khoảng trắng thừa giữa 2 từ
void XoaKhoangTrangGiua(char* s) {
	int length = strlen(s);
	for (int i = 0; i < length - 1; i++) {
		if (s[i] == ' ' && s[i + 1] == ' ') {
			XoaKyTu(s, i--);
			length--; // Cập nhật lại độ dài
		}
	}
}
// Hàm in hoa chữ cái đầu của mỗi từ trong họ tên
void ChuanHoa(char* s)
{
	int length = strlen(s);
	if (s[0] >= 'a' && s[0] <= 'z') {
		s[0] -= 32;
	}
	for (int i = 1; i < length; i++) {
		if (s[i] != ' ') {
			if (s[i - 1] == ' ') { // s[i] là ký tự đầu tiên của từ => chữ Hoa
				if (s[i] >= 'a' && s[i] <= 'z') {
					s[i] -= 32;
				}
			}
			else { // s[i] không phải là ký tự đầu tiên của từ => chữ thường
				if (s[i] >= 'A' && s[i] <= 'Z') {
					s[i] += 32;
				}
			}
		}
	}
}


// Hàm nhập thông tin 1 sinh viên
void Nhap_SV(SINHVIEN& sv) {
	do {
		cout << "\nNhap ma so sinh vien: ";
		cin>>sv.maso;
		if (strlen(sv.maso) != 8) {
			cout << "\nMa so sinh vien khong hop le. Moi ban nhap lai! \n";
		}
	} while (strlen(sv.maso) != 8);	
	cin.ignore();
	cout << "\nNhap ho ten sinh vien: ";
	cin.getline(sv.hoten, 40);
	XoaKhoangTrangDau(sv.hoten);
	XoaKhoangTrangCuoi(sv.hoten);
	XoaKhoangTrangGiua(sv.hoten);
	ChuanHoa(sv.hoten);
	cout << "\nNhap diem trung binh: ";
	cin >> sv.dtb;
}

// Hàm nhập danh sách sinh viên
void NhapDS_SV(DSSV &ds) {
	for (int i = 0; i < ds.size; i++) {
		cout << "\n\n\t\tNHAP THONG TIN SINH VIEN THU " << i + 1;
		Nhap_SV(ds.dssv[i]);
		cout << endl;
	}
}

// Hàm xuất thông tin 1 sinh viên
void Xuat_SV(SINHVIEN sv) {
	cout << "\nMa so sinh vien: " << sv.maso;
	cout << "\nHo ten sinh vien: " << sv.hoten;
	cout << "\nDiem trung binh: " << sv.dtb;
}
// Hàm xuất danh sách sinh viên
void XuatDS_SV(DSSV ds) {
	for (int i = 0; i < ds.size; i++) {
		cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << i + 1;
		Xuat_SV(ds.dssv[i]);
		cout << endl;
	}
}
/*2.  Cho trước một chuỗi kí tự, kiểm tra xem chuỗi đó có xuất hiện trong Họ tên sinh viên không*/

bool KiemTraChuoiCon(DSSV& ds, char chuoicon[40]) {
	for (int i = 0; i < ds.size; i++) {
		char* kq = strstr(ds.dssv[i].hoten, chuoicon);
		if (kq != NULL) {
			return 1;
		}
		return 0;
	}
}
void ChuoiCon(DSSV& ds, char chuoicon[40]) {
	cout << "\nNhap vao chuoi can kiem tra: ";
	cin.ignore();
	cin.getline(chuoicon, 40);
	if (KiemTraChuoiCon(ds, chuoicon) == 1) {
		cout << "\nChuoi "<<chuoicon<< " co xuat hien trong ho ten. ";
	}
	else {
		cout << "\nChuoi "<<chuoicon <<" khong xuat hien trong ho ten. ";
	}
	system("pause");
}
/*3. Tìm sinh viên có điểm trung bình thấp nhất. */
void DiemTB_ThapNhat(DSSV &ds) {
	float min = ds.dssv[0].dtb;
	for (int i = 0; i < ds.size; i++) {
		if (ds.dssv[i].dtb < min) {
			min = ds.dssv[i].dtb;
		}
	}
	for (int i = 0; i < ds.size; i++) {
		if (ds.dssv[i].dtb == min) {
			Xuat_SV(ds.dssv[i]);
		}
	}
}
/*4. Sắp xếp danh sách sinh viên giảm dần theo điểm TB. */

void SapXepGiamDan_DTB(DSSV& ds) {
	for (int i = 0; i < ds.size - 1; i++) {
		for (int j = i + 1; j < ds.size; j++) {
			if (ds.dssv[i].dtb < ds.dssv[j].dtb) {
				SINHVIEN temp = ds.dssv[i];
				ds.dssv[i] = ds.dssv[j];
				ds.dssv[j] = temp;
			}
		}
	}
}

/*5. Sắp xếp sinh viên tăng dần theo mã số sinh viên*/
void SapXepTangDan_MSSV(DSSV& ds) {
	for (int i = 0; i < ds.size - 1; i++) {
		for (int j = i + 1; j < ds.size; j++) {
			if (strcmp(ds.dssv[i].maso,ds.dssv[j].maso)>0) {
				SINHVIEN temp = ds.dssv[i];
				ds.dssv[i] = ds.dssv[j];
				ds.dssv[j] = temp;
			}
		}
	}
}

/*6. Sắp xếp danh sách sinh viên tăng dần theo Tên */
void LayRaTen(char hoten[], char ten[]) {
	int k = 0; 
	int n = strlen(hoten);
	for (int i = n - 1; i >= 0; i--) {
		if (hoten[i] == ' ') {
			for (int j = i + 1; j < n; j++) {
				ten[k] = hoten[j];
				k++;
			}
			break;
		}
	}
	ten[k] = '\0';
}
void LayRaHo(char hoten[], char ho[]) {
	int k = 0; 
	int n = strlen(hoten);
	for (int i = 0; i < n - 1; i++) {
		if (hoten[i] == ' ') {
			for (int j = i + 1; j < n; j++) {
				ho[k] = hoten[j];
				k++;
			}
			break;
		}
	}
	ho[k] = '\0';
}

void SapXepTangDan_Ten(DSSV& ds) {
	for (int i = 0; i < ds.size - 1; i++) {
		for (int j = i + 1; j < ds.size; j++) {
			if (strcmp(ds.dssv[i].hoten, ds.dssv[j].hoten) > 0) {
				SINHVIEN temp = ds.dssv[i];
				ds.dssv[i] = ds.dssv[j];
				ds.dssv[j] = temp;
			}
		}
	}
}

/*7. Tìm 3 sinh viên có điểm trung bình cao nhất, nếu có nhiều sinh viên có cùng điểm 
trung bình cao nhất thì ưu tiên chọn các bạn sinh viên có mã số sinh viên nhỏ hơn.*/
void DiemTB_CaoNhat(DSSV& ds) {	
	SapXepGiamDan_DTB(ds);
	for (int i = 0; i < ds.size - 1; i++) {
		for (int j = i + 1; j < ds.size; j++) {
			if (ds.dssv[i].dtb == ds.dssv[j].dtb) {
				SapXepTangDan_MSSV(ds);
				SapXepGiamDan_DTB(ds);
			}			
		}
	}
	for (int i = 0; i < 3; i++) {
		Xuat_SV(ds.dssv[i]);
	}
}
int main()
{
	DSSV ds;
	int n;
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	SvInit(ds, n);
	cout << "\n\n\t\tNHAP DANH SACH SINH VIEN: ";
	NhapDS_SV(ds);
	cout << "\n\n\t\tXUAT DANH SACH SINH VIEN:" << endl;
	XuatDS_SV(ds);	
	char chuoicon[40];
	cout << "\n\n\t\tKIEM TRA CHUOI CON: ";
	ChuoiCon(ds, chuoicon);
	cout << "\n\n\t\tTHONG TIN SINH VIEN CO DIEM TRUNG BINH THAP NHAT: ";
	DiemTB_ThapNhat(ds);
	cout << "\n\n\t\tDANH SACH SINH VIEN GIAM DAN THEO DIEM TRUNG BINH: ";
	SapXepGiamDan_DTB(ds);
	XuatDS_SV(ds);
	cout << "\n\n\t\tDANH SACH SINH VIEN TANG DAN THEO MA SO SINH VIEN: ";
	SapXepTangDan_MSSV(ds);
	XuatDS_SV(ds);
	cout << "\n\n\t\tDANH SACH SINH VIEN TANG DAN THEO TEN: ";
	SapXepTangDan_Ten(ds);
	XuatDS_SV(ds);
	cout << "\n\n\t\tTHONG TIN 3 SINH VIEN CO DIEM TRUNG BINH CAO NHAT: ";
	DiemTB_CaoNhat(ds);
	delete[] ds.dssv;
}