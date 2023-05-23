#include<iostream>
using namespace std;
/* node of avl tree */
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};
/* Function to get the height of the tree */
int height(Node* N) {
    if (N == NULL)
        return 0;
    return N->height;
}
/* Function to get maximum of two integers */
int max(int a, int b) {
    return (a > b) ? a : b;
}
/* Update height of node */
void update_height(Node* node) {
    node->height = max(height(node->left),
        height(node->right)) + 1;
}
Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // new node is initially
    // added at leaf
    return(node);
}
// Quay phai
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    // Perform rotation
    x->right = y;
    y->left = T2;
    // Update height
    update_height(y);
    update_height(x);
    // return new root
    return x;
}
// Quay trai
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    // Perform rotate
    y->left = x;
    x->right = T2;
    // Update height
    update_height(x);
    update_height(y);
    // Return new root
    return y;
}

// Get Balance factor of node N (lay he so can bang)
int getBalance(Node* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

// Insert
Node* insert(Node* node, int key)
{
    /* 1. Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys are not allowed in BST
        return node;

    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
        height(node->right));

    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}


// Tim node co khoa nho nhat
Node* minValueNode(Node* node)
{
    Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// Delete
Node* deleteNode(Node* root, int key)
{

    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == NULL)
        return root;

    // in left subtree 
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // in right subtree 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then 
    // This is the node to be deleted 
    else
    {
        // node with only one child or no child 
        if ((root->left == NULL) ||
            (root->right == NULL))
        {
            Node* temp = root->left ?
                root->left :
                root->right;

            // No child case 
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case 
                *root = *temp; // Copy the contents of 
            // the non-empty child 
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's 
            // data to this node 
            root->key = temp->key;

            // Delete the inorder successor 
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node
    // then return 
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = getBalance(root);

    // If this node becomes unbalanced, 
    // then there are 4 cases 

    // Left Left Case 
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case 
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case 
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case 
    if (balance < -1 &&
        getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// preorder traversal 
void preOrder(Node* root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
// In cay 
void printTree(Node* root, int h) {
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
void printTree(Node* root) {
    printTree(root, 0);
}
void menu() {
    Node* root = NULL;
    int ch;
    bool quit = false;
    do {
        system("cls");
        cout << "===============AVL TREE===============" << endl;
        cout << "1. Them nut vao cay AVL" << endl;
        cout << "2. In cay AVL" << endl;
        cout << "3. Duyet cay theo thu tu preorder" << endl;
        cout << "4. Xoa mot nut khoi cay AVL" << endl;
        cout << "5. Thoat" << endl;
        cout << "======================================" << endl;
        cout << "Nhap lua chon: " << endl;
        cin >> ch;
        switch (ch) {
        case 1:
        {
            root = insert(root, 9);
            root = insert(root, 5);
            root = insert(root, 10);
            root = insert(root, 0);
            root = insert(root, 6);
            root = insert(root, 11);
            root = insert(root, -1);
            root = insert(root, 1);
            root = insert(root, 2);
            cout << "Da them node vao cay AVL. Nhap 2 hoac 3 de kiem tra !" << endl;
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
            preOrder(root);
            system("pause");
        }
        break;
        case 4:
        {
            root = deleteNode(root, 10);
            cout << "Da xoa node 10 khoi danh sach. Nhap 2 hoac 3 de kiem tra!" << endl;
            system("pause");
        }
        break;
        case 5:
        {
            quit = true;
            system("pause");
        }
        break;
        default:
        {
            cout << "Lua chon khong hop le!" << endl;
            system("pause");
        }
        break;
        }

    } while (!quit);
}
int main()
{
    menu();
    return 0;
}