#include<iostream>
using namespace std;

int n = 0; // khai bao bien toan cuc chua so luong phan tu cua DSLK
struct Node {
	int key; 
	Node* Next;
};
struct List {
	Node* Head;
	Node* Tail;
};
void init(List& l) {
	l.Head = l.Tail = NULL;
}
Node* createNode(int key) {
	Node* p = new Node;
	if (p != NULL) {
		p->key = key;
		p->Next = NULL;
	}
	else cout << "\nLoi khong du bo nho";
	return p;
}
void addFirst(List& l, Node* p) {
	if (l.Head == NULL) {
		l.Head = l.Tail = p;
	}
	else {
		p->Next = l.Head;
		l.Head = p;
	}
}
void addLast(List& l, Node* p) {
	if (l.Head == NULL) {
		l.Head = l.Tail = p;
	}
	else {
		l.Tail->Next = p;
		l.Tail = p;
	}
}
// Them vao vi tri bat ky 
void addIndex(List& l, Node* p, int vt, int n) {
	if (l.Head == NULL || vt == 1) {
		addFirst(l, p);
	}
	else if (vt == n + 1) {
		addLast(l, p);
	}
	else {
		int dem = 0; // xac dinh vi tri can them
		Node* g = new Node;
		for (Node* k = l.Head; k != NULL; k = k->Next) {
			dem++;
			if (dem==vt) {
				Node* h = createNode(p->key);
				h->Next = k;
				g->Next = h;
				break;
			}
			g = k;
		}
	}
}
// Them node p vao truoc node q
void insertMidBefore(List& l, Node* p, Node* q) {
	if (q->key == l.Head->key && l.Head->Next == NULL) {
		addFirst(l, p);
	}
	else {
		Node* g = new Node; // node g giu lien ket voi node nam truoc node q
		for (Node* k = l.Head; k != NULL; k = k->Next) {
			if (q->key == k->key) {
				// Them node p vao sau node g <=> them node p vao truoc noi q
				Node* h = createNode(p->key);
				h->Next = k;
				g->Next = h;
			}
			g = k; // giu lien ket voi node nam truoc node q 
		}
	}
}

// Them node p vao sau node q
void insertMidAfter(List& l, Node* p, Node* q) {
	if (q->key == l.Head->key && l.Head->Next == NULL) {
		addLast(l, p);
	}
	else {
		for (Node* k = l.Head; k != NULL; k = k->Next) {
			// Neu ton tai q trong DSLK
			if (q->key == k->key) {
				Node* h = createNode(p->key); // Khoi tao node h moi de them vao sau node q
				Node* g = k->Next; // cho node g tro den node nam sau node q
				h->Next = g; // Tao moi lien ket tu node p den node g 
				// <=> tao moi lien ket tu node p den node nam sau node q
				k->Next = h; // Tao moi lien ket tu node q den node p
				// <=> node k den node p
			}
		}
	}
}

// Xoa node
// Trong trường hợp nhiều node giống nhau nó chỉ xóa 1 node => XEM LẠI
void remove(List& l, int delKey) {
	Node* pDel = l.Head;
	if (pDel == NULL) cout << "\nDanh sach rong!";
	else {
		Node* pPre = NULL;
		while (pDel != NULL) {
			if (pDel->key == delKey) {
				break;
			}
			pPre = pDel;
			pDel = pDel->Next;
		}
		if (pDel == NULL) cout << "\nKhong tim thay phan tu can xoa";
		else {
			// So can xoa o dau danh sach
			if (pDel == l.Head) {
				l.Head = l.Head->Next;
				pDel->Next = NULL;
				delete pDel;
				pDel = NULL;
			}
			// So can xoa o cuoi danh sach
			else if (pDel->Next == NULL) {
				l.Tail = pPre;
				pPre->Next = NULL;
				delete pDel;
				pDel = NULL;
			}
			// So can xoa o giua danh sach
			else {
				pPre->Next = pDel->Next;
				pDel->Next = NULL;
				delete pDel;
				pDel = NULL;
			}
		}
	}
}
void XoaDau(List& l) {
	//tao node p
	Node* p = new Node;
	//gan p bang node pHead dau tien cua danh sach 
	p = l.Head;
	//thay doi lai pHead cua danh sach
	l.Head = l.Head->Next;
	//gan node p ban dau tro den NULL
	p->Next = NULL;
	//xoa node p
	delete p;
}

