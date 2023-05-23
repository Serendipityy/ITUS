#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct Ngay {
	int ng, th, nam;
};
// Cấu trúc sinh viên
struct SINHVIEN {
	char maso[9]; // "19120100",
	char hoten[30]; // "Nguyen Thanh An"
	bool GioiTinh; // 1: "Nam"; 0: "Nu"
	Ngay NgaySinh; // 01/01/2000
	float Diem; // 6.75
};
struct Node {
	SINHVIEN data;
	Node* Next;
};
struct List {
	Node* Head = NULL;
	Node* Tail = NULL;
};
Node* CreateNode(SINHVIEN sv)
{
    Node* pNode = new Node;
    pNode->data = sv;
    pNode->Next = NULL;
    return pNode;
}
/*Viết hàm nhập danh sách sinh viên.*/
istream& operator>>(istream& cin, SINHVIEN& sv) {
    cout << "\nNhap ma so: ";
    cin.ignore();
    cin.getline(sv.maso, 9);
    cout << "\nNhap ho ten: ";
    cin.getline(sv.hoten, 30);
    cout << "\nNhap ngay thang nam sinh: ";
    cin >> sv.NgaySinh.ng >> sv.NgaySinh.th >> sv.NgaySinh.nam;
    cout << "\nNhap diem: ";
    cin >> sv.Diem;
    return cin;
}
//void Nhap(SINHVIEN& sv) {
//    cout << "\nNhap ma so: ";
//    cin.ignore();
//    cin.getline(sv.maso, 9);
//    cout << "\nNhap ho ten: ";
//    cin.getline(sv.hoten, 30);
//    cout << "\nNhap ngay thang nam sinh: ";
//    cin >> sv.NgaySinh.ng >> sv.NgaySinh.th >> sv.NgaySinh.nam;
//    cout << "\nNhap diem: ";
//    cin >> sv.Diem;
//    cout << "\nNhap gioi tinh (1 - Nam, 0 - Nu): ";
//    cin >> sv.GioiTinh;
//}
// Thêm 
void Them(List& l, SINHVIEN sv) {
    Node* pNode = CreateNode(sv);
    if (l.Head == NULL) {
        l.Head = l.Tail = pNode;
    }
    else {
        l.Tail->Next = pNode;
        l.Tail = pNode;
    }
}
void XuatSV(SINHVIEN sv) {
    cout << "\nHo ten: " << sv.hoten;
    cout << "\nMa so sinh vien: " << sv.maso;
    cout << "\nNgay sinh: " << sv.NgaySinh.ng << "/" << sv.NgaySinh.th << "/" << sv.NgaySinh.nam;
    cout << "\nDiem: " << sv.Diem;
}
/*Viết hàm xuất danh sách phim.*/
void Xuat(List l)
{
    int i = 1;
    for (Node* k = l.Head; k != NULL; k = k->Next) {
        cout << "\n\n\t\tTHONG TIN SINH VIEN THU " << i++;
        cout << "\nMa so: " << k->data.maso;
        cout << "\nHo ten: " << k->data.hoten;
        cout << "\nNgay thang nam sinh: " << k->data.NgaySinh.ng<<"/"<<k->data.NgaySinh.th<<"/" << k->data.NgaySinh.nam;
        cout << "\nDiem: " << k->data.Diem;
    }
}
void LoadFile(List& l) {
    ifstream filein("SINHVIEN.txt");
    while (filein.eof() != true) {
        SINHVIEN sv;
        filein >> sv;
        filein.ignore();
        Them(l, sv);
    }  
    filein.close();
}
/*Ghi file*/
void GhiFile(List& l) {
    ofstream fileout;
    fileout.open("SINHVIEN.txt");
    fileout.close();
}
/*Sắp xếp mã số sinh viên*/
void SapXep(List &l) {
    for (Node* k = l.Head; k->Next != NULL; k = k->Next) {
        for (Node* h = k->Next; h != NULL; h = h->Next) {
            if (strcmp(k->data.maso, h->data.maso) > 0) {
                swap(k->data, h->data);
            }
        }
    }
    cout << "\n=====DANH SACH SINH VIEN THEO MA SO TANG DAN=====";
    Xuat(l);
}
/*Xóa sinh viên */
void XoaSV(List &l, char maso[9]) {
    Node* h = NULL;
    for (Node* k = l.Head; k != NULL;) {
        if ((strcmp(k->data.maso, maso) == 0) && (k == l .Head)) {
            l.Head = l.Head->Next;
            delete k;
            k = l.Head;
        }
        else {
            if (strcmp(k->data.maso, maso) == 0) {
                h->Next = k->Next;
                delete k;
                k = h;

                if (h->Next == NULL) {
                    l.Tail = h;
                    return;
                }
            }
            h = k;
            k = k->Next;
        }
    }
}
void DiemTBDuoi5(List l) {
    for (Node* k = l.Head; k->Next != NULL; k = k->Next) {
        if (k->data.Diem < 5) {
            XuatSV(k->data);
        }
    }
}
void menu() {
    List l;

    bool kt_menu = true;
    while (kt_menu == true) {
        system("cls");
        cout << "\t------------------------------------------------------------------------" << endl;
        cout << "\t* 1. Nhap danh sach sinh vien                                          *" << endl;
        cout << "\t* 2. Xuat danh sach sinh vien                                          *" << endl;
        cout << "\t* 3. Ghi danh sach sinh vien vao tap tin (chua lam)                    *" << endl;
        cout << "\t* 4. Doc danh sach sinh vien tu file (chua lam)                        *" << endl;
        cout << "\t* 5. Sap xep sinh vien theo ma so sinh vien                            *" << endl;
        cout << "\t* 6. Them mot sinh vien co ma so sinh vien da cho vao danh sach        *" << endl;
        cout << "\t* 7. Tim tat ca sinh vien co diem trung binh duoi 5                    *" << endl;
        cout << "\t* 8. Xuat cac sinh vien co diem trung binh duoi 5 ra tap tin van ban   *" << endl;
        cout << "\t* 9. Xoa mot sinh vien co ma so da cho ra khoi danh sach               *" << endl;
        cout << "\t* 10. Thoat                                                            *" << endl;
        cout << "\t------------------------------------------------------------------------" << endl;
        int lc;
        cout << "Nhap lua chon: "; cin >> lc;
        switch (lc)
        {
        case 1:
        {
            int n;
            cout << "\nNhap so luong sinh vien: ";
            cin >> n;
            for (int i = 1; i <= n; i++) {
                cout << "\n\n\t\tNHAP SINH VIEN THU " << i;
                SINHVIEN sv;
                cin >> sv;
                Them(l, sv);
            }
            break;
        }
        case 2:
        {
            Xuat(l);
            system("pause");
            break;
        }
        case 3:
        {
            LoadFile(l);
            GhiFile(l);
            break;
        }
        case 5: 
        {
            SapXep(l);
            system("pause");
            break;
        }
        case 6: 
        {
            SINHVIEN sv;
            cout << "\nNhap thong tin sinh vien can them: ";
            cin >> sv;
            Them(l, sv);
            cout << "\n======SAU KHI THEM======\n";
            Xuat(l);
            system("pause");
            break;
        }
        case 7: {
            cout << "\n======DANH SACH SINH VIEN CO DIEM TRUNG BINH DUOI 5======\n";
            DiemTBDuoi5(l);
            system("pause");
            break;
        }
        case 9: 
        {
            char maso[9];
            cout << "\nNhap vao ma so sinh vien can xoa: ";
            cin >> maso;
            XoaSV(l, maso);
            cout << "\n======SAU KHI XOA======\n";
            Xuat(l);
            system("pause");
            break;
        }
        case 8:
        {
            kt_menu = false;
            break;
        }
        }
    }
}
int main() {

    menu();
    return 0;
}
