#pragma warning(disable : 4996)
#include <iostream>
#include <string.h>
using namespace std;
class A {
private:
	char* m_s;
public:
	A() { m_s = _strdup("default"); }
	A(const char* s) { m_s = _strdup(s); }
	virtual void prepare() { cout << "A "; }
	void display() {
		prepare();
		cout << m_s << endl;
	}

	// Thêm destructor
	~A() { free(m_s); }

	// Thêm copy constructor
	A(const A& other) { m_s = _strdup(other.m_s); }


	// Trang bị operator>> cho lớp A để nhập chuỗi từ bàn phím cho thuộc tính m_s.
	friend istream& operator>>(istream& input, A& a) {
		char buffer[100];
		input.getline(buffer, 100);
		a.m_s = _strdup(buffer);
		return input;
	}

};
class B : public A {
public:
	B(const char* s) : A(s) { }
	B(const B& b) {}
	void prepare() { cout << "B "; }
};
void foo(A* obj1, A obj2) {
	obj1->display();
	obj2.display();
}
void main() {
	B obj1("text");
	A* obj2 = new B(obj1);
	foo(&obj1, *obj2);
	delete obj2;

	A obj;
	cout << "Nhap chuoi: ";
	cin >> obj;
	obj.display();
}

