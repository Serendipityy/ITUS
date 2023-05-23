#include "PhanSo.h"
#include "MangPS.h"

MangPS::MangPS() {
    ds = NULL;
    size = 0;
}

MangPS::~MangPS() {
    if (ds != NULL) {
        delete[] ds;
    }
}

void MangPS:: nhapDS() {
    cout << "Nhap so luong phan so: ";
    cin >> size;
    while (size <= 0) {
        cout << "So luong phan so khong hop le, vui long nhap lai: ";
        cin >> size;
    }
    ds = new PhanSo[size];
    for (int i = 0; i < size; i++) {
        cout << "Nhap phan so thu " << i + 1 << endl;
        ds[i].nhap();
    }
}

void MangPS::xuatDS() {
    for (int i = 0; i < size; i++) {
        cout << "Phan so thu " << i + 1 << ": ";
        ds[i].xuat();
    }
}

PhanSo MangPS::tong() {
    PhanSo result;
    for (int i = 0; i < size; i++) {
        result = result + ds[i];
    }
    return result;
}

void MangPS::sapXep() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (ds[i].getTuSo() * ds[j].getMauSo() > ds[j].getTuSo() * ds[i].getMauSo()) {
                swap(ds[i], ds[j]);
            }
        }
    }
}

void MangPS::ghiFile() {
    ofstream file;
    string fileName;
    cout << "Nhap ten file de ghi mang phan so: ";
    cin.ignore();
    getline(cin, fileName);

    file.open(fileName);
    file<<"So luong phan so: " << size << endl;
    for (int i = 0; i < size; i++) {
        file << ds[i].getTuSo() << "/" << ds[i].getMauSo() << endl;
    }
    file.close();
}

void MangPS::docFile() {
    ifstream file;
    string fileName;
    cout << "Nhap ten file de doc mang phan so: ";
    cin.ignore();
    getline(cin, fileName);

    file.open(fileName);
    file >> size;
    ds = new PhanSo[size];
    for (int i = 0; i < size; i++) {
        int tu, mau;
        file >> tu >> mau;
        ds[i] = PhanSo(tu, mau);
    }
    file.close();
}
