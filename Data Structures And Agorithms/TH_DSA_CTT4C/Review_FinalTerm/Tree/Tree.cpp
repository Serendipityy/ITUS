#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int key;
	Node* left, * right;
}; typedef Node* Tree;
// Khoi tao cay
void init(Tree &root) {
	root = NULL;
}
// Khoi tao node
Node* createNode(int x) {
	Node* p = new Node;
	if (p != NULL) {
		p->left = NULL;
		p->right = NULL;
		p->key = x;
	}
	return p;
}
// Insert
void Insert(Tree& root, Node* p) {
	if (root == NULL) root = p;
	else if (p->key < root->key) Insert(root->left, p);
	else if (p->key > root->key) Insert(root->right, p);
	else return;
}
// In cay
void printTree(Tree root, int h) {
	if (root == NULL) {
		for (int i = 0; i < h; i++)
			cout << "  ";
		cout << "*  " << endl;
		return;
	}
	printTree(root->right, h + 1);
	for (int i = 0; i < h; i++)
		cout << "  ";
	cout << root->key << endl;
	printTree(root->left, h + 1);
}
void printTree(Tree root) {
	printTree(root, 0);
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
		Node* p = createNode(x);
		Insert(root, p);
	}
}
// Duyet cay
void NLR(Tree root) {
	if (root != NULL) {
		cout << root->key << "  ";
		NLR(root->left);
		NLR(root->right);
	}
}
void LNR(Tree root) {
	if (root != NULL) {
		LNR(root->left);
		cout << root->key << "  ";
		LNR(root->right);
	}
}
void LRN(Tree root) {
	if (root != NULL) {
		LRN(root->left);
		LRN(root->right);
		cout << root->key << "  ";
	}
}
// Tinh chieu cao cua cay
//int height(Tree root) {
//	if (root == NULL) return 0;
//	else {
//		int lHeight = height(root->left);
//		int rHeight = height(root->right);
//		if (lHeight > rHeight) return lHeight + 1;
//		else return rHeight + 1;
//	}
//}
// Cach khac de tinh chieu cao
int max(int x, int y) {
	return (x >= y) ? x : y;
}
int height(Tree root) {
	if (root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}
// In cay theo muc
void printLevel(Tree root, int lv_no) {
	if (!root) return;
	if (lv_no == 0) cout << root->key << "  ";
	else {
		printLevel(root->left, lv_no - 1);
		printLevel(root->right, lv_no - 1);
	}
}
void printTreeLevelOrder(Tree root) {
	if (!root) return;
	int h = height(root);
	for (int i = 0; i < h; i++) {
		cout << "\nLevel " << i << ": ";
		printLevel(root, i);
		cout << endl;
	}
	cout << "\n----Thu tu duyet cay theo muc:----\n";
	for (int i = 0; i < h; i++) {
		printLevel(root, i);
	}
	cout << endl;
}

// Tim kiem node co key bat ky trong cay
// Dung de quy
Node* searchNode_Recursion(Tree root, int x) {
	if (root != NULL) {
		if (root->key == x) return root;
		if (root->key > x) return searchNode_Recursion(root->left, x);
		else return searchNode_Recursion(root->right, x);
	}
	return NULL;
}
// Khong dung de quy
Node* searchNode_noRecursion(Tree root, int x) {
	while (root != NULL) {
		if (root->key == x) return root;
		else if (root->key > x) root = root->left;
		else root = root->right;
	}
	return NULL;
}

// Tim node co khoa nho nhat va lon nhat trong cay
int Min(Tree root) {
	if (root->left == NULL) return root->key;
	return Min(root->left);
}

int Max(Tree root) {
	if (root->right == NULL) return root->key;
	return Max(root->right);
}

// Xoa node
// Tim node trai nhat cua cay con phai
void getMinRight(Tree& root, Tree& delNode) {
	if (delNode->left != NULL) getMinRight(root, delNode->left);
	else {
		root->key = delNode->key;
		root = delNode;
		delNode = delNode->right;
	}
}
void Xoa(Tree& root, int delKey) {
	if (root == NULL) {
		cout << "\nKhong tim thay node can xoa";
		return;
	}
	else {
		if (delKey < root->key) Xoa(root->left, delKey);
		else if (delKey > root->key) Xoa(root->right, delKey);
		else {
			Node* temp = root;
			if (root->left == NULL) root = root->right;
			else if (root->right == NULL) root = root->left;
			else getMinRight(temp, root->right);
			delete temp;
		}
	}
}

void deletion(Tree root, int val)
{
	if (root == NULL)
		return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* res = q.front();
		q.pop();

		if (val < res->key) {
			if (res->left)
				q.push(res->left);
		}

		else if (val > res->key) {
			if (res->right)
				q.push(res->right);

		}
		else {
			if (res->left == NULL && res->right == NULL)   //leaf node 
			{
				delete res; // This deletion is causing error
				return;
			}
			else if (res->left == NULL)   //one child (right) 
			{
				Node* temp = res;
				res = res->right;
				delete temp; // This deletion is causing error
				return;
			}
			else if (res->right == NULL)  //one child (left)
			{
				Node* temp = res;
				res = res->left;
				delete temp; // This deletion is causing error
				break;
			}
			else // 2 children case working fine
			{
				Node* succParent = res;
				Node* succ = res->right;
				while (succ->left != NULL) {
					succParent = succ;
					succ = succ->left;
				}
				if (succParent != res)
					succParent->left = succ->right;
				else
					succParent->right = succ->right;
				res->key = succ->key;
				delete succ;
				return;
			}
		}
	}
}
Node* locateNode(Tree root, int key, Node*& parent) {
	while (root) {
		if (root->key > key) {
			parent = root;
			root = root->left;
		}
		else if (root->key < key) {
			parent = root;
			root = root->right;
		}
		else {
			return root;
		}
	}
	return NULL;
}

