#include "NhanVien.h"
#include "NVCongNhat.h"
#include "NVSanXuat.h"


NhanVien::NhanVien() {
	strcpy(maNV, "");
	strcpy(hoTen, "");
	strcpy(diaChi, "");
	gioiTinh = false;
}
void NhanVien::nhap() {
    do {
        cout << "Nhap ma nhan vien (chuoi gom 5 ki tu so): ";
        cin >> maNV;
        if (strlen(maNV) != 5) {
            cout << "Ma nhan vien khong hop le" << endl;
        }
    } while (strlen(maNV) != 5);
    cout << "Nhap ho ten: ";
    cin.ignore();
    cin.getline(hoTen, 51);
    cout << "Nhap gioi tinh (0-Nam, 1-Nu): ";
    cin >> gioiTinh;
    do {
        ngaySinh.nhapNS();
        if (gioiTinh == 0 && (ngaySinh.tinhTuoi() < 18 || ngaySinh.tinhTuoi() > 60)) {
            cout << "Do tuoi hop le phai tu 18 - 60 tuoi." << endl;
        }
        if (gioiTinh == 1 && (ngaySinh.tinhTuoi() < 18 || ngaySinh.tinhTuoi() > 55)) {
            cout << "Do tuoi hop le phai tu 18 - 55 tuoi. " << endl;
        }
    } while ((gioiTinh == 0 && (ngaySinh.tinhTuoi() < 18 || ngaySinh.tinhTuoi() > 60))
        || (gioiTinh == 1 && (ngaySinh.tinhTuoi() < 18 || ngaySinh.tinhTuoi() > 55)));

    cout << "Nhap dia chi: ";
    cin.ignore();
    cin.getline(diaChi, 101);
}


void NhanVien::xuat() {
    cout << "Ma nhan vien: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    ngaySinh.xuatNS();
    cout << "Tuoi: " << ngaySinh.tinhTuoi() << endl;
    if (gioiTinh == 0) cout << "Gioi tinh: Nam" << endl;
    else cout << "Gioi tinh: Nu" << endl;
    cout << "Dia chi: " << diaChi << endl;
}

double NhanVien::tinhLuong() {
    return 0;
}

char* NhanVien::getMaNV() {
    return maNV;
}

char* NhanVien::getHoTen() {
    return hoTen;
}

NgaySinh NhanVien::getNgaySinh() {
    return ngaySinh;
}

void NhanVien::ghi(ofstream& file) {
    file.write(reinterpret_cast<char*>(this), sizeof(NhanVien));
}

void NhanVien::doc(ifstream& file) {
    file.read(reinterpret_cast<char*>(this), sizeof(NhanVien));
}


NhanVien& NhanVien::operator=(const NhanVien& other) {
    if (this != &other) {
        strcpy(hoTen, other.hoTen);
        strcpy(maNV, other.maNV);
        ngaySinh = other.ngaySinh;
        strcpy(diaChi, other.diaChi);
    }
    return *this;
}
