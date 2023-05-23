#include "CongTy.h"


NhanVien::NhanVien() {
    maNV = "";
    hoTen = "";
    ngaySinh = "";
    diaChi = "";
}
NhanVien::NhanVien(string ma, string ten, string ngay, string diaChi) {
    maNV = ma;
    hoTen = ten;
    ngaySinh = ngay;
    this->diaChi = diaChi;
}
void NhanVien::nhapThongTin() {
    cout << "Nhap ma nhan vien: ";
    cin.ignore();
    getline(cin, maNV);
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);
    cout << "Nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
    cout << "Nhap dia chi: ";
    getline(cin, diaChi);
}
void NhanVien::xuatThongTin() {
    cout << "Ma nhan vien: " << maNV << endl;
    cout << "Ho ten: " << hoTen << endl;
    cout << "Ngay sinh: " << ngaySinh << endl;
    cout << "Dia chi: " << diaChi << endl;
}
string NhanVien::getMaNV() {
    return maNV;
}
string NhanVien::getTenNV() {
    return hoTen;
}
string NhanVien::getNgaySinh() {
    return ngaySinh;
}




NVSanXuat::NVSanXuat() {
    soSanPham = 0;
}
NVSanXuat::NVSanXuat(string ma, string ten, string ngay, string diaChi, int soSP) : NhanVien(ma, ten, ngay, diaChi) {
    soSanPham = soSP;
}
void NVSanXuat::nhapThongTin() {
    NhanVien::nhapThongTin();
    cout << "Nhap so san pham: ";
    cin >> soSanPham;
    cin.ignore();
}
void NVSanXuat::xuatThongTin() {
    cout << "Nhan vien san xuat" << endl;
    NhanVien::xuatThongTin();
    cout << "So san pham: " << soSanPham << endl;
}
double NVSanXuat::tinhLuong() {
    return soSanPham * 20000.0;
}



NVCongNhat::NVCongNhat() {
    soNgay = 0;
}
NVCongNhat::NVCongNhat(string ma, string ten, string ngay, string diaChi, int soNgay) : NhanVien(ma, ten, ngay, diaChi) {
    this->soNgay = soNgay;
}
void NVCongNhat::nhapThongTin() {
    NhanVien::nhapThongTin();
    cout << "Nhap so ngay lam viec: ";
    cin >> soNgay;
    cin.ignore();
}
void NVCongNhat::xuatThongTin() {
    cout << "Nhan vien cong nhat" << endl;
    NhanVien::xuatThongTin();
    cout << "So ngay lam viec: " << soNgay << endl;
}
double NVCongNhat::tinhLuong() {
    return soNgay * 300000.0;
}



CongTy::CongTy() {}
CongTy::CongTy(const CongTy& ct) { // Constructor sao chép
    for (int i = 0; i < ct.danhSachNV.size(); i++) {
        if (dynamic_cast<NVSanXuat*>(ct.danhSachNV[i])) {
            danhSachNV.push_back(new NVSanXuat(*dynamic_cast<NVSanXuat*>(ct.danhSachNV[i])));
        }
        else if (dynamic_cast<NVCongNhat*>(ct.danhSachNV[i])) {
            danhSachNV.push_back(new NVCongNhat(*dynamic_cast<NVCongNhat*>(ct.danhSachNV[i])));
        }
    }
}
CongTy& CongTy::operator=(const CongTy& ct) { // Toán tử gán bằng
    if (this != &ct) {
        // Xóa các phần tử cũ
        for (int i = 0; i < danhSachNV.size(); i++) {
            delete danhSachNV[i];
        }
        danhSachNV.clear();
        // Thêm các phần tử mới
        for (int i = 0; i < ct.danhSachNV.size(); i++) {
            if (dynamic_cast<NVSanXuat*>(ct.danhSachNV[i])) {
                danhSachNV.push_back(new NVSanXuat(*dynamic_cast<NVSanXuat*>(ct.danhSachNV[i])));
            }
            else if (dynamic_cast<NVCongNhat*>(ct.danhSachNV[i])) {
                danhSachNV.push_back(new NVCongNhat(*dynamic_cast<NVCongNhat*>(ct.danhSachNV[i])));
            }
        }
    }
    return *this;
}
CongTy::~CongTy() { // Destructor
    for (int i = 0; i < danhSachNV.size(); i++) {
        delete danhSachNV[i];
    }
    danhSachNV.clear();
}

void CongTy::docNV(string fileName) {
    ifstream fileIn(fileName);
    if (!fileIn.is_open()) {
        cout << "Khong mo duoc file de doc!" << endl;
        return;
    }
    string line;
    while (getline(fileIn, line)) {
        stringstream ss(line);
        string loaiNV;
        getline(ss, loaiNV, ',');
        if (loaiNV == "SX") {
            string maNV, hoTen, ngaySinh, diaChi, soSanPhamStr;
            getline(ss, maNV, ',');
            getline(ss, hoTen, ',');
            getline(ss, ngaySinh, ',');
            getline(ss, diaChi, ',');
            getline(ss, soSanPhamStr);
            int soSanPham = stoi(soSanPhamStr);
            danhSachNV.push_back(new NVSanXuat(maNV, hoTen, ngaySinh, diaChi, soSanPham));
        }
        else if (loaiNV == "CN") {
            string maNV, hoTen, ngaySinh, diaChi, soNgayStr;
            getline(ss, maNV, ',');
            getline(ss, hoTen, ',');
            getline(ss, ngaySinh, ',');
            getline(ss, diaChi, ',');
            getline(ss, soNgayStr);
            int soNgay = stoi(soNgayStr);
            danhSachNV.push_back(new NVCongNhat(maNV, hoTen, ngaySinh, diaChi, soNgay));
        }
    }
    fileIn.close();
}