void deleteNode(Tree root, int value)
{
	Node* parent = NULL;
	// locate node
	Node* target = locateNode(root, value , parent);
	// key not found
	if (target == NULL) {
		return;
	}
	//leaf
	if (!target->left && !target->right) {
		//root is the target
		if (parent == NULL) {
			return;
		}
		if (parent->left == target) {
			parent->left = NULL;
		}
		if (parent->right == target) {
			parent->right = NULL;
		}
		return;
	}
	// find successor down the right substree
	if (target->right) {
		Node* succ = target->right;
		Node* succParent = target;
		while (succ->left) {
			succParent = succ;
			succ = succ->left;
		}
		// target's right child does not have left child
		if (succParent == target) {
			succParent->right = succ->right;
		}
		else {
			succParent->left = succ->right;
		}
		target->key = succ->key;
	}
	// find predecessor down the left subtree
	else {
		Node* pred = target->left;
		Node* predParent = target;
		while (pred->right) {
			predParent = pred;
			pred = pred->right;
		}
		// target's left child does not have right child
		if (predParent == target) {
			predParent->left = pred->left;
		}
		else {
			predParent->right = pred->left;
		}
		target->key = pred->key;
	}
}

void xoaNode(Tree root, int key) {
	// Find the Node
	Node* prev = nullptr;
	Node* cur = root;
	while (cur && cur->key != key) {
		prev = cur;
		cur = (key < cur->key) ? cur->left : cur->right;
	}

	// special cases: either case return root no change to BST
	// 1. if tree passed is empty: Not required as per contraints (completeness sake) 
	// 2. If key is not found
	if (cur == nullptr) {
		cout << "\nKhong tim thay node can xoa";
		return;
	}
	// key is found in tree
	// Delete Case 1: Node to be deleted is leaf node
	if (cur->left == nullptr && cur->right == nullptr) {
		// Special case: leaf node is root :)
		if (prev == nullptr) {
			root = nullptr;
		}
		else if (prev->left == cur) {
			prev->left = nullptr;
		}
		else {
			prev->right = nullptr;
		}
		delete cur;
		return;
	}
	if (cur->left == nullptr || cur->right == nullptr) {
		// Delete Case 2: Node to be deleted has single child
		Node* child = (cur->left) ? cur->left : cur->right;

		// Special Case: If node to be deleted is root which single child /Sub tree
		if (prev == nullptr) {
			root = child;
		}
		else if (prev->left == cur) {
			prev->left = child;
		}
		else {
			prev->right = child;
		}
		delete cur;
		return;
	}
	// Delete case 3: Node to be deleted has both left and right child/sub tree
	prev = cur;
	Node* successor = cur->right;
	while (successor->left) {
		prev = successor;
		successor = successor->left;
	}
	cur->key = successor->key;
	// Now delete successor
	if (prev->left == successor)
		prev->left = successor->right;
	else
		prev->right = successor->right;
	delete successor;
	return;
}
// Tinh tong cac khoa lon hon x trong cay
int sum(Tree root, int x) {
	if (root != NULL) {
		if (root->key > x)
			return root->key + sum(root->left, x) + sum(root->right, x);
		return sum(root->left, x) + sum(root->right, x);
	}
	return 0;
}

