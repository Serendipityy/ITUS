#include "CongTy.h"

CongTy::CongTy() {
}

CongTy::~CongTy() {
    for (NhanVien* nv : danhSachNV) {
        delete nv;
    }
}

void CongTy::themNhanVien(NhanVien* nv) {
    danhSachNV.push_back(nv);
}

void CongTy::nhapDanhSachNV() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); 

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        NhanVien* nv;
        char loaiNV;

        cout << "Chon loai nhan vien (S: San xuat, C: Cong nhat): ";
        cin >> loaiNV;
        cin.ignore(); 

        if (loaiNV == 'S' || loaiNV == 's') {
            nv = new NVSanXuat();
        }
        else if (loaiNV == 'C' || loaiNV == 'c') {
            nv = new NVCongNhat();
        }
        else {
            cout << "Loai nhan vien khong hop le. Bo qua nhan vien nay." << endl;
            continue;
        }

        nv->nhap();
        danhSachNV.push_back(nv);
    }
}

//void CongTy::ghiDanhSachNV() {
//    ofstream file("ds_NhanVien.txt", ios::binary | ios::out);
//    if (file.is_open()) {
//        int size = danhSachNV.size();
//        file.write(reinterpret_cast<char*>(&size), sizeof(int));
//        for (NhanVien* nv : danhSachNV) {
//            if (NVSanXuat* nvSanXuat = dynamic_cast<NVSanXuat*>(nv)) {
//                char loaiNV = 'S';
//                file.write(reinterpret_cast<char*>(&loaiNV), sizeof(char));
//                file.write(reinterpret_cast<char*>(nvSanXuat), sizeof(NVSanXuat));
//            }
//            else if (NVCongNhat* nvCongNhat = dynamic_cast<NVCongNhat*>(nv)) {
//                char loaiNV = 'C';
//                file.write(reinterpret_cast<char*>(&loaiNV), sizeof(char));
//                file.write(reinterpret_cast<char*>(nvCongNhat), sizeof(NVCongNhat));
//            }
//        }
//        file.close();
//        cout << "Ghi danh sach nhan vien thanh cong." << endl;
//    }
//    else {
//        cout << "Khong the mo file de ghi." << endl;
//    }
//}
//
//void CongTy::ghiDanhSachNV() {
//    ofstream file("ds_NhanVien.dat", ios::binary | ios::out);
//    if (file.is_open()) {
//        int size = danhSachNV.size();
//        file.write(reinterpret_cast<char*>(&size), sizeof(int));
//        for (NhanVien* nv : danhSachNV) {
//            nv->ghi(file);
//        }
//        file.close();
//        cout << "Ghi danh sach nhan vien thanh cong." << endl;
//    }
//    else {
//        cout << "Khong the mo file de ghi." << endl;
//    }
//}

//
//void CongTy::docDanhSachNV() {
//    ifstream file("ds_NhanVien.txt", ios::binary | ios::in);
//    if (file.is_open()) {
//        danhSachNV.clear();
//        int size;
//        file.read(reinterpret_cast<char*>(&size), sizeof(int));
//        for (int i = 0; i < size; i++) {
//            char loaiNV;
//            file.read(reinterpret_cast<char*>(&loaiNV), sizeof(char));
//            if (loaiNV == 'S') {
//                NVSanXuat* nvSanXuat = new NVSanXuat();
//                file.read(reinterpret_cast<char*>(nvSanXuat), sizeof(NVSanXuat));
//                danhSachNV.push_back(nvSanXuat);
//            }
//            else if (loaiNV == 'C') {
//                NVCongNhat* nvCongNhat = new NVCongNhat();
//                file.read(reinterpret_cast<char*>(nvCongNhat), sizeof(NVCongNhat));
//                danhSachNV.push_back(nvCongNhat);
//            }
//        }
//        file.close();
//        cout << "Doc danh sach nhan vien thanh cong." << endl;
//    }
//    else {
//        cout << "Khong the mo file de doc." << endl;
//    }
//}

void CongTy::ghiDanhSachNV() {
    ofstream file("ds_NhanVien.dat", ios::binary | ios::out);
    if (file.is_open()) {
        int size = danhSachNV.size();
        file.write(reinterpret_cast<char*>(&size), sizeof(int));
        for (NhanVien* nv : danhSachNV) {
            if (dynamic_cast<NVCongNhat*>(nv) != nullptr) {
                char loaiNV = 'C'; // Loại nhân viên công nhật
                file.write(reinterpret_cast<char*>(&loaiNV), sizeof(char));
                nv->ghi(file);
            }
            else if (dynamic_cast<NVSanXuat*>(nv) != nullptr) {
                char loaiNV = 'S'; // Loại nhân viên sản xuất
                file.write(reinterpret_cast<char*>(&loaiNV), sizeof(char));
                nv->ghi(file);
            }
        }
        file.close();
        cout << "Ghi danh sach nhan vien thanh cong." << endl;
    }
    else {
        cout << "Khong the mo file de ghi." << endl;
    }
}



