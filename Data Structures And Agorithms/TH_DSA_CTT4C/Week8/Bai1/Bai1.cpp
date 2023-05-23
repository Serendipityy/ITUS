#include<iostream>
using namespace std;
#define COUNT 10
struct Node {
	int key;
	Node* left, * right;
};
typedef Node* Tree;

Node* createNode(int x) {
	Node* p = new Node;
	if (p != NULL) {
		p->left = p->right = NULL;
		p->key = x;
	}
	return p;
}

// In cay nhi phan
void print_BinaryTree(Tree root, int space)
{
    if (root == NULL)
        return;
    // Tang khoang cach giua cac level
    space += COUNT;
    // Duyet qua con phai
    print_BinaryTree(root->right, space);
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->key << "\n";
    // Duyet qua cay con trai
    print_BinaryTree(root->left, space);
}
void print2D(Tree root)
{
    print_BinaryTree(root, 0);
}


int max(int x, int y) {
    return(x >= y) ? x : y;
}
// Ham tinh chieu cao cua cay
int height(Tree root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Ham kiem tra cay la cay AVL
bool isAVL(Node* root) {
    int lHeight;
    int rHeight;
    if (root == NULL) return 1;
    lHeight = height(root->left);
    rHeight = height(root->right);
    if (abs(lHeight - rHeight) <= 1 && isAVL(root->left) && isAVL(root->right)) return 1;
    return 0;
}
int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(8);
    root->right->left = createNode(9);
    root->right->right = createNode(9);
    print2D(root);
    if (isAVL(root))
        cout << "\nDay la cay AVL";
    else cout << "\nKhong phai cay AVL";
	return 0;
}