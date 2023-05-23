#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
using namespace std;

// Forward declaration
class Point;
class Line;

// Class declaration (Khai báo lớp)
class Point {
private:
	int _x;
	int _y;
public: 
	int x() const { 
		return _x; 
	}
	int y() { return _y; }
	void setX(int value) { _x = value; }
	void setY(int value) { _y = value; }
public:
	// Hàm tạo
	Point();
	Point(int, int);
	Point(int);
	// Hàm hủy
	~Point();
public:
	float calcDistanceTo(Point);
	string toString();
};

class Line {
private: // Attributes
	// Một đường thẳng được tạo bởi 2 điểm
	Point _start;
	Point _end;
public: // Properties
	Point start() { return _start; }
	void setStart(Point value) { _start = value; }
	
	Point end() { return _end; }
	void setEnd(Point value) { _end = value; }

	float length();

public:
	Line();
	Line(Point, Point);
	Line(int, int, int, int);
	~Line();
public:
	// Chuyển về chuỗi và hiển thị ra bên ngoài
	string toString();

};
void Swap(int&, int&);

void read(const Point*);