#include<iostream>
#include<string.h>
using namespace std;
/* Khai bao Phim */
struct Phim {
	char maso[10]; // mã số, Ex. 123456789
	char tenPhim[30]; // tên phim: Before Sunrise, Bo gia
	char nhaSX[30]; // nhà sản xuất, ex. HBO, Phim Giai Phong
	int namSX; // 1975, 2000, 2020
	float XepHang; // 8, 9.2, trong khoang (1,10)
};
//tao cau truc danh sach lien ket don
struct Node
{
    Phim data;
    Node* pNext;
};

struct DSPhim {
    Node* pHead = NULL;
    Node* pTail = NULL;
};

//tao node phim
Node* CreateNode(Phim p)
{
    Node* pNode = new Node;
    pNode->data = p;
    pNode->pNext = NULL;
    return pNode;
}
/*Viết hàm nhập danh sách phim.*/
istream& operator>>(istream& is, Phim& p) {
    cout << "\nNhap ma so: ";
    cin.ignore();
    is.getline(p.maso, 10);
    cout << "\nNhap ten phim: ";
    is.getline(p.tenPhim, 30);
    cout << "\nNhap nha san xuat: ";
    is.getline(p.nhaSX, 30);
    cout << "\nNhap nam san xuat: ";
    is >> p.namSX;
    cout << "\nNhap xep hang: ";
    is >> p.XepHang;
    return is;
}
// Thêm 
void Them(DSPhim& ds, Phim p) {
    Node* pNode = CreateNode(p);
    if (ds.pHead == NULL) {
        ds.pHead = ds.pTail = pNode;
    }
    else {
        ds.pTail->pNext = pNode;
        ds.pTail = pNode;
    }
}
/*Viết hàm xuất danh sách phim.*/
void Xuat(DSPhim ds)
{
    int i = 1;
    for (Node* k = ds.pHead; k != NULL; k = k->pNext) {
        cout << "\n\n\t\tTHONG TIN PHIM THU " << i++;
        cout << "\nMa so: " << k->data.maso;
        cout << "\nTen phim: " << k->data.tenPhim;
        cout << "\nNha san xuat: " << k->data.nhaSX;
        cout << "\nNam san xuat: " << k->data.namSX;
        cout << "\nXep hang: " << k->data.XepHang;
    }
}

/*Viết hàm tìm phim theo tên.*/
void showNode(Node* k) {
    cout << "\n=====THONG TIN PHIM CAN TIM=====\n";
    cout << "\nMa so: " << k->data.maso;
    cout << "\nTen phim: " << k->data.tenPhim;
    cout << "\nNha san xuat: " << k->data.nhaSX;
    cout << "\nNam san xuat: " << k->data.namSX;
    cout << "\nXep hang: " << k->data.XepHang;
}
void search(DSPhim ds) {
    char  ten[30];
    cout << "\nNhap ten phim can tim: ";
    cin.ignore();
    cin.getline(ten, 30);
    for (Node* k = ds.pHead; k != NULL; k = k->pNext) {
        if (strcmp(k->data.tenPhim, ten)==0) {
            showNode(k);
        }
    }
}
void OutPut(Phim p) {
    cout << "\nMa so: " << p.maso;
    cout << "\nTen phim: " << p.tenPhim;
    cout << "\nNha san xuat: " << p.nhaSX;
    cout << "\nNam san xuat: " << p.namSX;
    cout << "\nXep hang: " << p.XepHang;
}
/*Viết hàm tìm phim của nhà sản xuất HBO mà có xếp hạng cao nhất.*/
void RankFirst(DSPhim ds)
{
    Node* p, *max;
    p = ds.pHead;
    max = p;
    while (p != NULL)
    {
        if (p->data.XepHang < max->data.XepHang) { 
            max = p; 
        }
        p = p->pNext;
    }
    cout<<"\n=====PHIM CO XEP HANG CAO NHAT TRONG DANH SACH LA=====\n";
    OutPut(max->data);
}

/*Viết hàm xóa một phim có mã số đã cho.*/
void XoaPhim(DSPhim& ds, char maso[10]) {
    Node* h = NULL;
    for (Node* k = ds.pHead; k != NULL;) {
        if ((strcmp(k->data.maso, maso) == 0) && (k == ds.pHead)) {
            ds.pHead = ds.pHead->pNext;
            delete k;
            k = ds.pHead;
        }
        else {
            if (strcmp(k->data.maso, maso) == 0) {
                h->pNext = k->pNext;
                delete k;
                k = h;

                if (h->pNext == NULL) {
                    ds.pTail = h;
                    return;
                }
            }
            h = k;
            k = k->pNext;
        }
    }
}
/*Viết hàm sắp xếp danh sách phim theo mã số tăng dần.*/
void SapXep(DSPhim& ds) {
    for (Node* k = ds.pHead; k->pNext != NULL; k = k->pNext) {
        for (Node* h = k->pNext; h != NULL; h = h->pNext) {
            if (strcmp(k->data.maso, h->data.maso) > 0) {
                swap(k->data, h->data);
            }
        }
    }

}

void menu() {
    DSPhim ds;
    bool kt_menu = true;
    while (kt_menu == true) {
        system("cls");
        cout << "\t------------------------------------------------------------" << endl;
        cout << "\t* 1. Nhap danh sach phim                                   *" << endl;
        cout << "\t* 2. Xuat danh sach phim                                   *" << endl;
        cout << "\t* 3. Tim phim theo ten                                     *" << endl;
        cout << "\t* 4. Tim phim cua nha san xuat HBO ma co xep hang cao nhat *" << endl;
        cout << "\t* 5. Them mot phim co ma so da cho vao danh sach           *" << endl;
        cout << "\t* 6. Xoa mot phim co ma so da cho                          *" << endl;
        cout << "\t* 7. Sap xep danh sach phim theo ma so tang dan            *" << endl;
        cout << "\t* 8. Thoat                                                 *" << endl;
        cout << "\t------------------------------------------------------------" << endl;
        int lc;
        cout << "Nhap lua chon: "; cin >> lc;
        switch (lc) 
        {
        case 1:
        {
            int n;
            cout << "\nNhap so luong phim: ";
            cin >> n;
            for (int i = 1; i <= n; i++) {
                cout << "\n\n\t\tNHAP PHIM THU " << i;
                Phim p;
                cin >> p;
                Them(ds, p);
            }
            break;
        }
        case 2:
        {
            Xuat(ds);
            system("pause");
            break;
        }
        case 3:
        {
            search(ds);
            system("pause");
            break;
        }
        case 4:
        {
            RankFirst(ds);
            system("pause");
            break;
        }
        case 5: 
        {
            Phim p;
            cout << "\nNhap thong tin phim can them: ";
            cin >> p;
            Them(ds, p);
            cout << "\n=====SAU KHI THEM====\n";
            Xuat(ds);
            system("pause");
            break;
        }
        case 6: 
        {
            char maso[10];
            cout << "\nNhap vao ma so phim can xoa: ";
            cin >> maso;
            XoaPhim(ds, maso);
            system("pause");
            break;
        }
        case 7:
        {
            SapXep(ds);
            cout << "\n=====DANH SACH PHIM THEO MA SO TANG DAN=====";
            Xuat(ds);
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