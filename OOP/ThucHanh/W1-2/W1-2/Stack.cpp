// Bài 1: Class Stack
#include"Stack.h"

Stack::Stack(int _capacity) {
	ptr = new int[_capacity];
	capacity = _capacity;
	top = -1;
}

Stack::~Stack() {
	delete[] ptr;
}

// Trả về kích thước của Stack
int Stack::size() {
	return top + 1;
}

// Kiểm tra Stack rỗng
bool Stack::isEmpty() {
	return top == -1; // or return size() == 0
}

// Kiểm tra Stack đầy
bool Stack::isFull() {
	return top == capacity - 1; // or return size() == capacity
}

// Trả về top element của stack
int Stack::peek() {
	if (!isEmpty()) {
		return ptr[top];
	}
	else {
		exit(EXIT_FAILURE);
	}
}
void Stack::push(const int& element) {
	if (isFull()) {
		cout << "Stack overflow!" << endl;
		return;
	}
	cout << "Push " << element <<" to stack." << endl;
	ptr[++top] = element;
}

void Stack::input() {
	int n;
	cout << "Enter the number of elements to be inserted in the stack: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cout << "Enter element " << i + 1 << ": ";
		cin >> x;
		push(x); // Thêm phần tử vào stack
	}
}

int Stack::pop() {
	if (isEmpty()) {
		cout << "Stack is empty" << endl;
		return 0;	}
	cout << "Removing " << peek() << " from stack." << endl;
	return ptr[top--];
}

//void Stack::output() {
//	while (!isEmpty()) {
//		cout << peek() << " ";
//		pop();
//	}
//}

void Stack::output() {
	int i; //for loop
	cout << "STACK is: ";
	for (i = (top); i >= 0; i--)
		cout << ptr[i] << " ";
	cout << endl;
}