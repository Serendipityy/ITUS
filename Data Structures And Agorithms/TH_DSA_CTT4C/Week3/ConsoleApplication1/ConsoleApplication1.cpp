#include<iostream>
using namespace std;
template<class Item>
void Xuat(Item a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
}
template<class Item>
void selection(Item a[], int l, int r) {

	for (int i = l; i < r; i++) {
		int min = i;
		for (int j = i + 1; j <= r; j++) {
			if (a[j] < a[min])
				min = j;
		}
		swap(a[i], a[min]);
	}
}
template<class Item>
void bubble(Item a[], int l, int r) {
	for (int i = l; i < r; i++) {
		for (int j = r; j > i; j--) {
			if (a[j - 1] > a[j])
				swap(a[j - 1], a[j]);
		}
	}
}
template<class Item>
void insertion(Item a[], int l, int r) {
	Item v;
	for (int i = l+1; i < r; i++) {
		v = a[i];
		int j;
		for (j = i; j > l && v < a[j - 1]; j--) {
			a[j] = a[j - 1];
		}
		a[j] = v;
	}
}
int main() {
	int a[] = { 5,2,0,1,3,1,4 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << "\Selection: ";
	selection(a, 0, n - 1);
	Xuat(a, n);

	cout << "\nBubble:    ";
	bubble(a, 0, n - 1);
	Xuat(a, n);
	cout << "\nInsertion: ";
	insertion(a, 0, n - 1);
	Xuat(a, n);
	return 0;
}