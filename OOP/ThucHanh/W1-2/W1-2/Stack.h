#pragma once
#include<iostream>
#include<cassert>
using namespace std;

#define SIZE 10

class Stack {
private:
	int* ptr;
	int capacity;
	int top;
public:
	// Default constructor
	// Constructor
	Stack(int _capacity = SIZE);
	// Destructor
	~Stack();
	// Thêm phần tử vào stack, thêm vào cuối
	void push(const int& element);
	// Lấy phần tử khỏi stack, lấy ra ở cuối theo LIFO
	int pop();

	//----------------------
	int peek();
	int size();
	bool isFull();
	bool isEmpty();
	void input();
	void output();

};

void menu();