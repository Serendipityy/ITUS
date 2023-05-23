#include "Chap2.h"

// class implementation - Cài đặt thiệt sự
// Hàm tạo không có đối số - Max 1 
Point2D::Point2D() {
	_x = 0;
	_y = 0;
}



// Hàm tạo có đối số - Vô hạn
Point2D::Point2D(int a, int b) {
	_x = a;
	_y = b;
}
Point2D::Point2D(int i) {
	_x = i;
	_y = i;
}

string Point2D::toString() {
	stringstream out; // filestream / network stream
	// console output - stream
	// this: giữ con trỏ trước địa chỉ của đối tượng đang ở hàm này
	out << "(" << this->_x << ", " << this->_y << ")";
	string result = out.str(); // Chuyển đống nằm trên bộ nhớ thành chuỗi thật sự
	return result;
}

Point2D::~Point2D() {
	cout << "Destructor of" << this->toString() << endl;
}


float Point2D::distanceTo(Point2D other) {
	float result = 0;
	int dx = this->_x - other._x;
	int dy = this->_y - other._y;
	result = sqrt(dx * dx + dy * dy);
	return result;
};

Line2D::Line2D() {

}

Line2D::Line2D(Point2D a, Point2D b) {
	_start = a;
	_end = b;
}

string Line2D::toString() {
	stringstream writer;

	writer << "(" << _start.toString() << ", " << _end.toString() << ")";
	string result = writer.str();
	return result;
}

float Line2D::length() {
	float result = 0;

	// Tính khoảng cách từ điểm đầu đến điểm cuối
	result = _start.distanceTo(_end);

	return result;
}

// 1. Có thể có tối đa bao nhiêu hàm tạo không có đối số?
// => 1
// 2. Có thể có tối đa bao nhiêu hàm tạo có đối số?
// => Vô hạn