#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
static const int ENTRIES = 100; // So tu
static const int DEFAULT_SIZE = 101; // Kich thuoc mac dinh cua Hash Table

/* Cau truc node cua Hash Table cai dat tu dien */
struct Node {
	string eng;
	string vi;
};

/* Cau truc Hash Table */
struct Hash {
	int itemCount; // Count of dictionary entries
	int hashTableSize; // Table size must be prime
	vector<vector<Node>> hashTable; // Array of pointers to entries
};

/* Ham khoi tao Bang bam */
void init_Hash(Hash& h) {
	h.itemCount = ENTRIES;
	h.hashTableSize = DEFAULT_SIZE;
	h.hashTable = vector<vector<Node>>(DEFAULT_SIZE);
}
/* Ham bam */
unsigned int hashFunc(Hash h, string s) {
	unsigned int hash_value = 0;
	unsigned int r = 127;
	for (int k = 0; k < s.length(); k++)
		hash_value = (hash_value * r + (int)tolower(s[k])) % h.hashTableSize;
	return hash_value;	
}
//unsigned int hashFunc(Hash h, string key) {
//	long sum = 0, mul = 1;
//	for (int i = 0; i < key.length(); i++) {
//		mul = (i % 4 == 0) ? 1 : mul * 256;
//		sum += key.at(i) * mul;
//	}
//	return (int)(abs(sum) % h.hashTableSize);
//}
//
//// Method 2: 
//unsigned int hashFunc(Hash h, string s) {
//	size_t r = 0;
//	for (size_t i = 0; i < s.length(); i++)
//		r = r * 31 + s[i];
//	return (r % h.hashTableSize);
//}
// Method 3: 
//unsigned int hashFunc(Hash h, const std::string& key)
//{
//	int hashVal = 0;
//	for (int i = 0; i < key.length(); i++)
//	{
//		hashVal = 37 * hashVal + key[i];
//	}
//	hashVal %= h.hashTableSize;
//
//	if (hashVal < 0)
//		hashVal += h.hashTableSize;
//	return hashVal;
//}

// So sanh 2 chuoi ky tu khong phan biet chu hoa, chu thuong
bool compareChar(char& c1, char& c2)
{
	return (toupper(c1) == toupper(c2));
}
bool String_IgnoreCase(std::string& s1, std::string& s2) {
	return((s1.size() == s2.size()) && std::equal(s1.begin(), s1.end(), s2.begin(), &compareChar));
}

/* Ham tra ve vi tri tu can tim */
int findWord(Hash h, unsigned int& hash_word, string word) {
	hash_word = hashFunc(h, word);
	for (int i = 0; i < h.hashTable[hash_word].size(); i++) {
		if (String_IgnoreCase(word, h.hashTable[hash_word][i].eng))
			return i;
	}
	return -1;
}

/* Ham doc mot tu */
void readWord(ifstream& filein, Node& node) {
	getline(filein, node.eng, ':');
	getline(filein, node.vi);
}

/* Ham them 1 item vao bang bam */
void add(Hash& h, Node node, bool& flag) {
	unsigned int hash_node = 0;
	int nodePos = findWord(h, hash_node, node.eng);
	if (nodePos == -1) {
		h.hashTable[hash_node].push_back(node);
	}
	else
		flag = 1;
}

/* Ham doc danh sach tu vung */
void readDictionary(ifstream& filein, Hash& h) {
	init_Hash(h);
	while (filein.peek() != EOF) {
		Node node;
		bool flag = 0;
		readWord(filein, node);
		add(h, node, flag);
	}
}

/* Xoa 1 item */
void deleteItem(Hash& h, string del) {
	unsigned int hash_del = 0;
	int delPos = findWord(h, hash_del, del);
	if (delPos == -1)
		cout << "\nKhong tim thay tu can xoa trong tu dien\n";
	else {
		h.hashTable[hash_del].erase(h.hashTable[hash_del].begin() + delPos);
		cout << "\nDa xoa tu " << del << " ra khoi tu dien\n";
	}
}

