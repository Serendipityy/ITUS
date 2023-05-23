#include "Chap3.h"

// Class implementation
Point::Point() {
	_x = 0;
	_y = 0;
}

Point::Point(int a, int b) {
	_x = a;
	_y = b;

	cout << "Point constructor called " << this->toString() << endl;
}

Point::Point(int i) {
	_x = i;
	_y = i;
}

Point::~Point() {
	// Do nothing
	cout << "Destructor of " << this->toString() << endl;
}

float Point::calcDistanceTo(Point other) {
	int dx = this->_x - other._x;
	int dy = this->_y - other._y;
	float result = sqrt(dx * dx + dy * dy);
	return result;
}

string Point::toString() {
	stringstream builder;
	builder << "(" << _x << ", " << _y << ")";
	//string result = builder.str();
	//return result;
	return builder.str();
}



// ------------ LINE ----------------
Line::Line() {
	// Hàm tạo ban đầu, không cần làm gì hết
}
Line::Line(Point a, Point b) {
	cout << "Inside line constructor" << endl;
	_start = a;
	_end = b;
	cout << "Finish line constructor" << endl;


	//cout << "Line "<<this->toString() << "is created" << endl;
}

Line::Line(int a, int b, int x, int y) {
	Point temp1(a, b);
	_start = temp1;

	Point temp2(x, y);
	_end = temp2;
}
Line::~Line() {
	//cout << "Destroyed line " << this->toString() << endl;
}
float Line::length() {
	return _start.calcDistanceTo(_end);
}

string Line::toString() {
	stringstream builder;
	builder << "(" << _start.toString()
		<< ", " << _end.toString()
		<< ")";
	string result = builder.str();
	return result;
}


void Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// const: chỉ những hàm được đánh dấu là const mới
// được phép gọi trong này
void read(const Point* a) {
	cout << a->x() << endl;
	// a->y();
}