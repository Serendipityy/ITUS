#include<iostream>
using namespace std;
/* tạo cấu trúc của Node trong danh sách liên kết */
struct Node {
	Node* next;
	int data;
};
/* tạo cấu trúc của hàng đợi Queue */
struct Queue {
	Node* head, * tail;
};
/* khởi tạo rỗng cho Node trong danh sách liên kết */
void Init(Queue& q) {
	q.head = q.tail = NULL;
}
/* hàm tạo một Node mới */
Node* createNode(int x) {
	Node* p = new Node;
	if (!p) exit(1);
	p->next = NULL;
	p->data = x;
	return p;
}
/*Kiểm tra hàng đợi rỗng*/
bool IsEmpty(Queue q) {
	//neu head bang NULL thi queue rong
	if (q.head == NULL) {
		return 1;
	}
	return 0;
}
/*Thêm phần tử vào hàng đợi*/
void enqueue(Queue& q, Node* p) {
	if (!q.head) q.head = q.tail = p;
	else {
		q.tail->next = p;
		q.tail = p;
	}
}

/* hàm trả về phần tử ở đầu hàm đợi */
int front(Queue q) {
	if (q.head) {
		return q.head->data;
	}
	else return 0;
}
/* hàm xóa phần tử đầu trong hàng đợi */
int dequeue(Queue& q) {
	if (q.head) {
		Node* p = q.head;
		q.head = q.head->next;
		return p->data;
		delete p;
	}
	return 0;
}
/* hàm nhập các phần tử vào hàng đợi */
void nhap(Queue& q) {
	int n, x;
	cout << "\nNhap so luong phan tu cua hang doi: ";
	cin >> n;
	while (n--) {
		cout << "\nNhap cac phan tu trong hang doi: ";
		cin >> x;
		Node* p = createNode(x);
		enqueue(q, p);
	}
}
/* hàm xuất các phần tử trong hàng đợi */
void xuat(Queue q) {
	Node* p = q.head;
	while (p) {
		cout << p->data << "\t";
		p = p->next;
	}
	cout << endl;
}
/* hàm menu để hiển thị menu và gọi các hàm đã tạo */
void menu(Queue q) {
	int lc;
	do {
		cout << "\n\n\t\t ============== Menu ==============";
		cout << "\n\t1. Nhap phan tu cho hang doi";
		cout << "\n\t2. Xuat phan tu trong hang doi";
		cout << "\n\t3. Hien thi phan tu dau tien cua hang doi";
		cout << "\n\t4. Xoa phan tu dau tien cua hang doi";
		cout << "\n\t0. Thoat";
		cout << "\n\n\t\t ============== End ==============";
		cout << "\nNhap lua chon: ";
		cin >> lc;
		switch (lc) {
		case 0: break;
		case 1:
			cout << "\n\n\t\tNHAP HANG DOI\n";
			nhap(q);
			break;
		case 2:
			cout << "\n\n\t\tXUAT HANG DOI\n";
			xuat(q);
			break;
		case 3:
			cout << "Phan tu dau tien cua hang doi la: " << front(q);
			break;
		case 4:
			dequeue(q);
			cout << "Xoa thanh cong. Nhap 2 de kiem tra!";
			break;
		default: cout << "\nNhap sai, vui long nhap lai";
		}
	} while (lc);
}
/* hàm main để hiển thị menu*/
int main() {
	Queue q;
	Init(q);
	int lc;
	menu(q);
}