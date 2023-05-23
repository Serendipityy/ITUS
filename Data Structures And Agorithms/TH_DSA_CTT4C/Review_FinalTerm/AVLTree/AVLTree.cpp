#include<iostream>
using namespace std;
struct Node {
	int key;
	Node* left;
	Node* right;
	int height;
};
typedef Node* Tree;
int height(Tree root) {
	if (root == NULL) return 0;
	return root->height;
}
int max(int a, int b) {
	return (a > b) ? a : b;
}
void updateHeight(Tree root) {
	root->height = max(height(root->left), height(root->right)) + 1;
}
Node* createNode(int key) {
	Node* node = new Node;
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return node;
}
// Quay phai
Node* rightRotate(Node* y) {
	Node* x = y->left;
	Node* T2 = x->right;
	x->right = y;
	y->left = T2;
	updateHeight(y);
	updateHeight(x);
	return x;
}
// Quay trai
Node* leftRotate(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;
	y->left = x;
	x->right = T2;
	updateHeight(x);
	updateHeight(y);
	return y;
}
// Lay he so can bang
int getBalance(Tree root) {
	if (root == NULL) return 0;
	return height(root->left) - height(root->right);
}

// Insert
Node* insert(Tree root, int key) {
	if (root == NULL) return createNode(key);
	if (key < root->key)
		root->left = insert(root->left, key);
	else if (key > root->key)
		root->right = insert(root->right, key);
	else return root;
	// Update height
	updateHeight(root);
	// Get balance
	int balance = getBalance(root);
	// left left
	if (balance > 1) {
		if (key < root->left->key) return rightRotate(root);
		else if (key > root->left->key) {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balance < -1) {
		if (key > root->right->key) return leftRotate(root);
		else if (key < root->right->key) {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}

// Tim nodo nho nhat
Node* minValue(Tree root) {
	Node* curr = root;
	while (curr->left != NULL)
		curr = curr->left;
	return curr;
}
// Xoa
Node* delNode(Tree root, int delKey) {
	if (root == NULL) return root;
	if (delKey < root->key)
		root->left = delNode(root->left, delKey);
	else if (delKey > root->key)
		root->right = delNode(root->right, delKey);
	else {
		if (root->left == NULL || root->right == NULL) {
			Node* temp = root->left ? root->left : root->right;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else {
				*root = *temp;
				delete temp;
			}
		}
		else {
			Node* temp = minValue(root->right);
			root->key = temp->key;
			root->right = delNode(root->right, temp->key);
		}
	}

	if (root == NULL) return root;
	updateHeight(root);
	int balance = getBalance(root);
	if (balance > 1) {
		if (getBalance(root->left) >= 0) return rightRotate(root);
		else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balance < -1) {
		if (getBalance(root->right) <= 0) return leftRotate(root);
		else {
			root->right = rightRotate(root->right);
			return rightRotate(root);
		}
	}
	return root;
}
// Nhap du lieu cho cay
void Input(Tree& root) {
	int n;
	cout << "\nNhap so luong node cua cay: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cout << "\nNhap key cua node thu " << i << ": ";
		cin >> x;
		root = insert(root, x);
	}
}
void NLR(Tree root) {
	if (root != NULL) {
		cout << root->key << "  ";
		NLR(root->left);
		NLR(root->right);
	}
}
// In cay
void printTree(Tree root, int h) {
	if (root == NULL) {
		for (int i = 0; i < h; i++)
			cout << "   ";
		cout << "*  " << endl;
		return;
	}
	printTree(root->right, h + 1);
	for (int i = 0; i < h; i++)
		cout << "   ";
	cout << root->key << endl;
	printTree(root->left, h + 1);
}
void printTree(Tree root) {
	printTree(root, 0);
}
// Tim kiem mot khoa trong cay
Node* searchNode(Tree root, int x) {
	if (root == NULL) {
		cout << "\nKhong tim thay " << x << " trong cay";
		return root;
	}
	if (root->key == x) {
		cout << "\nTim thay " << x << " trong cay";
		return root;
	}
	else {
		if (x > root->key) return searchNode(root->right, x);
		else if (x < root->key) return searchNode(root->left, x);
	}
}

bool check(Tree root, Node* temp, int k) {
	if (root == NULL) return false;
	Node* c = root;
	bool flag = false;
	while (c != NULL && flag != true) {
		if (c->key == k && temp != c) {
			flag = true;
			cout << "\nTim thay cap node: " << c->key << " + " << temp->key; 
			return true;
		}
		else if (k < c->key) c = c->left;
		else c = c->right;
	}
	return false;
}
bool isPair(Tree root, Node* temp, int target) {
	if (temp == NULL) return false;
	return check(root, temp, target - temp->key)
		|| isPair(root, temp->left, target)
		|| isPair(root, temp->right, target);
}
// Tim node co gia tri lon thu k trong cay
int visitedIdx, value;
void findMax(Tree root, int k) {
	if (root->right != NULL) findMax(root->right, k);
	visitedIdx++;
	if (visitedIdx == k) {
		value = root->key;
	}
	if (root->left != NULL) findMax(root->left, k);
}
int KthMax(Tree root, int k) {
	visitedIdx = 0;
	value = INT_MAX;
	findMax(root, k);
	return value;
}

// Tim node co khoa nho thu k trong cay

Node* findMin(Tree root, int& k) {
	if (root == NULL) return NULL;
	Node* left = findMin(root->left, k);
	if (left != NULL) return left;
	if (k-- == 1) return root;
	Node* right = findMin(root->right, k);
	if (right != NULL) return right;
	return NULL;
}
int KthMin(Tree root, int k) {
	Node* res = findMin(root, k);
	return res->key;
}
void menu() {
	Tree root = NULL;
	int ch;
	bool quit = false;
	do {
		system("cls");
		cout << "===================*CAY AVL*==================" << endl;
		cout << "1. Nhap cay AVL" << endl;
		cout << "2. Xuat cay duoi dang hinh ve" << endl;
		cout << "3. Duyet cay" << endl;
		cout << "4. Them nut co khoa bat ky vao cay AVL" << endl;
		cout << "5. Xoa mot nut khoi cay AVL" << endl;
		cout << "6. Tim kiem mot nut trong cay AVL" << endl;
		cout << "7. Kiem tra tong 2 khoa co bang sum cho truoc" << endl;
		cout << "8. Tim node co khoa lon thu k trong cay" << endl;
		cout << "9. Tim node co khoa nho thu k trong cay" << endl;
		cout << "==============================================" << endl;
		cout << "\nNhap lua chon: ";
		cin >> ch;
		switch (ch) {
		case 1:
		{
			Input(root);
			cout << "\nDa nhap cay thanh cong";
			system("pause");
		}
		break;
		case 2:
		{
			printTree(root);
			system("pause");
		}
		break;
		case 3:
		{
			cout << "\nDuyet cay theo thu tu Preorder: ";
			NLR(root);
			system("pause");
		}
		break;
		case 4:
		{
			int addKey;
			cout << "\nNhap vao khoa can them: ";
			cin >> addKey;
			root = insert(root, addKey);
			cout << "\nDa them " << addKey << " vao cay. Nhap 2 de kiem tra";
			system("pause");
		}
		break;
		case 5:
		{
			int delKey;
			cout << "\nNhap vao node can xoa: ";
			cin >> delKey;
			root = delNode(root, delKey);
			system("pause");
		}
		break;
		case 6:
		{
			int searchKey;
			cout << "\nNhap vao node can tim: ";
			cin >> searchKey;
			Node*temp = searchNode(root, searchKey);
			system("pause");
		}
		break;
		case 7:
		{
			int sum;
			cout << "\nNhap vao tong: ";
			cin >> sum;
			bool test = isPair(root, root, sum);
			if (!test) cout << "\nKhong tim thay cap node thoa man";
			system("pause");
		}
		break;
		case 8:
		{
			int k;
			cout << "\nNhap gia tri k: ";
			cin >> k;
			cout << "\nNode co khoa lon thu "<< k <<" trong cay la : " << KthMax(root, k);
			system("pause");
		}
		break;
		case 9: 
		{
			int k;
			cout << "\nNhap gia tri k: ";
			cin >> k;
			cout<<"\nNode co khoa nho thu "<<k<<" trong cay la: "<< KthMin(root, k);
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