// Kiem tra 2 nut co phai anh em ruot
//bool checkSiblings(Tree root, int x, int y) {
//	if (root == NULL) return 0;
//	bool a = false, b = false, c = false;
//	if (root->left != NULL && root->right != NULL) {
//		a = ((root->left->key == x && root->right->key == y) || (root->left->key == y && root->right->key == x));
//	}
//	if (root->left != NULL) b = checkSiblings(root->left, x, y);
//	if (root->right != NULL) c = checkSiblings(root->right, x, y);
//	return a || b || c;
//}

// Kiem tra 2 nut co phai anh em ruot
bool isSiblings(Tree root, int x, int y) {
	if (root == NULL) return 0;
	return (root->left->key == x && root->right->key == y)
		|| (root->left->key == y && root->right->key == x)
		|| isSiblings(root->left, x, y)
		|| isSiblings(root->right, x, y);
}
// Kiem tra cay co phai cay AVL
bool AVL(Tree root) {
	int lHeight;
	int rHeight;
	if (root == NULL) return true;
	lHeight = height(root->left);
	rHeight = height(root->right);
	if (abs(lHeight - rHeight) <= 1 && AVL(root->left) && AVL(root->right)) return true;
	return false;
}
// Tim level cua 1 node
int findLevel(Tree root, int x, int lv) {
	if (root == NULL) return 0;
	if (root->key == x) return lv;
	int level = findLevel(root->left, x, lv + 1);
	if (level != 0) return level;
	return findLevel(root->right, x, lv + 1);
}
int getLevel(Tree root, int x) {
	return findLevel(root, x, 0);
}

// Kiem tra 2 node co phai anh em ho (cousin)
// 2 node tren cung 1 level va khong co cung bo me
bool isCousins(Tree root, int x, int y) {
	if(getLevel(root,x)==getLevel(root,y) && !(isSiblings(root,x,y))) return true;
		return false;
}
// C2:
//int xdepth, ydepth, xparent, yparent;
//void depth(Tree root, int x, int y, int dep, int par_val) {
//	if (root == NULL) return;
//	if (root->key == x) {
//		xdepth = dep;
//		xparent = par_val;
//		return;
//	}
//	if (root->key == y) {
//		ydepth = dep;
//		yparent = par_val;
//		return;
//	}
//	depth(root->left, x, y, dep + 1, root->key);
//	depth(root->right, x, y, dep + 1, root->key);
//}
//bool isCousins(Tree root, int x, int y) {
//	if (root->key == x || root->key == y) return false;
//	depth(root, x, y, 0, 0);
//	if (xdepth == ydepth && xparent != yparent) return true;
//	return false;
//}

// Can bang cay nhi phan tim kiem
void storeBSTNodes(Tree root, vector<Node*>& nodes) {
	if (root == NULL) return;
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}
Node* buildTreeUtil(vector<Node*> &nodes, int start, int end) {
	if (start > end) return NULL;
	int mid = (start + end) / 2;
	Node* root = nodes[mid];
	root->left = buildTreeUtil(nodes, start, mid - 1);
	root->right = buildTreeUtil(nodes, mid + 1, end);
	return root;
}
Node* buildTree(Tree root) {
	vector<Node*> nodes;
	storeBSTNodes(root,nodes);
	int n = nodes.size();
	return buildTreeUtil(nodes, 0, n - 1);
}

// Tim to tien chung thap nhat (Lowest common ancestor)
Node* LCA(Tree root, int x, int y) {
	if (root == NULL) return NULL;
	if (x < root->key && y < root->key) return LCA(root->left, x, y);
	if (x > root->key && y > root->key) return LCA(root->right, x, y);
	return root;
}

// Chuyen doi cay BST thanh greater sum tree (moi node chua tong cua tat ca cac node lon hon no)
void reverse(Tree root, int& cnt) {
	if (!root) return;
	reverse(root->right, cnt);
	root->key += cnt;
	cnt = root->key;
	reverse(root->left, cnt);
}
void BSTtoDST(Tree root) {
	int cnt = 0;
	reverse(root, cnt);
}

