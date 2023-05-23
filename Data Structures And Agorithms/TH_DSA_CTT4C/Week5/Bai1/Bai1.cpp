#include<iostream>
#include<string>
#define COUNT 10
using namespace std;
struct Node
{
    string s;
    Node* left, * right;
};
typedef Node* Tree;

// Khoi tao node
Node* CreateNode(string s)
{
    Node* p = new Node();
    if (p == NULL)
    {
        cout << "khong du bo nho";
        system("pause");
        exit(1);
    }
    p->s = s;
    p->left = p->right = NULL;
    return p;
}
// Khoi tao cay
void TreeInit(Tree& root)
{
    root = NULL;
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
    cout << root->s << "\n";
    // Duyet qua cay con trai
    print_BinaryTree(root->left, space);
}


void print2D(Tree root)
{
    print_BinaryTree(root, 0);
}
// Ham tinh gia tri cua cay bieu thuc
int solveExpressionTree(Tree root) {

    if (!root)
        return 0;

    if (!root->left && !root->right)
        // Chuyen doi tu string ve int 
        return stoi(root->s);
    // Xu ly nhanh ben trai
    int leftSubTreeSol = solveExpressionTree(root->left);
    // Xu ly nhanh ben phai
    int rightSubTreeSol = solveExpressionTree(root->right);

    // Thuc hien cac phep toan
    if (root->s == "+")
        return leftSubTreeSol + rightSubTreeSol;

    if (root->s == "-")
        return leftSubTreeSol - rightSubTreeSol;

    if (root->s == "*")
        return leftSubTreeSol * rightSubTreeSol;

    if (root->s == "/")
        return leftSubTreeSol / rightSubTreeSol;

    return -1;
}
int main()
{
    Tree root;
    TreeInit(root);
    string s;
    root = CreateNode("+");
    root->left = CreateNode("*");
    root->left->left = CreateNode("5");
    root->left->right = CreateNode("4");
    root->right = CreateNode("-");
    root->right->left = CreateNode("100");
    root->right->right = CreateNode("/");
    root->right->right->left = CreateNode("20");
    root->right->right->right = CreateNode("2");
    cout << "\nCay bieu thuc: ";
    print2D(root);
    cout << "Gia tri cua cay bieu thuc la: " << solveExpressionTree(root);
    system("pause");
    return 0;
}