void CongTy::nhap() { // Nhập danh sách nhân viên
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int loai;
        cout << "Nhap loai nhan vien (1: Nhan vien san xuat, 2: Nhan vien cong nhat): ";
        cin >> loai;
        if (loai == 1) {
            NVSanXuat* nv = new NVSanXuat();
            nv->nhapThongTin();
            danhSachNV.push_back(nv);
        }
        else if (loai == 2) {
            NVCongNhat* nv = new NVCongNhat();
            nv->nhapThongTin();
            danhSachNV.push_back(nv);
        }
    }
}
void CongTy::xuat() { // Xuất danh sách nhân viên
    for (int i = 0; i < danhSachNV.size(); i++) {
        danhSachNV[i]->xuatThongTin();
        cout << "Luong: " << fixed << setprecision(0) << danhSachNV[i]->tinhLuong() << endl;
        cout << endl << endl;
    }
}

double CongTy::tinhTongLuongNV() {
    double tongLuong = 0;
    for (int i = 0; i < danhSachNV.size(); i++) {
        tongLuong += danhSachNV[i]->tinhLuong();
    }
    return tongLuong;
}

NhanVien* CongTy::timNhanVienLuongCaoNhat() {
    if (danhSachNV.empty()) { // Nếu danh sách nhân viên rỗng thì trả về nullptr
        return nullptr;
    }
    NhanVien* nvLuongCaoNhat = danhSachNV[0];
    for (int i = 1; i < danhSachNV.size(); i++) {
        if (danhSachNV[i]->tinhLuong() > nvLuongCaoNhat->tinhLuong()) {
            nvLuongCaoNhat = danhSachNV[i];
        }
    }
    return nvLuongCaoNhat;
}

double CongTy::tinhLuongTrungBinh() {
    double tongLuong = 0;
    for (int i = 0; i < danhSachNV.size(); i++) {
        tongLuong += danhSachNV[i]->tinhLuong();
    }
    return tongLuong / danhSachNV.size();
}

void CongTy::timNhanVienTheoMa() {
    string ma;
    cout << "Nhap ma nhan vien can tim: ";
    cin.ignore();
    getline(cin, ma);
    for (int i = 0; i < danhSachNV.size(); i++) {
        if (danhSachNV[i]->getMaNV() == ma) {
            danhSachNV[i]->xuatThongTin();
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma " << ma << endl;
}

void CongTy::timNhanVienTheoTen() {
    string ten;
    cout << "Nhap ten nhan vien can tim: ";
    cin.ignore();
    getline(cin, ten);
    for (int i = 0; i < danhSachNV.size(); i++) {
        if (danhSachNV[i]->getTenNV() == ten) {
            danhSachNV[i]->xuatThongTin();
        }
    }
}

void CongTy::demNVThang5() {
    int count = 0;
    for (int i = 0; i < danhSachNV.size(); i++) {
        string ngaySinh = danhSachNV[i]->getNgaySinh();
        int pos = ngaySinh.find("/");
        int month = stoi(ngaySinh.substr(pos + 1, 2));
        if (month == 5) {
            count++;
        }
    }
    cout << "Co " << count << " nhan vien sinh thang 5" << endl;
}

void CongTy::themNhanVien() {
    int loaiNV;
    cout << "Nhap loai nhan vien (1 - NV san xuat, 2 - NV cong nhat): ";
    cin >> loaiNV;
    cin.ignore();

    NhanVien* nv;
    if (loaiNV == 1) {
        nv = new NVSanXuat();
    }
    else if (loaiNV == 2) {
        nv = new NVCongNhat();
    }
    else {
        cout << "Loai nhan vien khong hop le." << endl;
        return;
    }

    nv->nhapThongTin();
    danhSachNV.push_back(nv);
    cout << "Them nhan vien thanh cong." << endl;
}

void CongTy::xoaNhanVien(string maNV) {
    for (int i = 0; i < danhSachNV.size(); i++) {
        if (danhSachNV[i]->getMaNV() == maNV) {
            delete danhSachNV[i];
            danhSachNV.erase(danhSachNV.begin() + i);
            return;
        }
    }
}

void CongTy::ghiNV_LowerAvgSalary() {
    double avgSalary = 0;
    // Tính lương trung bình của công ty
    for (int i = 0; i < danhSachNV.size(); i++) {
        avgSalary += danhSachNV[i]->tinhLuong();
    }
    avgSalary /= danhSachNV.size();

    // Lưu các nhân viên có lương thấp hơn lương trung bình vào file
    ofstream fout("emp_LowerAvgSalary.txt");
    if (fout.is_open()) {
        fout << "Danh sach nhan vien co luong thap hon luong trung binh " << "(" << fixed << setprecision(0) << avgSalary << ")" << endl;
        for (int i = 0; i < danhSachNV.size(); i++) {
            if (danhSachNV[i]->tinhLuong() < avgSalary) {
                //fout << danhSachNV[i]->getMaNV() << "," << danhSachNV[i]->getTenNV() << endl;
                fout << "Ma nhan vien: " << danhSachNV[i]->getMaNV() << endl;
                fout << "Ten nhan vien: " << danhSachNV[i]->getTenNV() << endl;
                fout << "Ngay sinh nhan vien: " << danhSachNV[i]->getNgaySinh() << endl;
                fout << "Luong nhan vien: " << fixed << setprecision(0) << danhSachNV[i]->tinhLuong() << endl;
                fout << endl;
            }
        }
        fout.close();
    }
    else {
        cout << "Khong the mo file!" << endl;
    }
}
