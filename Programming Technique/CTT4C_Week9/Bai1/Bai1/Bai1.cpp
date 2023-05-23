#include<iostream>
#include<limits.h>
#include<malloc.h>
using namespace std;

// Định nghĩa cấu trúc stack sử dụng biến cấu trúc
struct Stack {
	int top;
	unsigned capacity;
	int* ptr;
};
// Hàm tạo stack
Stack* create(unsigned cap) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = cap;
	stack->top = -1;
	stack->ptr = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}
// Hàm kiểm tra stack đầy
bool isFull(Stack* stack) {
	return stack->top == stack->capacity - 1;
}
// Hàm kiểm tra stack rỗng
bool isEmpty(Stack* stack) {
	return stack->top == -1;
}
// Hàm thêm phần tử vào stack
void push(Stack* stack, int elem) {
	if (isFull(stack)) {
		return;
	}
	stack->ptr[++stack->top] = elem;
	cout << elem << " pushed into stack\n";
}
// Hàm trả về đỉnh stack
int peek(Stack* stack) {
	if (isEmpty(stack))
		return INT_MIN;
	return stack->ptr[stack->top];
}
// Hàm lấy phần tử ra khỏi stack
int pop(Stack* stack) {
	if (isEmpty(stack)) {
		return INT_MIN;
	}
	else {
		return stack->ptr[stack->top--];
	}
}
// Nhap nhap Input
void Input(Stack* stack) {
	printf("\nNhap phan tu cho stack: \nNhap 0 de ket thuc\n");
	int x;
	do {
		scanf_s("%d", &x);
		if (x != 0)
			push(stack, x);
	} while (x != 0);
}

// Ham xuat
void Output(Stack* stack) {
	printf("\n");
	while (stack->top != NULL)
		printf("  %d", pop(stack));
}
int main() {
	Stack* stack = create(100);
	Input(stack);
	Output(stack);
	cout << "\nTop item is " << peek(stack);
	return 0;
}