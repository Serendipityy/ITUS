#include "stack.h"

void Stack::push(const string& val) {
	list.insert(0, val);
}

void Stack::pop() {
	list.erase(0);
}

string Stack::top() const {
	return list.get(0);
}

int Stack::size() const {
	return list.size();
}

void Stack::input() {
	string data;
	cout << "\nNhap du lieu vao stack (nhap 'q' de thoat): ";
	cin >> data;
	while (data != "q") {
		push(data);
		cout << "\nNhap du lieu vao stack (nhap 'q' de thoat): ";
		cin >> data;
	}

}

void Stack::output() const {
	cout << "\nCac du lieu trong stack: ";
	int n = size();
	for (int i = n - 1; i >= 0; i--) {
		cout << list.get(i) << " ";
	}
	cout << endl;

}