void CongTy::docDanhSachNV() {
    ifstream file("ds_NhanVien.dat", ios::binary | ios::in);
    if (file.is_open()) {
        danhSachNV.clear();
        int size;
        file.read(reinterpret_cast<char*>(&size), sizeof(int));
        for (int i = 0; i < size; i++) {
            char loaiNV;
            file.read(reinterpret_cast<char*>(&loaiNV), sizeof(char));

            NhanVien* nv;
            if (loaiNV == 'S') {
                nv = new NVSanXuat();
            }
            else if (loaiNV == 'C') {
                nv = new NVCongNhat();
            }
            else {
                cout << "Loai nhan vien khong hop le. Bo qua nhan vien nay." << endl;
                continue;
            }
            nv->doc(file);
            danhSachNV.push_back(nv);
        }
        file.close();
        cout << "Doc danh sach nhan vien thanh cong." << endl;
    }
    else {
        cout << "Khong the mo file de doc." << endl;
    }
}

void CongTy::xuatDanhSachNV() {
    for (NhanVien* nv : danhSachNV) {
        nv->xuat();
        cout << endl;
    }
}

double CongTy::tinhTongLuong() {
    double tongLuong = 0;
    for (NhanVien* nv : danhSachNV) {
        tongLuong += nv->tinhLuong();
    }
    return tongLuong;
}

void CongTy::timNhanVienLuongCaoNhat() {
    double maxLuong = 0;
    NhanVien* nvMaxLuong = nullptr;
    for (NhanVien* nv : danhSachNV) {
        nv->tinhLuong();
        // Tìm nhân viên có lương cao nhất
        if (nv->tinhLuong() > maxLuong) {
            maxLuong = nv->tinhLuong();
            nvMaxLuong = nv;
        }
    }
    if (nvMaxLuong != nullptr) {
        cout << "Nhan vien co luong cao nhat:" << endl;
        nvMaxLuong->xuat();
        cout << endl;
    }
}

double CongTy::tinhLuongTrungBinh() {
    double tongLuong = 0;
    for (NhanVien* nv : danhSachNV) {
        nv->tinhLuong();
        tongLuong += nv->tinhLuong();
    }
    double luongTrungBinh = 0;
    if (danhSachNV.size() > 0) {
        luongTrungBinh = tongLuong / danhSachNV.size();
    }
    return luongTrungBinh;
}

void CongTy::timNhanVienTheoMa() {
    char ma[6];
    cout << "Nhap ma nhan vien can tim: ";
    cin >> ma;

    for (NhanVien* nv : danhSachNV) {
        if (strcmp(nv->getMaNV(), ma) == 0) {
            cout << "Nhan vien co ma " << ma << ":" << endl;
            nv->xuat();
            cout << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien co ma " << ma << "." << endl;
}

void CongTy::timNhanVienTheoTen() {
    char ten[50];
    cout << "Nhap ten nhan vien can tim: ";
    cin.ignore();
    cin.getline(ten, 50);

    bool timThay = false;
    for (NhanVien* nv : danhSachNV) {
        if (strcmp(nv->getHoTen(), ten) == 0) {
            cout << "Nhan vien co ten " << ten << ":" << endl;
            nv->xuat();
            cout << endl;
            timThay = true;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay nhan vien co ten " << ten << "." << endl;
    }
}

void CongTy::demNhanVienSinhThang5() {
    int dem = 0;
    for (NhanVien* nv : danhSachNV) {
        if (nv->getNgaySinh().getThang() == 5) {
            dem++;
        }
    }
    cout << "Co " << dem << " nhan vien sinh trong thang 5." << endl;
}

void CongTy::themNhanVienVaoDanhSach() {
    int choice;
    cout << "Chon loai nhan vien muon them (1: NV San Xuat, 2: NV Cong Nhat): ";
    cin >> choice;

    NhanVien* nv;
    if (choice == 1) {
        nv = new NVSanXuat();
    }
    else if (choice == 2) {
        nv = new NVCongNhat();
    }
    else {
        cout << "Lua chon khong hop le." << endl;
        return;
    }

    nv->nhap();
    danhSachNV.push_back(nv);
    ghiDanhSachNV();
    cout << "Them nhan vien thanh cong." << endl;
}

void CongTy::xoaNhanVienKhoiDanhSach() {
    char ma[6];
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> ma;

    for (auto it = danhSachNV.begin(); it != danhSachNV.end(); ++it) {
        if (strcmp((*it)->getMaNV(), ma) == 0) {
            delete* it;
            danhSachNV.erase(it);
            ghiDanhSachNV();
            cout << "Xoa nhan vien thanh cong." << endl;
            return;
        }
    }
    cout << "Khong tim thay nhân viên có mã " << ma << " trong danh sách." << endl;
}


void CongTy::ghiDanhSachNhanVienLuongThap() {
    double luongTrungBinh = tinhLuongTrungBinh();
    ofstream file("emp_LowerAvgSalary.txt", ios::out | ios::binary);
    if (!file) {
        cout << "Khong the mo file." << endl;
        return;
    }

    for (NhanVien* nv : danhSachNV) {
        if (nv->tinhLuong() < luongTrungBinh) {
            file.write(reinterpret_cast<char*>(nv), sizeof(NhanVien));
        }
    }

    file.close();
    cout << "Ghi danh sach nhan vien co luong thap hon luong trung binh thanh cong." << endl;
}
