#include "PhanSo.h"
#include "MangPS.h"

void menu() {
    MangPS mang;
    bool quit = false;
    int choice;
    do {
        system("cls");
        cout << "-----------* CHUONG TRINH PHAN SO *------------" << endl;
        cout << "1. Nhap mang phan so" << endl;
        cout << "2. Xuat mang phan so" << endl;
        cout << "3. Tinh tong cua mang phan so" << endl;
        cout << "4. Sap xep mang phan so tang dan" << endl;
        cout << "5. Ghi mang phan so len file" << endl;
        cout << "6. Doc mang phan so tu file va xuat ra man hinh" << endl;
        cout << "0. Thoat chuong trinh" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice) {
        case 1:
            mang.nhapDS();
            system("pause");
            break;
        case 2:
            mang.xuatDS();
            system("pause");
            break;
        case 3: {
            PhanSo tong = mang.tong();
            cout << "Tong cua mang phan so la: ";
            tong.xuat();
            system("pause");
            break;
        }
        case 4:
            mang.sapXep();
            cout << "Mang phan so sau khi sap xep tang dan: " << endl;
            mang.xuatDS();
            system("pause");
            break;
        case 5:
            mang.ghiFile();
            cout << "Ghi mang phan so vao file thanh cong" << endl;
            system("pause");
            break;
        case 6:
            mang.docFile();
            cout << "Mang phan so doc tu file la: " << endl;
            mang.xuatDS();
            system("pause");
            break;
        case 0:
            exit(0);
            system("pause");
            break;
        default:
            cout << "Lua chon khong hop le" << endl;
            system("pause");
            break;
        }
    } while (!quit);
}