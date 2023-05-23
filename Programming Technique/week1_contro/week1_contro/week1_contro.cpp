#include<iostream>
#include<string>
using namespace std;
struct Sach {
	string masach;
	string tensach;
	string tentacgia;
	string tennhaxuatban;
	double giaban;
	int sotrang, namxuatban;
};typedef struct Sach SACH;
void Nhap_Thong_Tin_1_Quyen_Sach(SACH &s) {
	while (getchar() != '\n');
	do {
		cout << "\nNhap ma sach: ";
		getline(cin, s.masach);
		if (s.masach.length() > 7) {
			cout << "\nDo dai khong hop le. Vui long nhap lai!";
		}
	} while (s.masach.length() > 7);
	do {
		cout << "\nNhap ten sach: ";
		getline(cin, s.tensach);
		if (s.tensach.length() > 50) {
			cout << "\nDo dai khong hop le. Vui long nhap lai!";
		}
	} while (s.tensach.length()>50);
	do {
		cout << "\nNhap ten tac gia: ";
		getline(cin, s.tentacgia);
		if (s.tentacgia.length() > 50) {
			cout << "\nDo dai khong hop le. Vui long nhap lai!";
		}
	} while (s.tentacgia.length() > 50);
	
	do {
		cout << "\nNhap ten nha xuat ban: ";
		getline(cin, s.tennhaxuatban);
		if (s.tennhaxuatban.length() > 50) {
			cout << "\nDo dai khong hop le. Vui long nhap lai!";
		}
	} while (s.tennhaxuatban.length()>50);
	cout << "\nNhap gia ban: ";
	cin >> s.giaban;
	cout << "\nNhap so trang: ";
	cin >> s.sotrang;
	cout << "\nNhap nam xuat ban: ";
	cin >> s.namxuatban;
}
void Nhap_DS_Sach(SACH s[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t\tNHAP THONG TIN QUYEN SACH THU " << i + 1;
		Nhap_Thong_Tin_1_Quyen_Sach(s[i]);
	}
}
void Xuat_Thong_Tin_1_Quyen_Sach(SACH s) {
	cout << "\nMa sach la: " << s.masach;
	cout << "\nTen sach la: " << s.tensach;
	cout << "\nTen tac gia la: " << s.tentacgia;
	cout << "\nTen nha xuat ban la: " << s.tennhaxuatban;
	cout << "\nGia ban la:" << s.giaban;
	cout << "\nSo trang la: " << s.sotrang;
	cout << "\nNam xuat ban la: " << s.namxuatban;
}
void Xuat_DS_Sach(SACH s[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\n\n\t\tTHONG TIN QUYEN SACH THU " << i + 1;
		Xuat_Thong_Tin_1_Quyen_Sach(s[i]);
	}
}
void Hoan_Vi(SACH& x, SACH& y) {
	SACH tam;
	tam = x;
	x = y;
	y = tam;
}
void Xap_Sep_Tang_Dan_Nam_Xuat_Ban(SACH s[], int n) {
	for (int i = 0; i < n-1; i++) {
		for (int j=i+1; j < n; j++) {
			if (s[i].namxuatban > s[j].namxuatban) {
				Hoan_Vi(s[i], s[j]);
			}
		}
	}
}
void Tim_Kiem_Theo_Yeu_Cau(SACH s[], int n, int k) {
	double max = s[0].giaban;
	for (int i = 1; i < n; i++) {
		if (s[i].giaban > max) {
			max = s[i].giaban;
		}
	}
	for (int i = 0; i < n; i++) {
		if (s[i].giaban == max && s[i].sotrang < k) {
			cout << "\n\n\t\tTHONG TIN QUYEN SACH CO GIA BAN CAO NHAT IT HON SO TRANG CAN TIM LA: ";
			Xuat_Thong_Tin_1_Quyen_Sach(s[i]);
		}
	}
}
void Them(SACH s[], int& n, int vt, SACH x) {
	for (int i = n - 1; i >= vt; i--) {
		s[i + 1] = s[i];
	}
	s[vt] = x;
	n++;
}
void Xoa(SACH s[], int& n, int vt) {
	for (int i = vt + 1; i < n; i++) {
		s[i - 1] = s[i];
	}
	n--;
}
void Xoa_Theo_Yeu_Cau(SACH s[], int& n, int nam) {
	for (int i = 0; i < n; i++) {
		if (s[i].namxuatban < nam) {
			Xoa(s, n, i);
			i--;
		}
	}
}
int main() {
	SACH s[100];
	int n;
	cout << "Nhap so luong quyen sach: ";
	cin >> n;
	cout << "\n\n\t\tNHAP DANH SACH CAC QUYEN SACH\n\n\t\t";
	Nhap_DS_Sach(s,n);
	Xuat_DS_Sach(s, n);
	Xap_Sep_Tang_Dan_Nam_Xuat_Ban(s, n);
	cout << "\n\n\t\tDANH SACH XAP SEP TANG DAN THEO NAM XUAT BAN LA: ";
	Xuat_DS_Sach(s, n);
	int vt;
	SACH x;
	cout << "\nNhap vi tri can them: ";
	cin >> vt;
	cout << "\nNhap thong tin sach can them: ";
	Nhap_Thong_Tin_1_Quyen_Sach(x);
	Them(s, n, vt, x);	
	
	int nam;
	cout << "\nNhap vao nam chi dinh: ";
	cin >> nam;
	Xoa_Theo_Yeu_Cau(s, n, nam);
	cout << "\n\n\t\tDANH SACH SAU KHI XOA CAC QUYEN SACH XUAT BAN TRUOC NAM CHI DINH LA: ";
	Xuat_DS_Sach(s, n);

	int k;
	cout << "Nhap vao so trang theo yeu cau: ";
	cin >> k;
	Tim_Kiem_Theo_Yeu_Cau(s, n, k);
	system("pause");
	return 0;
}