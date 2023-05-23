#include<iostream>
using namespace std;
/*Cau truc node of LList*/
struct Node {
	int data;
	Node* Next;
};
/*Cau truc LList*/
struct List {
	Node* Head;
	Node* Tail;
};
/*Khoi tao LList*/
void init(List& l) {
	l.Head = l.Tail = NULL;
}
/*Khoi tao node*/
Node* createNode(int d) {
	Node* pNode = new Node;
	if (pNode != NULL)
	{
		pNode->data = d;
		pNode->Next = NULL;
	}
	else
	{
		cout << "\nLoi khong du bo nho";
	}
	return pNode;
}
/*Them 1 node vao dau LList*/
void addFirst(List& l, Node* p) {
	if (l.Head == NULL)
	{
		l.Head = p;
		l.Tail = p;
	}
	else
	{
		p->Next = l.Head;
		l.Head = p;
	}
}
/*Them 1 node vao cuoi LList*/
void addLast(List& l, Node* p) {
	if (l.Head == NULL)
	{
		l.Head = p;
		l.Tail = p;
	}
	else
	{
		l.Tail->Next = p;
		l.Tail = p;
	}
}
/*Nhap danh sach*/
void dsNhap(List& l, int n) {
	init(l); //Khởi tạo danh sách
	for (int i = 1; i <= n; i++) {
		int data;
		cout << "\nNhap vao node thu " << i << " la: ";
		cin >> data;

		Node* p = createNode(data);
		addLast(l, p);
	}
}
/*Xuat danh sach*/
void dsXuat(List l) {
	for (Node* p = l.Head; p != NULL; p = p->Next) {
		cout << p->data << "   ";
	}
}
/*Tim vi tri node co khoa cho truoc*/
int findNode(List l, int x, int n) {
	int idx = 1;
	for (Node* k = l.Head; k && idx <= n; k = k->Next, idx++) {
		if (k->data == x) {
			cout << "\nTim thay " << x << " tai vi tri " << idx << " ";
		}
	}
	return -1;
}
void GiaiPhong(List& l) {
	Node* p;
	while (l.Head != NULL) {
		p = l.Head;
		l.Head = l.Head->Next;
		delete p;
	}
}

// Tron 2 danh sach cac so nguyen tang dan thanh mot danh sach tang dan
Node* merge(List l1, List l2) {
	Node* p = new Node;
	List l;
	init(l);
	while (l1.Head != NULL && l2.Head != NULL) {
		if (l1.Head->data <= l2.Head->data) {
			p = l1.Head;
			l1.Head = l1.Head->Next;
			addLast(l, p);
		}
		else {
			p = l2.Head;
			l2.Head = l2.Head->Next;
			addLast(l, p);
		}
	}
	while (l1.Head != NULL) {
		p = l1.Head;
		l1.Head = l1.Head->Next;
		addLast(l, p);
	}
	while (l2.Head != NULL) {
		p = l2.Head;
		l2.Head = l2.Head->Next;
		addLast(l, p);
	}
	return l.Head;
}

int main() {
	List l, l1, l2;
	init(l);
	init(l1);
	init(l2);
	int n;
	cout << "\nNhap vao so luong node cua danh sach lien ket: ";
	cin >> n;
	dsNhap(l, n);
	cout << "\nDanh sach lien ket cac so nguyen: ";
	dsXuat(l);
	int x;
	cout << "\nNhap vao node can tim: ";
	cin >> x;
	int res = findNode(l, x, n);

	cout << "\n\nNhap danh sach thu nhat: ";
	int n1;
	cout << "\nNhap so luong node cua danh sach thu nhat: ";
	cin >> n1;
	dsNhap(l1, n1);
	cout << "\nList 1: ";
	dsXuat(l1);

	cout << "\n\nNhap danh sach thu hai: ";
	int n2;
	cout << "\nNhap so luong node cua danh sach thu hai: ";
	cin >> n2;
	dsNhap(l2, n2);
	cout << "\nList 2: ";
	dsXuat(l2);

	l.Head = merge(l1, l2);
	cout << "\n\nDanh sach lien ket sau khi sap xep: ";
	dsXuat(l);

	return 0;
}