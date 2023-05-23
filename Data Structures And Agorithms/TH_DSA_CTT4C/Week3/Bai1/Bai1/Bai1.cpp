#include<iostream>
#include<algorithm>
/*
* Bài 1: Viết hàm sắp xếp mảng A, với k phần tử đầu tiên của mảng có thứ tự tăng dần và n-k
phần tử còn lại có thứ tự giảm dần.
{5, 4, 6, 2, 1, 3, 8, 9, -1},
Thuật toán
- Bước 1: Chia mảng ra làm 2 phần,
 + Phần thứ nhất chứa các phần tử từ vị trí 0 đến vị trí k-1
 + Phần thứ hai chứa các phần tử từ vị trí k đến vị trí n-1
- Bước 2:
 + Duyệt mảng thứ nhất: sắp xếp tăng dần từ a[0] đến a[k-1]
 + Duyệt mảng thứ hai: sắp xếp giảm dần từ a[k] đến a[n-1]
- Bước 3: Kết hợp 2 mảng đã sắp xếp lại
*/
using namespace std;
template<class Item>
// Sắp xếp tăng dần
void bubble_increase(Item a[], int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = r; j > i; j--) {
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
            }
        }
    }
}
// Sắp xếp giảm dần
template<class Item>
void bubble_decrease(Item a[], int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = r; j > i; j--) {
            if (a[j - 1] < a[j]) {
                swap(a[j - 1], a[j]);
            }
        }
    }
}
template<class Item>
void sort_ascending_decending(Item a[], int n, int k) {
    // Sắp xếp tăng dần từ vị trí 0 đến vị trí k-1
    bubble_increase(a, 0, k - 1);
    // Sắp xếp giảm dần từ vị trí k đến vị trí n-1
    bubble_decrease(a, k, n - 1);
}
template<class Item>
void Nhap(Item a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap a[" << i << "]: ";
        cin >> a[i];
    }
}
template<class Item>
void Xuat(Item a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << "  ";
    }
}
int main() {
    int a[100], n, k;
    cout << "\nNhap so luong phan tu cua mang: ";
    cin >> n;
    Nhap(a, n);
    cout << "\nMang truoc khi sap xep: ";
    Xuat(a, n);
    do {
        cout << "\nNhap vi tri k: ";
        cin >> k;
    } while (k < 0 || k > n - 1);

    cout << "\nMang sau khi sap xep: ";
    sort_ascending_decending(a, n, k);
    Xuat(a, n);
}
