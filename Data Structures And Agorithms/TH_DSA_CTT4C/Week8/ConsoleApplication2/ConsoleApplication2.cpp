#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	string key;
	string meaning;
	node* left;
	node* right;
};

class AVL
{
	node* root;
public:
	AVL()
	{
		root = NULL;
	}

	void create();
	node* insert(node* cur, node* temp);
	node* balance(node* temp);
	int dif(node* temp);
	int height(node* temp);
	int maximum(int a, int b);

	node* LL(node* par);
	node* RR(node* par);
	node* LR(node* par);
	node* RL(node* par);

	void ascending(node* temp);
	node* delete_n(node* root, string key1);
	void deleten();

	node* extractmin(node* t);
	void descending(node* temp);
	void display();
	bool search(node* cur, string key1);
	void search_value();
};

void AVL::create()
{
	char answer;
	node* temp;
	do
	{
		temp = new node();
		cout << "\nNhap tu khoa (keyword):";
		cin >> temp->key;
		cout << "\nNhap y nghia cua tu khoa (meaning):";
		cin >> temp->meaning;
		temp->left = temp->right = NULL;

		root = insert(root, temp);

		cout << "\nBan co muon nhap them tu khac khong?(yes: y / no: n)";
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
}


node* AVL::insert(node* cur, node* temp)
{
	if (cur == NULL)
	{
		return temp;
	}
	if (temp->key < cur->key)
	{
		cur->left = insert(cur->left, temp);
		cur = balance(cur);
	}
	else if (temp->key > cur->key)
	{
		cur->right = insert(cur->right, temp);
		cur = balance(cur);
	}
	return cur;
}

node* AVL::balance(node* temp)
{
	int bal;
	bal = dif(temp);

	if (bal >= 2)
	{
		if (dif(temp->left) < 0)
			temp = LR(temp);
		else
			temp = LL(temp);
	}
	else if (bal <= -2)
	{
		if (dif(temp->right) < 0)
			temp = RR(temp);
		else
			temp = RL(temp);
	}
	return temp;
}


int AVL::dif(node* temp)
{
	int l, r;
	l = height(temp->left);
	r = height(temp->right);
	return(l - r);
}

int AVL::height(node* temp)
{
	if (temp == NULL)
		return(-1);
	else
		return(max(height(temp->left), height(temp->right)) + 1);
}

int AVL::maximum(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

node* AVL::LL(node* par)
{
	node* temp, * temp1;
	temp = par->left;
	temp1 = temp->right;
	temp->right = par;
	par->left = temp1;
	return temp;
}

node* AVL::RR(node* par)
{
	node* temp, * temp1;
	temp = par->right;
	temp1 = temp->left;
	temp->left = par;
	par->right = temp1;
	return temp;
}

node* AVL::LR(node* par)
{
	par->left = RR(par->left);
	return(LL(par));
}

node* AVL::RL(node* par)
{
	par->right = LL(par->right);
	return(RR(par));
}

void AVL::ascending(node* temp)
{
	if (temp != NULL)
	{
		ascending(temp->left);
		cout << "\n\t" << temp->key << " : " << temp->meaning;
		ascending(temp->right);
	}
}

void AVL::descending(node* temp)
{
	if (temp != NULL)
	{
		descending(temp->right);
		cout << "\n\t" << temp->key << " : " << temp->meaning;
		descending(temp->left);
	}
}


void AVL::display()
{
	cout << "\nKeywords theo thu tu tang dan : \n";
	ascending(root);
	cout << "\nKeywords theo thu tu giam dan : \n";
	descending(root);
}

bool AVL::search(node* cur, string key1)
{
	if (cur)
	{
		if (cur->key == key1)
			return true;
		if (cur->key > key1)
			return search(cur->left, key1);
		else
			return search(cur->right, key1);
	}
	return false;
}

void AVL::search_value()
{
	string key2;
	cout << "\nNhap keyword ban muon tim kiem: ";
	cin >> key2;
	if (search(root, key2))
		cout << "\nKeyword ban can tim co trong cay AVL";
	else
		cout << "\nKeyword ban can tim khong co trong cay AVL";
}


node* AVL::delete_n(node* cur, string key1)
{
	if (!cur)
		return cur;
	if (key1 < cur->key)
		cur->left = delete_n(cur->left, key1);

	else if (key1 > cur->key)
		cur->right = delete_n(cur->right, key1);

	else
	{
		node* l = cur->left;
		node* r = cur->right;
		delete cur;
		if (!r)
			return l;
		node* m = r;

		while (m->left)
			m = m->left;
		m->right = extractmin(r);
		m->left = l;
		return balance(m);
	}
	return balance(cur);
}

node* AVL::extractmin(node* t)
{
	if (!t->left)
		return t->right;
	t->left = extractmin(t->left);
	return balance(t);
}

void AVL::deleten()
{
	string key;
	cout << "\nNhap keyword can xoa: ";
	cin >> key;
	root = delete_n(root, key);
}

int main()
{
	bool quit = false;
	int ch;
	AVL a;
	do
	{
		system("cls");
		cout << "******UNG DUNG TU DIEN BANG CAY AVL********";
		cout << "\n 1.Them tu khoa (keyword) vao cay AVL";
		cout << "\n 2.In tu dien";
		cout << "\n 3.Tim kiem tu khoa trong cay AVL";
		cout << "\n 4.Xoa mot tu khoa khoi cay AVL";
		cout << "\n*******************************************";
		cout << "\nNhap lua chon: ";
		cin >> ch;
		switch (ch)
		{
		case 1: a.create();
			system("pause");
			break;
		case 2: a.display();
			system("pause");
			break;
		case 3: a.search_value();
			system("pause");
			break;
		case 4: a.deleten();
			system("pause");
			break;
		default: cout << "\nLua chon khong hop le ! ";
			system("pause");
			break;
		}
	} while (!quit);
	return 0;
}