#include "CongTy.h"
int main() {
    int ch;
    bool quit = false;
    CongTy ct;
    do {
        system("cls");
        cout << "----------- *QUAN LY CONG TY* -------------" << endl;
        cout << "1. Doc danh sach nhan vien tu file" << endl;
        cout << "2. Nhap danh sach cac nhan vien" << endl;
        cout << "3. Xuat danh sach cac nhan vien" << endl;
        cout << "4. Tinh tong tien luong cua tat ca nhan vien" << endl;
        cout << "5. Tim nhan vien co luong cao nhat" << endl;
        cout << "6. Tinh luong trung binh trong cong ty" << endl;
        cout << "7. Tim nhan vien voi ma cho truoc" << endl;
        cout << "8. Tim nhan vien voi ten cho truoc" << endl;
        cout << "9. So nhan vien sinh trong thang 5" << endl;
        cout << "10. Them mot nhan vien vao danh sach" << endl;
        cout << "11. Xoa mot nhan vien khoi danh sach" << endl;
        cout << "12. Ghi tat ca nhan vien co luong nho hon luong trung binh cua cong ty len file" << endl;
        cout << "0. Thoat" << endl;
        cout << "----------------------------------------" << endl;
        cout << "\nNhap lua chon cua ban: ";
        cin >> ch;
        switch (ch) {
        case 1:
        {
            ct.docNV("docNV.txt");
            cout << "Da doc file thanh cong. Nhap 3 de xem danh sach nhan vien.";
            system("pause");
        }
        break;
        case 2:
        {
            ct.nhap();
            system("pause");
        }
        break;
        case 3:
        {
            ct.xuat();
            system("pause");
        }
        break;
        case 4:
        {
            cout << "Tong luong nhan vien: " << ct.tinhTongLuongNV();
            system("pause");
        }
        break;
        case 5:
        {
            NhanVien* nvLuongCaoNhat = ct.timNhanVienLuongCaoNhat();
            if (nvLuongCaoNhat != nullptr) {
                cout << "Nhan vien co muc luong cao nhat la: " << endl;
                nvLuongCaoNhat->xuatThongTin();
            }
            else {
                cout << "Khong tim thay nhan vien nao trong danh sach." << endl;
            }
            system("pause");
        }
        break;
        case 6:
        {
            cout << "Luong TB: " << ct.tinhLuongTrungBinh();
            system("pause");
        }
        break;
        case 7:
        {
            ct.timNhanVienTheoMa();
            system("pause");
        }
        break;
        case 8:
        {
            ct.timNhanVienTheoTen();
            system("pause");
        }
        break;
        case 9:
        {
            ct.demNVThang5();
            system("pause");
        }
        break;
        case 10:
        {
            ct.themNhanVien();
            system("pause");
        }
        break;
        case 11:
        {
            string ma;
            cout << "Nhap ma nhan vien can xoa: ";
            cin.ignore();
            getline(cin, ma);
            ct.xoaNhanVien(ma);
            system("pause");
        }
        break;
        case 12:
        {

            ct.ghiNV_LowerAvgSalary();
            system("pause");
        }
        break;
        case 0: {
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
}