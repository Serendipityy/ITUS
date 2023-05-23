/*****************************************************
* Define Shape class, File giao dien cho lop Shape
*****************************************************/
#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <vector>
using namespace std;

// Dinh nghia diem Point
struct Point {
    double X, Y;
};

// Dinh nghia lop Shape
class Shape {
public:
    virtual double area() = 0;
    virtual Shape* Clone() = 0;
    virtual bool IsSelected(Point p) = 0;
    virtual void input() {}
    virtual void print() {}
    virtual ~Shape() {}
};
#endif