#include <iostream>
using namespace std;
//Dinh dang kieu phan so
struct Fraction {
    int tuso;
    int mauso;
};

//overload toan tu xuat cho phan so
ostream& operator<< (ostream& outFraction, const Fraction& a) {
    outFraction << a.tuso << '/' << a.mauso << ' ';
    return outFraction;
}

//overload toan tu xuat cho mang
template <typename T, int N>
ostream& operator<<(ostream& outDev, const T(&a)[N]) {
    int n = N - 1;
    for (int i = 0; i < n; i++)
        outDev << a[i] << (const char*)" ";
    outDev << a[n];
    return outDev;
}

//overload toan tu <
bool operator<(Fraction& x, Fraction& y) {
    return x.tuso * y.mauso < y.tuso* x.mauso;
}

//overload toan tu >
bool operator>(Fraction& x, Fraction& y) {
    return x.tuso * y.mauso > y.tuso * x.mauso;
}

template <class T>
bool increase(T left, T right)
{
    return left > right;
}

template <class T>
bool decrease(T left, T right)
{
    return left < right;
}

//Ham sap xep mang tang dan, giam dan
template <class T>
void sort(T a[], int n, bool (*comparisonFunc)(T, T)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (comparisonFunc(a[i], a[j])) {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void main()
{
    int a[] = { 4,3,6,8 };
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, n, increase);
    cout << a << endl;
    sort(a, n, decrease);
    cout << a << endl;
}
