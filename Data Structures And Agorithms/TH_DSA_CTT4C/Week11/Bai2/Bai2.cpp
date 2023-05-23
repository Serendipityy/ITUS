#include<iostream>
using namespace std;
struct Node {
    int key;
    Node* pLeft, * pRight;
};
typedef Node* Tree;
void Init(Tree& root) {
    root = NULL;
}
Node* CreateNode(int x) {
    Node* p = new Node;
    if (p != NULL) {
        p->pLeft = NULL;
        p->pRight = NULL;
        p->key = x;
    }
    return p;
}

void InsertNode(Tree& root, Node* p) {
    if (root == NULL) root = p;
    else if (root->key > p->key) InsertNode(root->pLeft, p);
    else if (root->key < p->key) InsertNode(root->pRight, p);
    else return;
}
// In cay nhi phan
void printTree(Tree t, int h) {
    if (t == nullptr) {
        for (int i = 0; i < h; i++)
            cout << "   ";
        cout << "*  " << endl;
        return;
    }
    printTree(t->pRight, h + 1);
    for (int i = 0; i < h; i++)
        cout << "   ";
    cout << t->key << endl;
    printTree(t->pLeft, h + 1);
}
void printTree(Tree root) {
    printTree(root, 0);
}

// Nhap cay
void Input(Tree& root) {
    int n;
    cout << "\nNhap so luong node can them: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cout << "\nNhap key cua node thu " << i << ": ";
        cin >> x;
        //tao node p co data = x
        Node* p = CreateNode(x);
        //them node p co data x vao trong cay
        InsertNode(root, p);
    }
}
void Inorder(Tree root) {
    if (root != NULL) {
        Inorder(root->pLeft);
        cout << root->key << " ";
        Inorder(root->pRight);
    }
}
void Preorder(Tree root) {
    if (root != NULL) {
        cout << root->key << " ";
        Preorder(root->pLeft);
        Preorder(root->pRight);
    }
}

void Postorder(Tree root) {
    if (root != NULL) {
        Postorder(root->pLeft);
        Postorder(root->pRight);
        cout << root->key << " ";
    }
}
Node* searchNode(Tree root, int x) {
    while (root != NULL) {
        if (root->key == x) {
            return root;
        }
        else if (root->key > x) {
            root = root->pLeft;
        }
        else {
            root = root->pRight;
        }
    }
    return NULL;
}

// Tim nut co khoa nho nhat
int TimMin(Tree root)
{

    if (root->pLeft == NULL)
    {
        return root->key;
    }
    return TimMin(root->pLeft);
}


// Xoa nut co khoa x 
void NodeTheMang(Tree& x, Tree& y)
{
    if (y->pLeft != NULL)
    {
        NodeTheMang(x, y->pLeft);
    }
    else
    {
        x->key = y->key;
        x = y;
        y = y->pRight;
    }
}
void XoaNode(Tree& root, int key)
{
    if (root == NULL)
    {
        cout << "\nKhong tim thay node can xoa !";
        return;
    }
    else
    {
        if (key < root->key)
        {
            XoaNode(root->pLeft, key);
        }
        else if (key > root->key)
        {
            XoaNode(root->pRight, key);
        }
        else
        {
            Node* X = root;
            if (root->pLeft == NULL)
            {
                root = root->pRight;
            }
            else if (root->pRight == NULL)
            {
                root = root->pLeft;
            }
            else
            {
                NodeTheMang(X, root->pRight);
            }
            delete X;
        }
    }
}
// Kiem tra 2 nut co phai la anh em ruot
bool isSibling(Node* root, int x, int y)
{
    if (root == NULL) return 0;
    bool a = false, b = false, c = false;
    if (root->pLeft != NULL && root->pRight != NULL)
        a = ((root->pLeft->key == x && root->pRight->key == y) ||
            (root->pLeft->key == y && root->pRight->key == x));
    if (root->pLeft != NULL)
        b = isSibling(root->pLeft, x, y);
    if (root->pRight != NULL)
        c = isSibling(root->pRight, x, y);
    return (a || b || c);
}
void Menu() {
    int ch;
    bool quit = false;
    Tree root;
    Init(root);
    do {
        system("cls");
        cout << "=======*CAY NHI PHAN TIM KIEM*=======" << endl;
        cout << "1. Nhap danh sach node" << endl;
        cout << "2. Xuat danh sach node duoi dang cay nhi phan" << endl;
        cout << "3. Tim nut co khoa nho nhat trong cay" << endl;
        cout << "4. Xoa mot nut co khoa la x ra khoi cay" << endl;
        cout << "5. Kiem tra hai nut a, b co phai la anh em ruot" << endl;
        cout << "6. Thoat" << endl;
        cout << "=====================================" << endl;
        cout << "\nNhap lua chon: "; cin >> ch;
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
            int min = TimMin(root);
            cout << "Node nho nhat trong cay la: " << min;
            system("pause");
        }
        break;
        case 4:
        {
            int x;
            cout << "\nNhap vao nut can xoa: ";
            cin >> x;
            XoaNode(root, x);
            system("pause");
        }
        break;
        case 5:
        {
            int x, y;
            cout << "\nNhap gia tri cua node thu nhat: "; cin >> x;
            cout << "\nNhap gia tri cua node thu hai: "; cin >> y;
            if (isSibling(root, x, y))
                cout << "\nHai node " << x << " va " << y << " la anh em ruot";
            else
                cout << "\nHai node " << x << " va " << y << " khong phai anh em ruot";
            system("pause");
        }
        break;
        case 6:
        {
            quit = true;
            system("pause");
        }
        break;
        default:
        {
            cout << "\nLua chon khong hop le!";
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
