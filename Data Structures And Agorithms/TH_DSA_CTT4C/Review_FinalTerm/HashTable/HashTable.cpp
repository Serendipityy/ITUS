#include <iostream>
#include <list>
using namespace std;

// https://www.sanfoundry.com/cpp-program-implement-hash-tables/
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/?fbclid=IwAR0_ZbjzllaoTz8Qv78OYtNPe171kSBHrAab85yZkXHgz2Z9c6HHBmwbyuA
struct Hash {
    int slot; // No.
    list<int>* table;  // Pointer to an array containing buckets
};

/* Ham Khoi Tao Hash Table */
void create_Hash(Hash& h, int b)
{
    h.slot = b;
    h.table = new list<int>[h.slot];
}

/* Ham Hashing (map values to key)*/
int hashFunction(Hash h, int key)
{
    return (key % h.slot);
}

/* Them Item vao HTable */
void insertItem(Hash& h, int key)
{
    int index = hashFunction(h, key);
    h.table[index].push_back(key);
}

/* Xoa 1 Item */
void deleteItem(Hash h, int key)
{
    // get the hash index of key
    int index = hashFunction(h, key);

    // find the key in (index)th list
    list<int>::iterator i;
    for (i = h.table[index].begin();
        i != h.table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != h.table[index].end())
        h.table[index].erase(i);
}

// Display hash table
void displayHash(Hash h)
{
    for (int i = 0; i < h.slot; i++)
    {
        cout << "table[" << i << "]";
        for (auto x : h.table[i])
            cout << " --> " << x;
        cout << endl;
    }
}
// Tim kiem
bool search(Hash h, int key) {
    int index = hashFunction(h, key);
    list<int>::iterator i;
    for (i = h.table[index].begin(); i != h.table[index].end(); i++) {
        if (*i == key) {
            /*cout << "\nTim thay " << key << " trong bang bam";*/
            return true;
        }
    }
    if (i == h.table[index].end())
        return false;
        /*cout << "\nKhong tim thay "<<key<<" trong bang bam";*/
}

int main()
{
    int key[] = { 15, 11, 27, 8, 12 };
    int size = sizeof(key) / sizeof(key[0]);
    Hash h;
    // 7 is count of buckets in hash table
    create_Hash(h, 7);
    for (int i = 0; i < size; i++)
        insertItem(h, key[i]);
    cout << "Hash Table: " << endl;
    displayHash(h);

    int delKey;
    do {
        cout << "\nNhap vao key can xoa: ";
        cin >> delKey;
        if (!search(h, delKey)) {
            cout << "\nKey ban can xoa khong co trong bang bam";
            system("pause");
        }
    } while (!search(h, delKey));
    deleteItem(h, delKey);
    cout << "\nBang bam sau khi xoa "<<delKey<<": " << endl;
    displayHash(h);

    int searchKey;
    cout << "\nNhap vao key can tim kiem: ";
    cin >> searchKey;
    int find = search(h, searchKey);
    if (find == true) cout << "\nTim thay " << searchKey << " trong bang bam";
    else cout << "\nKhong tim thay " << searchKey << " trong bang bam";
    return 0;
}