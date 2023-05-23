//#include "NgaySinh.h"
//#include "NhanVien.h"
//#include "NVCongNhat.h"
//#include "NVSanXuat.h"
//#include "CongTy.h"
//int main() {
//	CongTy ct;
//    int choice;
//    while (true) {
//        cout << "\n======= MENU =======" << endl;
//        cout << "1. Ghi danh sach nhan vien vao file" << endl;
//        cout << "2. Doc danh sach nhan vien tu file" << endl;
//        cout << "3. Xuat danh sach nhan vien ra man hinh" << endl;
//        cout << "4. Tinh tong tien luong cua tat ca nhan vien" << endl;
//        cout << "5. Tim nhan vien co luong cao nhat" << endl;
//        cout << "6. Tinh luong trung binh trong cong ty" << endl;
//        cout << "7. Tim nhan vien theo ma" << endl;
//        cout << "8. Tim nhan vien theo ten" << endl;
//        cout << "9. Dem so nhan vien sinh trong thang 5" << endl;
//        cout << "10. Them mot nhan vien vao danh sach" << endl;
//        cout << "11. Xoa mot nhan vien khoi danh sach" << endl;
//        cout << "12. Ghi danh sach nhan vien co luong thap hon luong trung binh" << endl;
//        cout << "0. Thoat" << endl;
//        cout << "====================" << endl;
//        cout << "Nhap lua chon cua ban: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            ct.ghiDanhSachNV();
//            break;
//        case 2:
//            ct.docDanhSachNV();
//            break;
//        case 3:
//            ct.xuatDanhSachNV();
//            break;
//        case 4:
//            ct.tinhTongLuong();
//            break;
//        case 5:
//            ct.timNhanVienLuongCaoNhat();
//            break;
//        case 6:
//            cout << "Luong trung binh trong cong ty: " << ct.tinhLuongTrungBinh();
//            break;
//        case 7:
//            ct.timNhanVienTheoMa();
//            break;
//        case 8:
//            ct.timNhanVienTheoTen();
//            break;
//        case 9:
//            ct.demNhanVienSinhThang5();
//            break;
//        case 10:
//            ct.themNhanVienVaoDanhSach();
//            break;
//        case 11:
//            ct.xoaNhanVienKhoiDanhSach();
//            break;
//        case 12:
//            ct.ghiDanhSachNhanVienLuongThap();
//            break;
//        case 13:
//            ct.nhapDanhSachNV();
//            break;
//        case 0:
//            cout << "Cam on ban da su dung chuong trinh!" << endl;
//        }
//    }
//    return 0;
//}

#include "CongTy.h"

int main() {
    int ch;
    bool quit = false;
    CongTy ct;
    do {
        system("cls");
        cout << "------------------* QUAN LY NHAN VIEN *-------------------------" << endl;
        cout << "1. Nhap danh sach nhan vien" << endl;
        cout << "2. Xuat danh sach nhan vien" << endl;
        cout << "3. Ghi danh sach nhan vien vao file 'ds_NhanVien.txt'" << endl;
        cout << "4. Doc danh sach nhan vien tu file 'ds_NhanVien.txt'" << endl;
        cout << "5. Tinh tong tien luong cua tat ca nhan vien" << endl;
        cout << "6. Tim nhan vien co luong cao nhat" << endl;
        cout << "7. Tinh luong trung binh cua cong ty" << endl;
        cout << "8. Tim nhan vien co ma tuong ung" << endl;
        cout << "9. Tim nhan vien co ten tuong ung" << endl;
        cout << "10. Dem so nhan vien sinh trong thang 5" << endl;
        cout << "11. Them mot nhan vien vao danh sach va cap nhat lai file 'ds_NhanVien" << endl;
        cout << "12. Xoa mot nhan vien ra khoi danh sach va cap nhat lai file 'ds_NhanVien" << endl;
        cout << "13. Ghi tat ca nhan vien co luong trung binh nho hon luong trung binh cua cong ty len file 'emp_LowerAvgSalary.txt'" << endl;
        cout << "0. Thoat" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        cout << "Nhap lua chon cua ban: "; cin >> ch;
        switch (ch) {
        case 1:
        {
            ct.nhapDanhSachNV();
            system("pause");
        }
        break;
        case 2:
        {
            ct.xuatDanhSachNV();
            system("pause");
        }
        break;
        case 3:
        {
            ct.ghiDanhSachNV();

            /*ofstream outFile("ds_NhanVien1.txt", ios::out | ios::trunc);
            if (outFile.is_open()) {
                ct.store(outFile);
                cout << "Da ghi file thanh cong!" << endl;
                outFile.close();
            }
            else {
                cout << "Khong mo duoc file de ghi!" << endl;
            }*/

            system("pause");
        }
        break;
        case 4:
        {
            ct.docDanhSachNV();

            /*ifstream inFile("ds_NhanVien1.txt", ios::in);
            if (inFile.is_open()) {
                ct.load(inFile);
                cout << "Da doc file thanh cong!" << endl;
                inFile.close();
            }
            else {
                cout << "Khong mo duoc file de doc!" << endl;
            }*/
            system("pause");
        }
        break;
        case 5:
        {
            cout << "Tong tien luong cua tat ca nhan vien la: " << fixed << setprecision(2) << ct.tinhTongLuong();
            system("pause");
        }
        break;
        case 6:
        {
            ct.timNhanVienLuongCaoNhat();
            system("pause");
        }
        break;
        case 7:
        {
            cout << "Luong trung binh cua cong ty: " << fixed << setprecision(2) << ct.tinhLuongTrungBinh();
            system("pause");
        }
        break;
        case 8:
        {
            ct.timNhanVienTheoMa();
            system("pause");
        }
        break;
        case 9:
        {
            ct.timNhanVienTheoTen();
            system("pause");
        }
        break;
        case 10:
        {
            ct.demNhanVienSinhThang5();
            system("pause");
        }
        break;
        case 11:
        {
            ct.themNhanVienVaoDanhSach();
            system("pause");
        }
        break;
        case 12:
        {
            ct.xoaNhanVienKhoiDanhSach();
            system("pause");
        }
        break;
        case 13:
        {
            ct.ghiDanhSachNhanVienLuongThap();
            system("pause");
        }
        break;
        case 0:
        {
            exit(0);
            system("pause");
        }
        break;
        default:
        {
            cout << "Lua chon khong hop le!";
            system("pause");
        }
        break;
        }
    } while (!quit);
    return 0;
}
