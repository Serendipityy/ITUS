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
	Node* pNode = new Node; //sử dụng pNode để tạo một Node mới
	if (pNode != NULL) // Nếu pNode != Null, tức là pNode có giá trị thì
	{
		pNode->data = d; // gán giá trị data cho d
		pNode->Next = NULL;// và cho con trỏ pNext trỏ tới giá trị Null
	}
	else // Nếu pNode == Null, tức là pNode không có giá trị thì xuất thông tin
	{
		cout << "\nLoi khong du bo nho";
	}
	return pNode;//trả về pNode
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

/*Thêm node p vào trước node q*/
void insertMidList(List& l, Node* p) {
	int x;
	cout << "\nNhap gia tri node q: ";
	cin >> x;
	Node* q = createNode(x); // Khởi tạo 1 node q
	if (q->data == l.Head->data && l.Head->Next == NULL) {
		addFirst(l, p);
	}
	else {
		Node* g = new Node;
		for (Node* k = l.Head; k != NULL; k = k->Next) {
			if (q->data == k->data) {
				Node* h = createNode(p->data);
				h->Next = k;
				g->Next = h;
			}
			g = k;
		}
	}
}
/*Nhap danh sach*/
void dsNhap(List& l) {
	init(l); //Khởi tạo danh sách
	int n;
	cout << "\nNhap vao so luong node: ";
	cin >> n;
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
/*Tim node co khoa cho truoc*/
Node* SearchNode(List l, int key) {
	Node* node = l.Head;
	while (node != NULL && node->data != key)
		node = node->Next;
	if (node != NULL)
		return node;
	return NULL;
}
/*Xoa 1 node(key)*/
void removeEntry(List& l, int key) {
	Node* pDel = l.Head; // tạo một node pDel để xóa
  //Nếu pDel == Null thì danh sách rỗng
	if (pDel == NULL) {
		cout << "Danh sach rong!!";
	}
	//ngược lại thì xét điều kiện
	else {
		Node* pPre = NULL;
		//dùng vòng lặp while để tìm ra pDel và pPre (vị trí đứng trước pDel)
		while (pDel != NULL) {
			if (pDel->data == key) {
				break;
			}
			pPre = pDel;
			pDel = pDel->Next;
		}
		//Nếu pDel == null tức là không tìm thấy số cần xóa
		if (pDel == NULL) {
			cout << "Khong tim thay phan tu can xoa";
		}
		// Ngược lại tiếp tục xét điều kiện
		else {
			// Nếu pDel == list.pHead, tức là số cần xóa ở đầu danh sách
			if (pDel == l.Head) {
				l.Head = l.Head->Next;
				pDel->Next = NULL;
				delete pDel;
				pDel = NULL;
			}
			//Nếu pDel == list.pTail, tức là số cần xóa ở cuối danh sách
			else if (pDel->Next == NULL) {
				l.Tail = pPre;
				pPre->Next = NULL;
				delete pDel;
				pDel = NULL;
			}
			// và trường hợp cuối cùng số muốn xóa nằm ở giữa danh sách
			else {
				pPre->Next = pDel->Next;
				pDel->Next = NULL;
				delete pDel;
				pDel = NULL;
			}
		}
	}
}

void GiaiPhong(List& l) {
	Node* p;
	while (l.Head != NULL) {
		p = l.Head;
		l.Head = l.Head->Next;
		delete p;
	}
}

int main() {
	List l;
	dsNhap(l);
	dsXuat(l);
	int k;
	cout << "\nNhap vao gia tri node can them: ";
	cin >> k;
	Node* p = createNode(k);
	addFirst(l, p);
	cout << "\nSau khi them node vao dau danh sach: ";
	dsXuat(l);
	int key;
	cout << "\nNhap node can xoa: ";
	cin >> key;
	removeEntry(l, key);
	cout << "\nSau khi xoa: ";
	dsXuat(l);
	return 0;
}