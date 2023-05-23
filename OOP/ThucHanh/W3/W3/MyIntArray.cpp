#include "MyIntArray.h"


MyIntArray::MyIntArray() {
    pArr = NULL;
    size = 0;
}

MyIntArray::MyIntArray(int sz) {
    size = sz;
    if (sz <= 0) {
        pArr = NULL;
    }
    else {
        pArr = new int[sz];
    }
}

MyIntArray::~MyIntArray() {
    delete[] pArr;
}

int& MyIntArray::operator[](int index) {
    return pArr[index];
}

MyIntArray::MyIntArray(const MyIntArray& src) {
    if (src.pArr == NULL) {
        pArr = NULL;
        size = 0;
    }
    else {
        size = src.size;
        pArr = new int[src.size];
        for (int i = 0; i < src.size; ++i) {
            pArr[i] = src.pArr[i];
        }
    }
}

MyIntArray& MyIntArray::operator=(const MyIntArray& src) {
    if (this == &src) {
        return *this;
    }
    if (src.pArr != NULL) {
        delete[] pArr;
        size = src.size;
        pArr = new int[src.size];
        for (int i = 0; i < size; i++)
            pArr[i] = src.pArr[i];
    }
    return *this;
}

void MyIntArray::input() {
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> size;

    pArr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Nhap pArr[" << i << "]: ";
        cin >> pArr[i];
    }
}


void MyIntArray::print() {
    if (size == 0) {
        cout << "Mang rong" << endl;
    }
    else {
        for (int i = 0; i < size; i++) {
            cout << pArr[i] << " ";
        }
        cout << endl;
    }
}


