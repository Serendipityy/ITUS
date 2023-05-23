#pragma warning(disable: 4996)
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

class Phim {
private:
    char maSo[6];
    char tenPhim[100];
    char theLoai[100];
    char nhaSanXuat[100];
    int namSanXuat;
    char xepHang;

public:
    Phim(const char* ma, const char* ten, const char* tl, const char* nsx, int nam, char xh) {
        strcpy(maSo, ma);
        strcpy(tenPhim, ten);
        strcpy(theLoai, tl);
        strcpy(nhaSanXuat, nsx);
        namSanXuat = nam;
        xepHang = xh;
    }

    const char* getMaSo() const {
        return maSo;
    }

    const char* getTenPhim() const {
        return tenPhim;
    }

    const char* getTheLoai() const {
        return theLoai;
    }

    const char* getNhaSanXuat() const {
        return nhaSanXuat;
    }

    int getNamSanXuat() const {
        return namSanXuat;
    }

    char getXepHang() const {
        return xepHang;
    }
};

class QL_Phim {
private:
    vector<Phim*> ds_phim;

public:
    void themPhim(Phim* phim) {
        if (ds_phim.empty()) {
            ds_phim.push_back(phim);
            return;
        }

        for (auto it = ds_phim.begin(); it != ds_phim.end(); ++it) {
            if ((*it)->getNamSanXuat() > phim->getNamSanXuat()) {
                ds_phim.insert(it, phim);
                return;
            }
        }

        ds_phim.push_back(phim);
    }

    void xuatDanhSachPhim() const {
        for (const auto& phim : ds_phim) {
            cout << "Ma so: " << phim->getMaSo() << endl;
            cout << "Ten phim: " << phim->getTenPhim() << endl;
            cout << "The loai: " << phim->getTheLoai() << endl;
            cout << "Nha san xuat: " << phim->getNhaSanXuat() << endl;
            cout << "Nam san xuat: " << phim->getNamSanXuat() << endl;
            cout << "Xep hang: " << phim->getXepHang() << endl;
            cout << endl;
        }
    }

    void ghiDanhSachPhim() const {
        ofstream file("ds_phim.dat", ios::binary | ios::trunc);
        if (file.is_open()) {
            for (const auto& phim : ds_phim) {
                file.write(reinterpret_cast<const char*>(phim), sizeof(Phim));
            }
            file.close();
            cout << "Ghi danh sach phim thanh cong." << endl;
        }
        else {
            cout << "Khong the mo file de ghi danh sach phim." << endl;
        }
    }

    void docDanhSachPhim() {
        ds_phim.clear();

        ifstream file("ds_phim.dat", ios::binary);
        if (file.is_open()) {
            while (!file.eof()) {
                Phim* phim = new Phim("", "", "", "", 0, '\0');
                file.read(reinterpret_cast<char*>(phim), sizeof(Phim));
                if (file.gcount() > 0) {
                    ds_phim.push_back(phim);
                }
                else {
                    delete phim;
                }
            }
            file.close();
            cout << "Doc danh sach tu file thanh cong." << endl;
        }
        else {
            cout << "Khong the mo file de doc danh sach phim." << endl;
        }
    }

    void xoaPhimHBO() {
        vector<Phim*>::iterator it = ds_phim.begin();
        while (it != ds_phim.end()) {
            if (strcmp((*it)->getNhaSanXuat(), "HBO") == 0) {
                delete* it;
                it = ds_phim.erase(it);
            }
            else {
                ++it;
            }
        }
    }
};

int main() {
    QL_Phim qlPhim;

    //// Thêm phim
    //Phim* phim1 = new Phim("00001", "Phim 1", "Phim hanh dong", "HBO", 2020, 'A');
    //Phim* phim2 = new Phim("00002", "Phim 2", "Phim tinh cam", "Sai Gon", 2021, 'B');
    //Phim* phim3 = new Phim("00003", "Phim 3", "Phim hai", "HBO", 2022, 'C');

    //qlPhim.themPhim(phim1);
    //qlPhim.themPhim(phim2);
    //qlPhim.themPhim(phim3);

    //// In danh sách phim
    //qlPhim.xuatDanhSachPhim();

    //// Ghi danh sách phim vào file
    //qlPhim.ghiDanhSachPhim();

    // Đọc danh sách phim từ file
    qlPhim.docDanhSachPhim();
    qlPhim.xuatDanhSachPhim();

    // Xóa các phim có nhà sản xuất 'HBO'
    qlPhim.xoaPhimHBO();

    // In danh sách phim sau khi xóa
    cout << "Xoa" << endl;
    qlPhim.xuatDanhSachPhim();

    return 0;
}
