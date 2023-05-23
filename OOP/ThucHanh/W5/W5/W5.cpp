//#include <iostream>
//#include <string>
//using namespace std;
//
//template<typename T>
//class vector {
//private:
//    T* ptr;
//    int capacity;
//    int sz;
//
//public:
//    // Constructors
//    vector() : ptr(nullptr), capacity(0), sz(0) {}
//    vector(int cap) : ptr(new T[cap]), capacity(cap), sz(0) {}
//    ~vector() { delete[] ptr; }
//
//    // Utilities methods
//
//    /* operator[] */
//    T& operator[](int n) { return ptr[n]; }
//
//    /* Expand extra memory */
//    void reserve(int newalloc) {
//        if (newalloc <= capacity) {
//            return;
//        }
//
//        T* new_ptr = new T[newalloc];
//        for (int i = 0; i < sz; i++) {
//            new_ptr[i] = ptr[i];
//        }
//
//        delete[] ptr;
//        ptr = new_ptr;
//        capacity = newalloc;
//    }
//
//    void push(const T& element) {
//        if (sz == capacity) {
//            reserve(capacity == 0 ? 1 : capacity * 2);
//        }
//        ptr[sz++] = element;
//    }
//
//    void print() {
//        cout << "[";
//        for (int i = 0; i < sz; i++) {
//            if (i != 0) {
//                cout << ", ";
//            }
//            cout << ptr[i];
//        }
//        cout << "]" << endl;
//    }
//};
//
//int main() {
//    vector<int> v(3);
//    v.push(1);
//    v.push(2);
//    v.push(3);
//    v.push(4);
//    v.push(5);
//
//    cout << "Vector: ";
//    v.print();
//
//    cout << "Element at index 3: " << v[3] << endl;
//
//    return 0;
//}


#include <iostream>
#include <string>
using namespace std;

template<typename T>
class vector {
private:
    T* ptr;
    int capacity;
    int sz;
public:
    // Constructors
    vector() : ptr(nullptr), capacity(0), sz(0) {}
    vector(int cap) : ptr(new T[cap]), capacity(cap), sz(0) {}
    ~vector() {
        delete[] ptr;
    }

    // utilities methods

    /* operator[] */
    T& operator[](int n) {
        return ptr[n];
    }

    /* Expand extra memory */
    void reserve(int newalloc) {
        if (newalloc <= capacity) return;
        T* newptr = new T[newalloc];
        for (int i = 0; i < sz; ++i) {
            newptr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newptr;
        capacity = newalloc;
    }

    // input, output
    void push(const T& element) {
        if (sz >= capacity) {
            reserve(max(1, capacity * 2));
        }
        ptr[sz++] = element;
    }

    void print() {
        for (int i = 0; i < sz; ++i) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }

    void input() {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        for (int i = 0; i < n; ++i) {
            T x;
            cout << "Enter element " << i << ": ";
            cin >> x;
            push(x);
        }
    }
};

int main() {
    vector<int> v(10);
    v.input();
    cout << "Vector: ";
    v.print();
    cout << v[3];
    return 0;
}

