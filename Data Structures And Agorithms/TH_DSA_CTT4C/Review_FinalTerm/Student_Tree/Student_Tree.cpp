#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct SinhVien {
	int id;
	string name; 
	float gpa;
};
struct Node {
	SinhVien key;
	Node* left, * right;
};
typedef Node* Tree;
void TreeInit(Tree& root) {
	root = NULL;
}

Node* createNode(SinhVien& key) {
	Node* p = new Node;
	if (p != NULL) {
		p->key = key;
		p->left = p->right = NULL;
	}
	return p;
}
void InsertNode(Tree& root, Node* p) {
	if (root == NULL) root = p;
	else if (root->key.id > p->key.id) InsertNode(root->left, p);
	else if (root->key.id < p->key.id) InsertNode(root->right, p);
	else return;
}
istream& operator>>(istream& CIN, SinhVien& key) {
	cout << "\nNhap ho ten: ";
	CIN.ignore();
	getline(CIN, key.name);
	cout << "\nNhap ID: ";
	cin >> key.id;
	cout << "\nNhap GPA: ";
	cin >> key.gpa;
	return CIN;
}
void NhapDS(Tree& root) {
	int n;
	cout << "\nNhap so luong sinh vien: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		SinhVien key;
		cout << "\nNhap thong tin sinh vien thu " << i;
		cin >> key;
		Node* p = createNode(key);
		InsertNode(root, p);
	}
}

void DocSinhVien(ifstream& filein, SinhVien& key) {
	filein >> key.id;
	filein.ignore();
	getline(filein, key.name, ',');
	filein >> key.gpa;
}
void DocDS(ifstream& filein, Tree& root) {
	SinhVien key;
	while (filein.peek() != EOF) {
		DocSinhVien(filein, key);
		Node* p = createNode(key);
		InsertNode(root, p);
	}
}
ostream& operator <<(ostream& COUT, SinhVien key) {
	cout << "\nHo ten: " << key.name;
	cout << "\nMa so: " << key.id;
	cout << "\nGPA: " << key.gpa;
	return COUT;
}
void XuatDS(Tree root) {
	if (root != NULL) {
		cout << root->key << endl;
		XuatDS(root->left);
		XuatDS(root->right);
	}
}

void printNode(int id, int h) {
	for (int i = 0; i < h; i++)
		cout << "          ";
	cout << id << endl << endl;
}
void printTree(Tree root, int h) {
	if (root == NULL) {
		for (int i = 0; i < h; i++)
			cout << "          ";
		cout << "*" << endl << endl;
		return;
	}
	printTree(root->right, h + 1);
	printNode(root->key.id, h);
	printTree(root->left, h + 1);
}

// Tinh chieu cao cua cay
int max(int a, int b) {
	return (a > b) ? a : b;
}
int height(Tree root) {
	if (root == 0) return 0;
	return max(height(root->left), height(root->right)) + 1;
}

// Tim SV co gpa thap nhat
void findGPAMin(Tree& root, Node*& min) {
	if (!root) return;
	if (min->key.gpa > root->key.gpa)
		min = root;
	findGPAMin(root->right, min);
	findGPAMin(root->left, min);
}

// Xoa SV co ID cho truoc ra khoi danh sach
void getMin(Tree& root, Tree& delNode) {
	if (delNode->left != NULL) {
		getMin(root, delNode->left);
	}
	else {
		root->key.id = delNode->key.id;
		root = delNode;
		delNode = delNode->right;
	}
}
void Xoa(Tree& root, int id) {
	if (root == NULL) {
		cout << "\nKhong tim thay ID can xoa";
		return;
	}
	else {
		Node* x = root;
		if (id < root->key.id) Xoa(root->left, id);
		else if (id > root->key.id) Xoa(root->right, id);
		else {
			Node* x = root;
			if (root->left == NULL) root = root->right;
			else if (root->right == NULL) root = root->left;
			else getMin(x, root->right);
			delete x;
		}
	}
}

// Dem so node cua cay
int countNode(Tree root) {
	if (root == NULL) return 0;
	return 1 + countNode(root->left) + countNode(root->right);
}

// Thay doi ten sinh vien co ID cho truoc
void editName(Tree& root, int id) {
	if (root == NULL) {
		cout << "\nKhong tim thay ID can thay doi";
		return;
	}
	else {
		if (root->key.id > id) editName(root->left, id);
		else if (root->key.id < id) editName(root->right, id);
		else if (root->key.id == id) {
			string newName;
			cout << "\nNhap ten can thay doi: ";
			cin >> newName;
			root->key.name = newName;
			cout << "\nDa thay doi ten. Nhap 2 de kiem tra";
		}
	}
}
void Menu() {
	int ch;
	bool quit = false;
	Tree root;
	TreeInit(root);
	do {
		system("cls");
		cout << "===========QUAN LY SINH VIEN===============" << endl;
		cout << "1. Nhap danh sach sinh vien" << endl;
		cout << "2. Doc file danh sach sinh vien" << endl;
		cout << "3. Xuat danh sach sinh vien" << endl;
		cout << "4. In cay nhi phan ID sinh vien" << endl;
		cout << "5. Tinh chieu cao cua cay" << endl;
		cout << "6. In thong tin sinh vien co GPA thap nhat" << endl;
		cout << "7. Xoa sinh vien voi id cho truoc" << endl;
		cout << "8. Dem so node trong cay" << endl;
		cout << "9. Thay doi ten cua sinh vien theo ID" << endl;
		cout << "===========================================" << endl;
		cout << "\nNhap lua chon: "; cin >> ch;
		switch (ch) {
		case 1:
		{
			NhapDS(root);
		}
		break;
		case 2:
		{
			ifstream filein;
			char fileName[30];
			cout << "\nNhap ten file: "; cin >> fileName;
			filein.open(fileName, ios::in);
			if (!filein) {
				cout << "\nKhong tim thay file!";
				system("pause");
			}
			else {
				DocDS(filein, root);
				cout << "\nDa doc file thanh cong!";
				system("pause");
			}
		}
		break;
		case 3:
		{
			XuatDS(root);
			system("pause");
		}
		break;
		case 4:
		{
			printTree(root, 0);
			system("pause");
		}
		break;
		case 5:
		{
			int h = height(root);
			cout << "\nChieu cao cua cay la: " << h;
			system("pause");
		}
		break;
		case 6:
		{
			Node* min = root;
			findGPAMin(root, min);
			cout << min->key;
			system("pause");
		}
		break;
		case 7:
		{
			int del;
			cout << "\nNhap ID can xoa: ";
			cin >> del;
			Xoa(root, del);
			system("pause");
		}
		break;
		case 8:
		{
			int cnt = countNode(root);
			cout << "\nSo node trong cay la: " << cnt;
			system("pause");
		}
		break;
		case 9:
		{
			int id;
			cout << "\nNhap ID cua sinh vien can thay doi ten: ";
			cin >> id;
			editName(root, id);
			system("pause");
		}
		break;
		}

	} while (!quit);
}
int main() {
	Menu();
	return 0;
}