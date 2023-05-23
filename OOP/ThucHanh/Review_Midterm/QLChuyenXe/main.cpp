#include "ChuyenXe.h"
#include "ChuyenXeNgoaiThanh.h"
#include "ChuyenXeNoiThanh.h"

int main() {
    int n;
    cout << "Nhap so luong chuyen xe: ";
    cin >> n;
    ChuyenXe** ds = new ChuyenXe * [n];
    for (int i = 0; i < n; i++) {
        int loaiChuyenXe;
        cout << "Nhap loai chuyen xe (1 - Xe noi thanh, 2 - Xe ngoai thanh): ";
        cin >> loaiChuyenXe;

        if (loaiChuyenXe == 1) {
            ds[i] = new ChuyenXeNoiThanh();
            ds[i]->Nhap();
        }
        else if (loaiChuyenXe == 2) {
            ds[i] = new ChuyenXeNgoaiThanh();
            ds[i]->Nhap();
        }
    }

    int tongDoanhThuNoiThanh = 0, tongDoanhThuNgoaiThanh = 0;
    for (int i = 0; i < n; i++) {
        if (typeid(*ds[i]) == typeid(ChuyenXeNoiThanh)) {
            tongDoanhThuNoiThanh += ds[i]->TinhDoanhThu();
        }
        else if (typeid(*ds[i]) == typeid(ChuyenXeNgoaiThanh)) {
            tongDoanhThuNgoaiThanh += ds[i]->TinhDoanhThu();
        }
    }

    cout << "Tong doanh thu xe noi thanh: " << tongDoanhThuNoiThanh << endl;
    cout << "Tong doanh thu xe ngoai thanh: " << tongDoanhThuNgoaiThanh << endl;

    for (int i = 0; i < n; i++) {
        ds[i]->Xuat();
    }

    for (int i = 0; i < n; i++) {
        delete ds[i];
    }
    delete[] ds;

    return 0;
}