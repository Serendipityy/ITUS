#include <iostream>
#include <list>
using namespace std;
struct Hash {
    int slot; // No.
    list<int>* table;  // Pointer to an array containing buckets
};
//int checkPrime(int n)
//{
//    int i;
//    if (n == 1 || n == 0)
//    {
//        return 0;
//    }
//    for (i = 2; i < n / 2; i++)
//    {
//        if (n % i == 0)
//        {
//            return 0;
//        }
//    }
//    return 1;
//}
//int getPrime(int n)
//{
//    if (n % 2 == 0)
//    {
//        n++;
//    }
//    while (!checkPrime(n))
//    {
//        n += 2;
//    }
//    return n;
//}


/* Ham Khoi Tao Hash Table */
void create_Hash(Hash& h, int b)
{
    //int size = getPrime(b);
    //h.slot = size;
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

    // delete 12 from hash table
    deleteItem(h, 12);
    cout << "\nAfter deleting 12: " << endl;
    displayHash(h);

    return 0;
}