#include "DonThuc.h"
#include "DaThuc.h"

void menu() {
    int ch;
    bool quit = false;
    DaThuc p1, p2, p3;
    do {
        
        system("cls");
        cout << "------ *LOP DON THUC, DA THUC *------" << endl;
        cout << "1. Nhap da thuc" << endl;
        cout << "2. Xuat da thuc" << endl;
        cout << "3. Tinh gia tri da thuc" << endl;
        cout << "4. Cong hai da thuc" << endl;
        cout << "5. Tru hai da thuc" << endl;
        cout << "6. Nhan hai da thuc" << endl;
        cout << "7. Chia hai da thuc" << endl;
        cout << "0. Thoat" << endl;
        cout << "--------------------------------------" << endl;

        cout << "\nNhap lua chon cua ban: ";
        cin >> ch;
        switch (ch) {
        case 1:
            cout << "Nhap da thuc thu nhat: \n";
            p1.nhap();
            cout << "Nhap da thuc thu hai: \n";
            p2.nhap();
            system("pause");
            break;
        case 2:
            // Xuất đa thức
            cout << "Da thuc thu nhat: ";
            p1.xuat();
            cout << "\nDa thuc thu hai: ";
            p2.xuat();
            system("pause");
            break;
        case 3:
            // Tính giá trị đa thức
            float x;
            cout << "Nhap gia tri cua x: ";
            cin >> x;
            cout << "Gia tri cua da thuc thu nhat tai x = " << x << " la: " << p1.tinhGiaTri(x) << endl;
            cout << "Gia tri cua da thuc thu hai tai x = " << x << " la: " << p2.tinhGiaTri(x) << endl;
            system("pause");
            break;
        case 4:
            // Cộng hai đa thức
            p3 = p1 + p2;
            cout << "Tong cua hai da thuc la: ";
            p3.xuat();
            system("pause");
            break;
        case 5:
            // Trừ hai đa thức
            p3 = p1 - p2;
            cout << "Hieu cua hai da thuc la: ";
            p3.xuat();
            system("pause");
            break;
        case 6:
            // Nhân hai đa thức
            p3 = p1 * p2;
            cout << "Tich cua hai da thuc la: ";
            p3.xuat();
            system("pause");
            break;
        case 7:
            // Chia hai đa thức
            p3 = p1 / p2;
            cout << "Thuong cua hai da thuc la: ";
            p3.xuat();
            system("pause");
            break;
        case 0:
            // Thoát chương trình
            exit(0);
            system("pause");
            break;
        default:
            cout << "Lua chon khong hop le!";
            system("pause");
            break;
        }
    } while (!quit);
}