// Dem so luong so nguyen to trong cay
bool checkPrime(int x) {
	if (x < 2) return false;
	else {
		if (x == 2) return true;
		else {
			if (x % 2 == 0) return false;
			else {
				for (int i = 2; i < x; i++) {
					if (x % i == 0) return false;
				}
			}
		}
	}
	return true;
}

void countPrime(Tree root, int &cnt) {
	if (root != NULL) {
		if (checkPrime(root->key)) {
			cnt++;
		}
		countPrime(root->left, cnt);
		countPrime(root->right, cnt);
	}
}
bool isLeafNode(Tree root) {
	return(root->left == NULL && root->right == NULL);
}
int count(Tree root) {
	if (root != NULL) {
		if(root->left!=NULL && root->right!=NULL
			&& isLeafNode(root->left) && isLeafNode(root->right)) {
			return 1+count(root->left) + count(root->right);
		}
		return count(root->left) + count(root->right);
	}
	return 0;
}
void printArray(int a[], int n, int h) {
	if (n == h) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
bool isLeaf(Tree root) {
	return (root->left == nullptr && root->right == nullptr);
}
void printNodes(Tree root, vector<int>& path) {
	if (root == NULL) return;
	path.push_back(root->key);
	if (isLeaf(root))
	{
		for (int data : path) {
			cout << data << " ";
		}
		cout << endl;
	}
	if (height(root->left) > height(root->right)) printNodes(root->left, path);
	else printNodes(root->right, path);
}
void longestPath(Tree root) {
	vector<int>path;
	printNodes(root, path);
}
void menu() {
	int ch;
	bool quit = false;
	Tree root;
	init(root);
	do {
		system("cls");
		cout << "======================*CAY NHI PHAN TIM KIEM*=====================" << endl;
		cout << "1. Nhap cay" << endl;
		cout << "2. Xuat cay" << endl;
		cout << "3. Duyet cay" << endl;
		cout << "4. In cay theo muc" << endl;
		cout << "5. Chieu cao cua cay" << endl;
		cout << "6. Tim kiem mot khoa bat ky trong cay" << endl;
		cout << "7. Tim node co khoa nho nhat va lon nhat trong cay" << endl;
		cout << "8. Them mot node vao cay" << endl;
		cout << "9. Xoa mot node ra khoi cay" << endl;
		cout << "10. Tinh tong cac node trong cay co gia tri lon hon x" << endl;
		cout << "11. Kiem tra 2 nut trong cay co phai la anh em ruot" << endl;
		cout << "12. Kiem tra cay co phai la cay AVL" << endl;
		cout << "13. Tim level cua mot node trong cay" << endl;
		cout << "14. Kiem tra 2 nut trong cay co phai la anh em ho" << endl;
		cout << "15. Can bang cay nhi phan tim kiem" << endl;
		cout << "16. Tim to tien chung gan nhat (Lowest Common Ancestor) trong cay" << endl;
		cout << "17. Chuyen cay BST thanh cay GST (Greater Sum Tree)" << endl;
		cout << "18. Dem so luong so nguyen to trong cay" << endl;
		cout << "==================================================================" << endl;
		cout << "\nNhap lua chon: ";
		cin >> ch;
		switch (ch) {
		case 1:
		{
			Input(root);
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
			cout << "\nDuyet cay theo thu tu Preorder (NLR):";
			NLR(root);
			cout << "\nDuyet cay theo thu tu Inorder (LNR): ";
			LNR(root);
			cout << "\nDuyet cay theo thu tu Postorder (LRN): ";
			LRN(root);
			system("pause");
		}
		break;
		case 4:
		{
			printTreeLevelOrder(root);
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
			int sKey;
			cout << "\nNhap vao khoa can tim kiem: ";
			cin >> sKey;
			Node*temp = searchNode_Recursion(root, sKey);
			if (temp != NULL) cout << "\nTim thay khoa " << sKey << " trong cay";
			else cout << "\nKhong tim thay khoa " << sKey << " trong cay";
			system("pause");
		}
		break;
		case 7:
		{
			cout << "\nNode co khoa nho nhat trong cay la: " << Min(root);
			cout << "\nNode co khoa lon nhat trong cay la: " << Max(root);
			system("pause");
		}
		break;
		case 8:
		{
			int aKey;
			cout << "\nNhap vao node can them: ";
			cin >> aKey;
			Node* p = createNode(aKey);
			Insert(root, p);
			cout << "\nDa them node vao danh sach";
			system("pause");
		}
		break;
		case 9:
		{
			int delKey;
			cout << "\nNhap vao node can xoa: ";
			cin >> delKey;
			/*Xoa(root, delKey);*/
			/*deletion(root, delKey);*/
			//deleteNode(root, delKey);
			xoaNode(root, delKey);
			system("pause");
		}
		break;
		case 10:
		{
			int x;
			do {
				cout << "\nNhap gia tri cua node x: ";
				cin >> x;
				if (!searchNode_Recursion(root, x)) {
					cout << "\Node " << x << " khong co trong cay";
					system("pause");
				}
			} while (!searchNode_Recursion(root, x));
			cout << "\nTong cac node co gia tri lon hon " << x << " trong cay la: " << sum(root, x);
			system("pause");
		}
		break;
		case 11:
		{
			int x, y;
			do {
				cout << "\nNhap gia tri cua node x: ";
				cin >> x;
				cout << "\nNhap gia tri cua node y: ";
				cin >> y;
				if (!searchNode_Recursion(root, x) || !searchNode_Recursion(root, y)) {
					cout << "\nNode ban nhap khong co trong cay";
					system("pause");
				}
			} while (!searchNode_Recursion(root, x) || !searchNode_Recursion(root, y));
			/*if (checkSiblings(root, x, y)) cout << "\nHai node " << x << " va " << y << " la anh em ruot";*/
			if (isSiblings(root, x, y)) cout << "\nHai node " << x << " va " << y << " la anh em ruot";
			else cout << "\nHai node " << x << " va " << y << " khong phai anh em ruot";
			system("pause");
		}
		break;
		case 12:
		{
			if (AVL(root)) cout << "\nDay la cay AVL";
			else cout << "\nDay khong phai la cay AVL";
			system("pause");
		}
		break;
		case 13:
		{
			int x;
			do {
				cout << "\nNhap vao node can tim level: ";
				cin >> x;
				if (!searchNode_Recursion(root, x)) {
					cout << "\nNode ban nhap khong co trong cay";
					system("pause");
				}
			} while (!searchNode_Recursion(root, x));
			cout << "Level cua " << x << " la: " << getLevel(root, x);
			system("pause");
		}
		break;
		case 14:
		{
			int x, y;
			do {
				cout << "\nNhap gia tri cua node x: ";
				cin >> x;
				cout << "\nNhap gia tri cua node y: ";
				cin >> y;
				if (!searchNode_Recursion(root, x) || !searchNode_Recursion(root, y)) {
					cout << "\nNode ban nhap khong co trong cay";
					system("pause");
				}
			} while (!searchNode_Recursion(root, x) || !searchNode_Recursion(root, y));
			if (isCousins(root, x, y)) cout << "\nHai node " << x << " va " << y << " la anh em ho";
			else cout << "\nHai node " << x << " va " << y << " khong phai anh em ho";
			system("pause");
		}
		break;
		case 15:
		{
			root = buildTree(root);
			cout << "\nDa can bang cay. Nhap 2 de kiem tra.";
			system("pause");
		}
		break;
		case 16:
		{
			int x, y;
			do {
				cout << "\nNhap gia tri cua node x: ";
				cin >> x;
				cout << "\nNhap gia tri cua node y: ";
				cin >> y;
				if (!searchNode_Recursion(root, x) || !searchNode_Recursion(root, y)) {
					cout << "\nNode ban nhap khong co trong cay";
					system("pause");
				}
			} while (!searchNode_Recursion(root, x) || !searchNode_Recursion(root, y));
			
			Node* p = LCA(root, x, y);
			cout << "\nTo tien chung gan nhat cua " << x << " va " << y << " la: " << p->key;
			system("pause");
		}
		break;
		case 17:
		{
			BSTtoDST(root);
			cout << "\nDa chuyen thanh cay GST. Nhap 2 de kiem tra";
			system("pause");
		}
		break;
		case 18:
		{
			int cnt = 0;
			countPrime(root, cnt);
			cout << "\nSo luong so nguyen to trong cay: " << cnt;
			system("pause");
		}
		break;
		case 19:
		{
			int get2child = count(root);
			cout << "\nSo nut co 2 con voi dieu kien 2 con la nut la: " << get2child;
			system("pause");
		}
		break;
		case 20:
		{
			longestPath(root);
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