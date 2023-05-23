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

    vector(int cap) : capacity(cap), sz(0) {
        ptr = new T[capacity];
    }

    // Destructor
    ~vector() {
        delete[] ptr;
    }

    // Operator overloading
    T& operator[](int n) {
        return ptr[n];
    }

    // Utility methods
    void reserve(int newalloc) {
        if (newalloc <= capacity) {
            return;
        }
        T* newPtr = new T[newalloc];
        for (int i = 0; i < sz; i++) {
            newPtr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newPtr;
        capacity = newalloc;
    }

    // Input, output
    void push(const T& element) {
        if (sz == capacity) {
            reserve(capacity + 1);
        }
        ptr[sz++] = element;
    }

    void print() {
        for (int i = 0; i < sz; i++) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    vector<int> intVector(5);
    intVector.push(1);
    intVector.push(2);
    intVector.push(3);
    intVector.print();

    vector<string> strVector;
    strVector.push("Hello");
    strVector.push("World");
    strVector.print();

    return 0;
}
