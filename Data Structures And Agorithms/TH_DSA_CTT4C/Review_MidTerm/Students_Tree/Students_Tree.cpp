#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct NgaySinh {
	int ngay, thang, nam;
};
struct SinhVien {
	char* name;
	char* id;
	bool gioitinh = 1;
	double lt = 0;
	double th = 0;
	double tb = 0;
	NgaySinh ngsinh;
};
struct Node {
	SinhVien key;
	Node* left, * right;
};
typedef Node* Tree;
void TreeInit(Tree& root) {
	root = NULL;
}
void StudentInit(SinhVien& key) {
	key.name = new char[30];
	key.id = new char[30];
}
Node* createNode(SinhVien& key) {
	Node* p = new Node;
	if (p != NULL) {
		p->key = key;
		p->left = p->right = NULL;
	}
	return p;
}
void InsertNode(Tree& root,Node* p) {
	if (root == NULL) root = p;
	else if (strcmp(root->key.id, p->key.id) > 0) InsertNode(root->left, p);
	else if (strcmp(root->key.id, p->key.id) < 0) InsertNode(root->right, p);
	else return;
}
istream& operator>>(istream& CIN, SinhVien& key) {
	StudentInit(key);
	cout << "\nNhap ho ten: ";
	CIN.ignore();
	CIN.getline(key.name, 30);
	cout << "\nNhap ID: ";
	CIN.getline(key.id, 30);
	cout << "\nNhap gioi tinh (1-Nu, 0-Nam): ";
	CIN >> key.gioitinh;
	cout << "\nNhap ngay thang nam sinh: ";
	CIN >> key.ngsinh.ngay >> key.ngsinh.thang >> key.ngsinh.nam;
	cout << "\nNhap diem ly thuyet: ";
	CIN >> key.lt;
	cout << "\nNhap diem thuc hanh: ";
	CIN >> key.th;
	key.tb = key.lt * 0.7 + key.th * 0.3;
	return CIN;
}
void NhapDS(Tree&root){
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
void DocNgaySinh(ifstream& filein, NgaySinh&ngsinh) {
	filein >> ngsinh.ngay;
	filein.ignore();
	filein >> ngsinh.thang;
	filein.ignore();
	filein >> ngsinh.nam;
	filein.ignore();
}
void DocSinhVien(ifstream& filein, SinhVien& key) {
	StudentInit(key);
	filein.getline(key.name, 30, ',');
	filein >> key.gioitinh;
	filein.ignore();
	DocNgaySinh(filein, key.ngsinh);
	filein.getline(key.id, 30, ',');
	filein >> key.lt;
	filein.ignore();
	filein >> key.th;
	filein.ignore();
}
void DocDS(ifstream& filein, Tree& root) {
	SinhVien key;
	while (filein.peek() != EOF) {
		DocSinhVien(filein, key);
		Node* p = createNode(key);
		InsertNode(root, p);
	}
}
ostream& operator <<(ostream &COUT, SinhVien key) {
	cout << "\nHo ten: " << key.name;
	cout << "\nMa so: " << key.id;
	if (key.gioitinh == 1) cout << "\nGioi tinh: Nu";
	else cout << "\nGioi tinh: Nam";
	cout << "\nNgay sinh: " << key.ngsinh.ngay << "/" << key.ngsinh.thang << "/" << key.ngsinh.nam;
	key.tb = key.lt * 0.7 + key.th * 0.3;
	cout << "\nDiem trung binh: " << key.tb;
	return COUT;
}
void XuatDS(Tree root) {
	if (root != NULL) {
		cout << root->key << endl;
		XuatDS(root->left);
		XuatDS(root->right);
	}
}

void printNode(char* id, int h) {
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
void Xoa(Tree& root, char* id) {
	if (root == NULL) {
		cout << "\nKhong tim thay id can xoa!";
		return;
	}
	else {
		if (strcmp(root->key.id, id) > 0) Xoa(root->left, id);
		else if (strcmp(root->key.id, id) < 0) Xoa(root->right, id);
		else {
			Node* x = root;
			if (root->left == NULL) root = root->right;
			else if (root->right == NULL) root = root->left;
			else getMin(x,root->right);
			delete x;
		}
	}
}
int height(Tree root)
{
	if (root == NULL)
		return 0;
	else {
		/* compute the height of each subtree */
		// Tinh chieu cao cua moi cay con
		int lheight = height(root->left);
		int rheight = height(root->right);

		/* use the larger one */
		// Lay chieu cao lon hon
		if (lheight > rheight) {
			return (lheight + 1);
		}
		else {
			return (rheight + 1);
		}
	}
}
void sort(Tree root) {
	SinhVien key;
	key.tb = key.th * 0.7 + key.th * 0.3;
	if (root != NULL) {
		sort(root->left);
		cout << key.tb << "  ";
		sort(root->right);
	}
}
// Tim SV co gpa thap nhat

void Menu() {
	int ch;
	bool quit = false;
	Tree root;
	TreeInit(root);
	do {
		system("cls");
		cout << "=========QUAN LY SINH VIEN========" << endl;
		cout << "1. Nhap danh sach sinh vien" << endl;
		cout << "2. Doc file danh sach sinh vien" << endl;
		cout << "3. Xuat danh sach sinh vien" << endl;
		cout << "4. In cay nhi phan ID sinh vien" << endl;
		cout << "5. Xoa sinh vien voi ma so bat ky" << endl;
		cout << "=============================" << endl;
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
			char* id = new char[30];
			cout << "\nNhap ID can xoa: ";
			cin >> id;
			Xoa(root, id);
			system("pause");
		}
		break;
		case 6:
		{
			sort(root);
			system("pause");
		}
		}

	} while (!quit);
}
int main() {
	Menu();
	return 0;
}