void XoaCuoi(List& l)
{
	//duyet cac phan tu co trong danh sach
	for (Node* k = l.Head; k != NULL; k = k->Next)
	{
		//neu duyet den phan tu pTail cuoi trong danh sach
		if (k->Next == l.Tail)
		{
			//xoa phan tu cuoi
			delete l.Tail;
			//tro phan tu truoc phan tu cuoi ve NULL
			k->Next = NULL;
			//thay doi lai phan tu cuoi pTail cua danh sach
			l.Tail = k;
		}
	}
}

// Xoa phan tu co khoa k trong DSLK
void XoaKhoaK(List& l, int delKey) {
	//tao node p de luu tru phan tu truoc node k can xoa
	Node* p = new Node;
	//neu data dau vao bang voi pHead->data thi xoa dau
	if (l.Head->key == delKey) {
		//goi ham xoa dau
		XoaDau(l);
		//ket thuc ham
		return;
	}
	//neu data bang voi pTail->data thi xoa cuoi
	if (l.Tail->key == delKey) {
		//goi ham xoa cuoi
		XoaCuoi(l);
		//ket thuc ham
		return;
	}
	//duyet qua cac phan tu co trong danh sach
	for (Node* k = l.Head; k != NULL; k = k->Next) {
		//neu tim thay data trung voi k->data dang duyet
		if (k->key == delKey) {
			//gan con tro next cua node p bang con tro next cua node k
			p->Next = k->Next;
			//xoa di node k
			delete k;
			//ket thuc ham
			return;
		}
		//gan node p bang node k de node p luon la node dung truoc node k
		p = k;
	}
}



int findNode(List l, int x, int n) {
	int idx = 1;
	for (Node* k = l.Head; k && idx <= n; k = k->Next, idx++) {
		if (k->key == x) {
			cout << "\nTim thay " << x << " tai vi tri " << idx << "  ";
		}
	}
	return -1;
}

