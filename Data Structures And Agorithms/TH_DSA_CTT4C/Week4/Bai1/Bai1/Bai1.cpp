#include<iostream>
using namespace std;
typedef struct Node {
    //khai bao du lieu cua node co kieu du lieu int
    int key;
    //khai bao con tro den cay con trai va phai
    Node* left, * right;
};
typedef struct Node* Tree;
Tree root;
void Init(Tree& root) {
    //gan node goc ve NULL
    root = NULL;
}
Node* CreateNode(int x) {
    //tao node moi
    Node* p = new Node;
    //neu cay nhi phan khong rong
    if (p != NULL) {
        //gan cay con trai va cay con phai mac dinh bang NULL
        p->left = NULL;
        p->right = NULL;
        //gan key bang x
        p->key = x;
    }
    //tra ve node p
    return p;
}
int InsertNode(Tree& root, Node* p) {
    //neu node root khac rong thi thuc hien them vao cay
    if (root != NULL) {
        //neu 2 data cua 2 node bang nhau thi ket thuc
        if (root->key == p->key) {
            return 0;
        }
        //neu khoa cua root lon hon khoa cua p thi goi de quy trai 
        if (root->key > p->key) {
            return InsertNode(root->left, p);
        }
        else {//neu khoa cua root nho hon khoa cua p thi goi de quy phai 
            return InsertNode(root->right, p);
        }
    }
    else { //truong hop neu node root la rong thi them node p vao node root
        root = p;
    }
}
// In cay 
void printTree(Tree root, int h) {
    if (root == nullptr) {
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

// Nhap du lieu cho cay nhi phan
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
// Duyet cay theo thu tu Preorder (Root-Left-Right)
void NLR(Tree root) {
    if (root != NULL) {
        //xu ly node goc
        cout << root->key << " ";
        //su dung de quy de duyet tiep cay con trai
        NLR(root->left);
        //su dung de quy de duyet tiep cay con phai
        NLR(root->right);
    }
}
// Duyet cay theo thu tu Inorder (Left-Root-Right)
void LNR(Tree root) {
    if (root != NULL) {
        //su dung de quy de duyet tiep cay con trai
        LNR(root->left);
        //xy ly node goc
        cout << root->key << " ";
        //su dung de quy de duyet tiep cay con phai
        LNR(root->right);
    }
}
// Duyet cay theo thu tu Postorder (Left-Right-Root)
void LRN(Tree root) {
    if (root != NULL) {
        //su dung de quy de duyet tiep cay con trai
        LRN(root->left);
        //su dung de quy de duyet tiep cay con phai
        LRN(root->right);
        //xu ly node goc
        cout << root->key << " ";
    }
}

// Tinh chieu cao cua cay
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

void print_level(Tree root, int level_no) {
    // Prints the nodes in the tree
    // having a level = level_no

    // We have a auxiliary root node for printing the root of every subtree
    if (!root)
        return;
    if (level_no == 0) {
        // We are at the top of a subtree
        // So print the auxiliary root node
        cout << root->key << "  ";
    }
    else {
        // Make the auxiliary root node to be the left and right nodes for the subtrees and decrease level by 1
        // since you are moving from top to bottom
        print_level(root->left, level_no - 1);
        print_level(root->right, level_no - 1);
    }

}
// In cay theo muc
void print_tree_level_order(Tree root) {
    if (!root)
        return;
    int h = height(root);
    for (int i = 0; i < h; i++) {
        cout << "\nLevel " << i << ": ";
        print_level(root, i);
        cout << endl;
    }
    cout << "\n----Complete Level Order Traversal:------\n";
    for (int i = 0; i < h; i++) {
        print_level(root, i);
    }
    cout << endl;
}

// Tim kiem node su dung de quy
Node* searchNodeByRecursion(Tree root, int x) {
    if (root != NULL) {
        if (root->key == x) {
            return root;
        }
        if (root->key > x) {
            return searchNodeByRecursion(root->left, x);
        }
        else {
            return searchNodeByRecursion(root->right, x);
        }
    }
    return NULL;
}

// Tim kiem node khong dung de quy
Node* searchNodeWithoutRecursion(Tree root, int x) {
    while (root != NULL) {
        if (root->key == x) {
            return root;
        }
        else if (root->key > x) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return NULL;
}


void NodeTheMang(Tree& x, Tree& y)
{
    // Tim node trai nhat cua cay con phai
    // Duyet sang ben trai nhat
    if (y->left != NULL)
    {
        NodeTheMang(x, y->left); // Tim ra node trai nhat
    }
    else // Da tim thay node trai nhat
    {
        x->key = y->key; // cap nhat lai key cua node can xoa la key cua node the mang
        x = y; // cho node X (se xoa) tro den node the mang ==> ra khoi ham se xoa node X
        y = y->right; // cap nhat lai lien ket cho node cha cua node the mang (se xoa) voi node con cua node the mang
    }
}
// Xoa node
void XoaNode(Tree& root, int key) // key la gia tri cua node can xoa
{
    // Neu cay rong
    if (root == NULL)
    {
        cout << "\nKhong tim thay node can xoa !";
        return; // Ket thuc ham
    }
    else
    {
        // Neu key nho hon node goc
        if (key < root->key)
        {
            XoaNode(root->left, key); // Duyet sang nhanh trai cua cay
        }
        else if (key > root->key)
        {
            XoaNode(root->right, key); // Duyet sang nhanh phai cua cay
        }
        else // key == root->key - da tim ra node can xoa
        {
            Node* X = root; // node X la node the mang, se bi xoa 
            // Co mot con phai
            if (root->left == NULL)
            {
                // Duyet sang phai node can xoa de cap nhat lien ket giua node cha cua node can xoa voi node con cua no
                root = root->right;
            }
            // Co mot con trai
            else if (root->right == NULL)
            {
                // Duyet sang phai node can xoa de cap nhat lien ket giua node cha cua node can xoa voi node con cua no
                root = root->left;
            }
            else // Co hai con
            {
                // Tim node trai nhat cua cay con phai va dua len
                NodeTheMang(X, root->right);
            }
            delete X; // Xoa node can xoa
        }
    }
}
// Tinh tong cac nut co gia tri lon hon x trong cay
int sum(Tree root, int x) {
    if (root != NULL) {
        if (root->key > x)
            return root->key + sum(root->left, x) + sum(root->right, x);
        return sum(root->left, x) + sum(root->right, x);
    }
    return 0;
}
void menu() {
    int ch;
    bool quit = false;
    //tao cay voi node goc la root
    Tree root;
    //khoi tao cay
    Init(root);
    do {
        system("cls");
        cout << "=======================================================" << endl;
        cout << "*CAY NHI PHAN TIM KIEM*";
        cout << "\n1. Nhap cay";
        cout << "\n2. Xuat cay";
        cout << "\n3. Duyet cay theo thu tu preorder";
        cout << "\n4. Duyet cay theo thu tu inorder";
        cout << "\n5. Duyet cay theo thu tu postorder";
        cout << "\n6. Duyet cay theo muc";
        cout << "\n7. Chieu cao cua cay";
        cout << "\n8. Them node vao cay";
        cout << "\n9. Tim kiem node trong cay";
        cout << "\n10. Xoa node khoi cay";
        cout << "\n11. Tinh tong cac nut trong cay co gia tri lon hon x";
        cout << "\n12. Thoat";
        cout << "\n======================================================" << endl;
        cout << "\nNhap lua chon: "; cin >> ch;
        switch (ch)
        {
        case 1:
            //nhap n phan tu vao cay
            Input(root);
            cout << "\nDa nhap cay thanh cong !";
            system("pause");
            break;
        case 2:
            printTree(root);
            system("pause");
            break;
        case 3:
            NLR(root);
            system("pause");
            break;
        case 4:
            LNR(root);
            system("pause");
            break;
        case 5:
            LRN(root);
            system("pause");
            break;
        case 6:
            print_tree_level_order(root);
            system("pause");
            break;
        case 7:
            cout << "\nChieu cao cua cay la: " << height(root);
            system("pause");
            break;
        case 8:
        {
            int x;
            cout << "\nNhap node can them: ";
            cin >> x;
            Node* p = CreateNode(x);
            InsertNode(root, p);
            cout << "\nDa them node vao danh sach !";
            system("pause");
        }
        break;
        case 9:
        {
            int x;
            cout << "\nNhap node can tim kiem: ";
            cin >> x;
            Node* temp = searchNodeByRecursion(root, x);
            if (temp != NULL) cout << "\nDa tim thay node " << x << " trong cay !";
            else cout << "\nKhong tim thay node " << x << " trong cay !";
            system("pause");
        }
        break;
        case 10:
        {
            int x;
            cout << "\nNhap node can xoa: ";
            cin >> x;
            /*if (searchNodeByRecursion(root, x)) {
                XoaNode(root, x);
                cout << "\nXoa node thanh cong !";
            }
            else cout << "\nKhong tim thay node can xoa !";*/
            XoaNode(root, x);
            system("pause");
        }
        break;
        case 11:
        {
            int x;
            do {
                cout << "\nNhap node x: ";
                cin >> x;
                if (!searchNodeByRecursion(root, x)) {
                    cout << "\nNode " << x << " khong co trong danh sach. Moi ban nhap lai!";
                    system("pause");
                }
            } while (!searchNodeByRecursion(root, x));
            cout << "\nTong cac node lon hon " << x << " la: " << sum(root, x);
            system("pause");
        }
        break;
        case 12:
            quit = true;
            break;
        default:
            cout << "\nLua chon khong hop le !";
            system("pause");
            break;
        }
    } while (!quit);
}
int main() {
    menu();
    return 0;
}