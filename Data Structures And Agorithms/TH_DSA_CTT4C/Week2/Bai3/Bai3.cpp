#include<iostream>
#include<string>
using namespace std;

template<class T>
class Node {
private:
    T data;
    Node<T>* next;
    template<class U>friend class LinkedList; // Class LinkedList có thể truy cập vào private members của Node
public:
    // Default constructor (hàm tạo mặc định (rỗng))
    Node() {
        next = NULL; // this dùng để trỏ đến địa chỉ của đối tượng hiện tại
    }
};
template<class T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() {
        head = NULL;
    }
    // Ham them node vao cuoi danh sach
    void addBack(T item) {
        Node<T>* node = new Node<T>[1]; // Cấp phát vùng nhớ cho node
        node->data = item;
        if (head == NULL) { // Nếu head là NULL thì gán cho node là head
            head = node;
            cout << "Da them node (node dau tien)!" << endl;
            return;
        }
        Node<T>* temp = head; // Gán node tạm (node hiện tại) là node đầu
        while (temp->next != NULL) { // Trỏ đến cuối danh sách 
            temp = temp->next;
        }
        temp->next = node; // Thêm node vào cuối danh sách
        cout << "Da them node vao cuoi danh sach !" << endl;
    }
    // Ham them node vao dau danh sach
    void addFront(T item) {
        Node<T>* node = new Node<T>[1];
        node->data = item;
        if (head == NULL) {
            head = node;
            cout << "Da them node (node dau tien) !" << endl;
            return;
        }
        node->next = head;
        head = node;
        cout << "Da them node vao dau danh sach !" << endl;
    }
    // Ham tinh so luong phan tu cua danh sach (do dai cua danh sach)
    int length() {
        int len = 0;
        Node<T>* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
    // Ham them node vao vi tri bat ky
    void addIndex(int index, T item) {
        if (index > length() || index < 0) {
            cout << "Vi tri khong hop le !" << endl;
            return;
        }
        Node<T>* node = new Node<T>[1];
        node->data = item;
        int count = 0;
        Node<T>* temp = head; // Tạo một node tạm (node hiện tại), gán cho node đầu tiên
        while (temp != NULL && count < index) {
            if (count == index - 1) { 
                if (temp->next != NULL) {
                    node->next = temp->next;
                }
                temp->next = node;
                cout << "Da them node vao vi tri thu " << index << " !" << endl;
                break;
            }
            count++;
            temp = temp->next; 
        }
    }
    // Ham xuat danh sach lien ket
    void displayAll() {
        if (head == NULL) {
            cout << "Danh sach rong" << endl;
            return;
        }
        cout << endl << "----DANH SACH LIEN KET DON------" << endl;
        Node<T>* temp = head;
        while (temp != NULL) {
            cout << temp->data << " | ";
            temp = temp->next;
        }
        cout << endl << "--------------------------" << endl;
    }
    // Ham xoa phan tu o cuoi danh sach
    void removeBack() {
        if (head == NULL) {
            cout << "Danh sach rong !" << endl;
            return;
        }
        if (head->next == NULL) {
            head = NULL;
            cout << "Da xoa phan tu cuoi danh sach" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp != NULL) {
            if (temp->next->next == NULL) {
                temp->next = NULL;
                cout << "Da xoa phan tu cuoi danh sach" << endl;
                break;
            }
            temp = temp->next;
        }
    }
    // Ham xoa phan tu o dau danh sach
    void removeFront() {
        if (head == NULL) {
            cout << "Danh sach rong !" << endl;
            return;
        }
        head = head->next;
        cout << "Da xoa phan tu o dau danh sach" << endl;
    }
    // Ham xoa phan tu o vi tri bat ky
    void removeIndex(int index) {
        if (head == NULL) {
            cout << "Danh sach rong !" << endl;
            return;
        }
        if (index >= length() || index < 0) {
            cout << "Vi tri khong hop le !" << endl;
            return;
        }
        if (index == 0) {
            removeFront();
            cout << "Da xoa phan tu o vi tri thu " << index << endl;
            return;
        }
        int count = 0;
        Node<T>* temp = head;
        while (temp != NULL) {
            if (count == index - 1) {
                temp->next = temp->next->next;
                cout << "Da xoa phan tu o vi tri thu " << index << endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }
    // Ham tim kiem phan tu o vi tri bat ky trong danh sach
    T get(int index) {
        if (head == NULL) {
            cout << "Danh sach rong !" << endl;
            /* return -9999;*/
        }
        if (index >= length() || index < 0) {
            cout << "Vi tri khong hop le !" << endl;
            /*  return -9999;*/
        }
        if (index == 0) {
            return head->data;
        }
        int count = 0;
        T res;
        Node<T>* temp = head;
        while (temp != NULL) {
            if (count++ == index) {
                res = temp->data;
                break;
            }
            temp = temp->next;
        }
        return res;
    }
};
void Menu_Int() {
    LinkedList<int> list;
    int ch, item, index;
    bool quit = false;
    do {
        cout << "====================================" << endl;
        cout << "Nhap lua chon :" << endl;
        cout << "1: Them cuoi" << endl;
        cout << "2: Them dau" << endl;
        cout << "3: Them vao vi tri bat ky" << endl;
        cout << "4: Xuat danh sach lien ket" << endl;
        cout << "5: Tim kiem phan tu o vi tri bat ky" << endl;
        cout << "6: Xoa cuoi" << endl;
        cout << "7: Xoa dau" << endl;
        cout << "8: Xoa o vi tri bat ky" << endl;
        cout << "9: Thoat" << endl;
        cin >> ch;
        cout << "====================================" << endl;
        switch (ch)
        {
        case 1:
            cout << "Nhap phan tu can them:" << endl;
            cin >> item;
            list.addBack(item);
            break;
        case 2:
            cout << "Nhap phan tu can them:" << endl;
            cin >> item;
            list.addFront(item);
            break;
        case 3:
            cout << "Nhap phan tu can them:" << endl;
            cin >> item;
            cout << "Nhap vi tri can them:" << endl;
            cin >> index;
            list.addIndex(index, item);
            break;
        case 4:
            list.displayAll();
            break;

        case 5:
            cout << "Nhap vi tri can tim kiem:" << endl;
            cin >> index;
            cout << "Phan tu o vi tri thu " << index << ": " << list.get(index) << endl;
            break;
        case 6:
            list.removeBack();
            break;
        case 7:
            list.removeFront();
            break;
        case 8:
            cout << "Nhap vi tri can xoa:" << endl;
            cin >> index;
            list.removeIndex(index);
            break;
        case 9:
            quit = true;
            break;
        default:
            cout << "Lua chon khong hop le !" << endl;
            break;
        }
    } while (!quit);

}
void Menu_Float() {
    LinkedList<float> list;
    int ch, index;
    float item;
    bool quit = false;
    do {
        cout << "====================================" << endl;
        cout << "Nhap lua chon :" << endl;
        cout << "1: Them cuoi" << endl;
        cout << "2: Them dau" << endl;
        cout << "3: Them vao vi tri bat ky" << endl;
        cout << "4: Xuat danh sach lien ket" << endl;
        cout << "5: Tim kiem phan tu o vi tri bat ky" << endl;
        cout << "6: Xoa cuoi" << endl;
        cout << "7: Xoa dau" << endl;
        cout << "8: Xoa o vi tri bat ky" << endl;
        cout << "9: Thoat" << endl;
        cin >> ch;
        cout << "====================================" << endl;
        switch (ch)
        {
        case 1:
            cout << "Nhap phan tu can them:" << endl;
            cin >> item;
            list.addBack(item);
            break;
        case 2:
            cout << "Nhap phan tu can them:" << endl;
            cin >> item;
            list.addFront(item);
            break;
        case 3:
            cout << "Nhap phan tu can them:" << endl;
            cin >> item;
            cout << "Nhap vi tri can them:" << endl;
            cin >> index;
            list.addIndex(index, item);
            break;
        case 4:
            list.displayAll();
            break;

        case 5:
            cout << "Nhap vi tri can tim kiem:" << endl;
            cin >> index;
            cout << "Phan tu o vi tri thu " << index << ": " << list.get(index) << endl;
            break;
        case 6:
            list.removeBack();
            break;
        case 7:
            list.removeFront();
            break;
        case 8:
            cout << "Nhap vi tri can xoa:" << endl;
            cin >> index;
            list.removeIndex(index);
            break;
        case 9:
            quit = true;
            break;
        default:
            cout << "Lua chon khong hop le !" << endl;
            break;
        }
    } while (!quit);
}
void Menu_String() {
    LinkedList<string> list;
    int ch, index;
    string item;
    bool quit = false;
    do {
        cout << "====================================" << endl;
        cout << "Nhap lua chon :" << endl;
        cout << "1: Them cuoi" << endl;
        cout << "2: Them dau" << endl;
        cout << "3: Them vao vi tri bat ky" << endl;
        cout << "4: Xuat danh sach lien ket" << endl;
        cout << "5: Tim kiem phan tu o vi tri bat ky" << endl;
        cout << "6: Xoa cuoi" << endl;
        cout << "7: Xoa dau" << endl;
        cout << "8: Xoa o vi tri bat ky" << endl;
        cout << "9: Thoat" << endl;
        cin >> ch;
        cout << "====================================" << endl;
        switch (ch)
        {
        case 1:
            cout << "Nhap phan tu can them:" << endl;
            cin.ignore();
            getline(cin, item);
            list.addBack(item);
            break;
        case 2:
            cout << "Nhap phan tu can them:" << endl;
            cin.ignore();
            getline(cin, item);
            list.addFront(item);
            break;
        case 3:
            cout << "Nhap phan tu can them:" << endl;
            cin.ignore();
            getline(cin, item);
            cout << "Nhap vi tri can them:" << endl;
            cin >> index;
            list.addIndex(index, item);
            break;
        case 4:
            list.displayAll();
            break;

        case 5:
            cout << "Nhap vi tri can tim kiem:" << endl;
            cin >> index;
            cout << "Phan tu o vi tri thu " << index << ": " << list.get(index) << endl;
            break;
        case 6:
            list.removeBack();
            break;
        case 7:
            list.removeFront();
            break;
        case 8:
            cout << "Nhap vi tri can xoa:" << endl;
            cin >> index;
            list.removeIndex(index);
            break;
        case 9:
            quit = true;
            break;
        default:
            cout << "Lua chon khong hop le !" << endl;
            break;
        }
    } while (!quit);

}
void Menu() {
    int ch;
    bool quit = false;
    do {
        cout << "============================" << endl;
        cout << "Chon kieu du lieu can dung: " << endl;
        cout << "1. Integer" << endl;
        cout << "2. Float" << endl;
        cout << "3. String" << endl;
        cout << "============================" << endl;
        cout << "\nNhap lua chon: "; cin >> ch;
        switch (ch) {
        case 1:
            Menu_Int();
            break;
        case 2:
            Menu_Float();
            break;
        case 3:
            Menu_String();
            break;
        default:
            cout << "Lua chon khong hop le !" << endl;
            break;
        }
    } while (!quit);
}
int main() {
    Menu();
    return 0;
}