// Tron 2 danh sach cac so nguyen tang dan thanh mot danh sach tang dan
Node* merge(List l1, List l2) {
	Node* p = new Node;
	List l;
	init(l);
	while (l1.Head != NULL && l2.Head != NULL) {
		if (l1.Head->key <= l2.Head->key) {
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
void dsNhap(List& l, int n) {
	init(l);
	for (int i = 1; i <= n; i++) {
		int key;
		cout << "\nNhap vao node thu " << i << ": ";
		cin >> key;
		Node* p = createNode(key);
		addLast(l, p);
	}
}
void dsXuat(List l) {
	for (Node* k = l.Head; k != NULL; k = k->Next)
		cout << k->key << "  ";
}

void GiaiPhong(List& l) {
	Node* p;
	while (l.Head != NULL) {
		p = l.Head;
		l.Head = l.Head->Next;
		delete p;
	}
}
// Sap xep DSLK theo thu tu tang dan
void SortList(List& l) {
	for (Node* k = l.Head; k != NULL; k = k->Next) {
		for (Node* h = k->Next; h != NULL; h = h->Next) {
			if (k->key > h->key) {
				int temp = k->key;
				k->key = h->key;
				h->key = temp;
			}
		}
	}
}

void getMiddleNode(List l) {
	Node* slow = l.Head;
	Node* fast = l.Head;
	if (l.Head != NULL) {
		while (fast != NULL && fast->Next != NULL) {
			fast = fast->Next->Next;
			slow = slow->Next;
		}
		cout << "\nPhan tu o chinh giua DSLK la: " << slow->key;
	}
}

// Odd even linked list (chan le)
// Nhóm các nút có chỉ số chẵn lại với nhau, các nút có chỉ số lẻ lại với nhau
Node* oddEven(List l) {
	if (l.Head == NULL) return NULL;
	Node* odd = l.Head;
	Node* even = l.Head->Next;
	Node* evenHead = even;
	while (even != NULL && even->Next != NULL) {
		odd->Next = even->Next;
		odd = odd->Next;
		even->Next = odd->Next;
		even = even->Next;
	}
	odd->Next = evenHead;
	return l.Head;
}
void menu() {
	int ch;
	bool quit = false;
	List l; 
	init(l);
	do {
		system("cls");
		cout << "============*DANH SACH LIEN KET*============" << endl;
		cout << "1. Nhap DSLK" << endl;
		cout << "2. Xuat DSLK" << endl;
		cout << "3. Them node vao vi tri bat ky trong DSLK" << endl;
		cout << "4. Them node p vao truoc node q trong DSLK" << endl;
		cout << "5. Them node p vao sau node q trong DSLK" << endl;
		cout << "6. Tim vi tri cua node trong DSLK" << endl;
		cout << "7. Tron 2 danh sach lien ket thanh DSLK sap xep" << endl;
		cout << "8. Sap xep DSLK" << endl;
		cout << "9. Tim phan tu chinh giua DSLK" << endl;
		cout << "10. Thoat" << endl;
		cout << "=============================================" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch) {
		case 1:
		{
			cout << "\nNhap so luong node cua DSLK: ";
			cin >> n;
			dsNhap(l, n);
			cout << "\nDa nhap thanh cong DSLK!";
			system("pause");
		}
		break;
		case 2:
		{
			dsXuat(l);
			system("pause");
		}
		break;
		case 3:
		{
			// Lay so luong node trong DSLK
			for (Node* k = l.Head; k != NULL; k = k->Next) {
				n++;
			}

			int vt;
			do {
				cout << "\nNhap vi tri can them: ";
				cin >> vt;
				if (vt < 1 || vt > n + 1) {
					cout << "\nVi tri khong hop le";
					system("pause");
				}
			} while (vt < 1 || vt > n + 1);
			
			int x;
			cout << "\nNhap gia tri node can them: ";
			cin >> x;
			Node* p = createNode(x);
			addIndex(l, p, vt, n);
			system("pause");
		}
		break;
		case 4:
		{
			int x;
			cout << "\nNhap gia tri node q trong DSLK: ";
			cin >> x;
			Node* q = createNode(x); // Khoi tao 1 node q

			int addBefore;
			cout << "\nNhap vao node can them truoc node q: ";
			cin >> addBefore;
			Node* p = createNode(addBefore);
			insertMidBefore(l, p, q);
			system("pause");
		}
		break;
		case 5:
		{
			int x;
			cout << "\nNhap gia tri node q trong DSLK: ";
			cin >> x;
			Node* q = createNode(x); // Khoi tao 1 node q
			int addAfter;
			cout << "\nNhap vao node can them sau node q: ";
			cin >> addAfter;
			Node* pA = createNode(addAfter);
			insertMidAfter(l, pA, q);
			system("pause");
		}
		break;
		case 6:
		{
			int searchNode;
			cout << "\nNhap vao node can tim kiem: ";
			cin >> searchNode;
			int res = findNode(l, searchNode, n);
			if (res == -1) cout << "\nKhong tim thay " << searchNode << " trong DSLK";
			system("pause");
		}
		break;
		case 7:
		{
			List l1, l2;
			init(l1); init(l2);
			cout << "\nNhap DSLK thu nhat: ";
			int n1;
			cout << "\nNhap so luong List 1: ";
			cin >> n1;
			dsNhap(l1, n1);
			dsXuat(l1);
			cout << "\nNhap DSLK thu hai: ";
			int n2;
			cout << "\nNhap so luong List 2: ";
			cin >> n2;
			dsNhap(l2, n2);
			dsXuat(l2);
			l.Head = merge(l1, l2);
			cout << "\nDSLK sau khi sap xep: ";
			dsXuat(l);
			system("pause");
		}
		break;
		case 8: 
		{
			SortList(l);
			system("pause");
		}
		break;
		case 9:
		{
			getMiddleNode(l);
			system("pause");
		}
		break;
		case 10:
		{
			l.Head = oddEven(l);
			cout << "\nDa chuyen thanh Odd Even Linked List. Nhap 2 de kiem tra";
			system("pause");
		}
		break;
		}
	} while (!quit);
	
}
int main() {
	menu();
	return 0;
}