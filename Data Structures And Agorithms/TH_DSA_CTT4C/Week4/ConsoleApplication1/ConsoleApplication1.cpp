#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;
struct NgaySinh {
	int ngay, thang, nam;
};
typedef NgaySinh NgayHeThong;

struct KhachHang {
	// string
	//string name;
	string sdt;
	string diachi;
	// char[]
	//char name[30];
	// 
	// char*
	char* name;
	NgaySinh ngsinh;
};

struct Node {
	KhachHang key;
	Node* left, * right;
};
typedef Node* Tree;

void initKhachHang(KhachHang& kh) {
	kh.name = new char[30];
}

Node* createNode(KhachHang key) {
	Node* node = new Node;
	if (node != NULL) {
		node->key = key;
		node->left = node->right = NULL;
	}
	return node;
}

//Them
void insertNode(Tree& root, Node* node) {
	if (root == NULL)
		root = node;
	else if (node->key.sdt > root->key.sdt)
		insertNode(root->right, node);
	else if (node->key.sdt < root->key.sdt)
		insertNode(root->left, node);
	else return;
}
// Xoa
// Tim nut trai nhat cua cay con phai
void getMin(Tree& root, Tree& delNode) {
	if (delNode->left != NULL) {
		getMin(root,delNode->left);
	}
	else {
		root->key.sdt = delNode->key.sdt;
		root = delNode;
		delNode = delNode->right;
	}
}
// Xoa node
void Xoa(Tree &root, string sdt) {
	if (root == NULL) {
		cout << "\nKhong tim thay so dien thoai can xoa ";
		return;
	}
	else {
		if (sdt < root->key.sdt) Xoa(root->left, sdt);
		else if(sdt > root->key.sdt) Xoa(root->right, sdt);
		else {
			Node* x = root;
			if (root->left == NULL) root = root->right;
			else if (root->right == NULL) root = root->left;
			else getMin(x, root->right);
			delete x;
		}
	}
}
/*Ham doc ngay sinh*/
void DocNgsinh(ifstream& filein, NgaySinh& ngsinh) {
	filein >> ngsinh.ngay;
	filein.ignore(1);
	filein >> ngsinh.thang;
	filein.ignore(1);
	filein >> ngsinh.nam;
	filein.ignore(1);
}
/*Ham doc thong tin mot khach hang*/
void DocKhachHang(ifstream& filein, KhachHang& key) {
	// String
	//getline(filein, key.name, ',');

	//char[]
	//filein.getline(key.name, 30,',');

	// char*
	initKhachHang(key);
	filein.getline(key.name,30, ',');
	DocNgsinh(filein, key.ngsinh);
	getline(filein, key.sdt, ',');
	getline(filein, key.diachi);

}
/*Ham doc danh ba*/
void DocDanhBa(ifstream& filein, Tree& root) {
	KhachHang key;
	while (filein.peek() != EOF) {
		DocKhachHang(filein, key);
		Node* node = createNode(key);
		insertNode(root, node);
	}
}
istream& operator>>(istream& CIN, KhachHang& key) {
	cout << "\nNhap ho ten: ";
	//CIN.ignore();
	// string
	//getline(CIN, key.name);
	// char[]
	//CIN.getline(key.name, 30);
	//char*
	initKhachHang(key);
	CIN >> key.name;
	cout << "\nNhap so dien thoai: ";
	CIN.ignore();
	getline(CIN, key.sdt);
	cout << "\nNhap dia chi: ";
	getline(CIN, key.diachi);
	cout << "\nNhap ngay sinh: ";
	CIN >> key.ngsinh.ngay >> key.ngsinh.thang >> key.ngsinh.nam;
	return CIN;
}
void NhapDS(Tree& root) {
	int n;
	cout << "\nNhap so luong khach hang: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "\nNhap thong tin khach hang thu " << i;
		KhachHang key;
		cin >> key;
		Node* node = createNode(key);
		insertNode(root, node);
	}
}
ostream& operator<<(ostream& COUT, KhachHang key) {
	COUT << "Ho ten: " << key.name << endl;
	COUT << "So dien thoai: " << key.sdt << endl;
	COUT << "Dia chi: " << key.diachi << endl;
	COUT << "Ngay sinh: " << key.ngsinh.ngay << "/" << key.ngsinh.thang << "/" << key.ngsinh.nam << endl;
	return COUT;
}

void XuatDS(Tree root) {
	if (root != NULL) {
		cout << root->key << endl;
		XuatDS(root->left);
		XuatDS(root->right);
	}
}
void printNode(string sdt, int h) {
	for (int i = 0; i < h; i++)
		cout << "           ";
	cout << sdt << endl << endl;
}
void printTree(Tree root, int h) {
	if (root == NULL) {
		for (int i = 0; i < h; i++)
			cout << "           ";
		cout << "*" << endl << endl;
		return;
	}
	printTree(root->right, h + 1);
	printNode(root->key.sdt, h);
	printTree(root->left, h + 1);
}
int main() {
	Tree root=NULL;
	ifstream filein;
	filein.open("danhba.txt", ios::in);
	DocDanhBa(filein, root);
	XuatDS(root);

	//NhapDS(root);
	//XuatDS(root);
	printTree(root,0);
	string sdt;
	cout << "\nNhap so dien thoai can xoa: ";
	cin >> sdt;
	Xoa(root, sdt);
	cout << "\nDanh sach sau khi xoa: ";
	XuatDS(root);
	system("pause");
	return 0;
}