/* Ham cap nhat nghia moi cho tu*/
void updateItem(Hash& h, string word) {
	unsigned int hash_word = 0;
	string new_meaning;
	int wordPos = findWord(h, hash_word, word);
	if (wordPos == -1)
		cout << "\nKhong tim thay tu can cap nhat trong tu dien\n";
	else {
		cout << "\nNhap nghia moi cho tu: ";
		cin.ignore();
		getline(cin, new_meaning);
		h.hashTable[hash_word][wordPos].vi = new_meaning;
		cout << "\nDa cap nhat thanh cong nghia cua tu\n";
	}
}

/* Ham in bang bam */
void display(Hash h) {
	for (int i = 0; i < h.hashTable.size(); i++) {
		cout << i;
		for (int j = 0; j < h.hashTable[i].size(); j++) {
			cout << " ---> " << h.hashTable[i][j].eng << ": " << h.hashTable[i][j].vi;
		}
		cout << endl;
	}
}

void menu() {
	int ch;
	bool quit = false;
	Hash h;
	do {
		system("cls");
		cout << "======*UNG DUNG TU DIEN VOI HASH TABLE*======" << endl;
		cout << "1. Doc tu dien tu file" << endl;
		cout << "2. Xuat tu dien" << endl;
		cout << "3. Tim kiem mot tu trong tu dien" << endl;
		cout << "4. Cap nhat nghia cua tu trong tu dien" << endl;
		cout << "5. Them mot tu vao tu dien" << endl;
		cout << "6. Xoa mot tu khoi tu dien" << endl;
		cout << "7. Thoat" << endl;
		cout << "==============================================" << endl;
		cout << "Nhap lua chon: "; cin >> ch;

		switch (ch) {
		case 1:
		{
			ifstream filein;
			char fileName[30];
			cout << "\nNhap ten file: "; cin >> fileName;
			filein.open(fileName, ios::in);
			if (!filein) {
				cout << "\nTen file khong hop le!";
				system("pause");
			}
			else {
				readDictionary(filein, h);
				cout << "\nDa doc file thanh cong. Nhap 2 de kiem tra\n";
				system("pause");
			}
			filein.close();
		}
		break;
		case 2:
		{
			display(h);
			system("pause");
		}
		break;
		case 3:
		{
			string searchWord;
			cout << "\nNhap vao tu can tim kiem: ";
			cin.ignore();
			getline(cin, searchWord);
			unsigned int hash_search = 0;
			int find = findWord(h, hash_search, searchWord);
			if (find == -1) {
				cout << "\nTu ban tim kiem khong co trong tu dien\n";
				system("pause");
			}
			else {
				cout << "\nTim thay tu " << searchWord << " trong tu dien\n";
				system("pause");
			}
		}
		break;
		case 4:
		{
			string updateMeaning;
			cout << "\nNhap vao tu can cap nhat: ";
			cin.ignore();
			cin >> updateMeaning;
			updateItem(h, updateMeaning);
			system("pause");
		}
		break;
		case 5:
		{
			Node node;
			bool flag = 0; // Kiem tra tu da co trong 
			cout << "\nNhap vao tu tieng Anh can them: ";
			cin.ignore();
			getline(cin, node.eng);
			cout << "\nNhap nghia cua tu tieng Anh vua them: ";
			getline(cin, node.vi);
			add(h, node, flag);
			if (flag == 1)
				cout << "\nTu ban them da ton tai\n";
			else
				cout << "\nThem tu thanh cong\n";
			system("pause");
		}
		break;
		case 6:
		{
			string delWord;
			cout << "\nNhap tu can xoa: ";
			cin.ignore();
			getline(cin, delWord);
			deleteItem(h, delWord);
			system("pause");
		}
		break;
		case 7:
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
	menu();
	return 0;
}