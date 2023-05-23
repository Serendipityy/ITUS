#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;

// Class forward declaration (tham chiếu vòng)
class Point2D;
class Line2D;

// Class declaration 
class Point2D {
private: 
	int _x;
	int _y;
public:
	int X() {
		return _x;
	}
	int Y() {
		return _y;
	}
	void setX(int value) {
		_x = value;
	}
	void setY(int value) {
		_y = value;
	}
public: // Constructor - Khai báo
	Point2D();
	Point2D(int);
	Point2D(int, int);
	~Point2D();
public:
	string toString();
	float distanceTo(Point2D);
};

class Line2D {
private:
	Point2D _start;
	Point2D _end;
public:
	Point2D start() {
		return _start;
	}
	Point2D end() {
		return _end;
	}
	void setStart(Point2D value) {
		_start = value;
	}
	void setEnd(Point2D value) {
		_end = value;
	}
public: 
	Line2D();
	Line2D(Point2D, Point2D);
	string toString();
	float length(); // Độ dài của đường thẳng
};

