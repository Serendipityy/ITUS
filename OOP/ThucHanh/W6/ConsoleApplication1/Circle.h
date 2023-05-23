/*****************************************************
* Define Circle class, File giao dien cho lop Circle
*****************************************************/
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

// Dinh nghia lop Circle
class Circle : public Shape {
protected:
    Point C; // toa do tam
    double R; // do dai ban kinh
public:
    // Constructors
    Circle() : C({ 0,0 }), R(0) {}
    Circle(Point c, double r) : C(c), R(r) {}
    /* override area() method */
    double area() { return R * R * 3.14; }
    bool IsSelected(Point p);
    Shape* Clone();
    void input();
    void print();
};

#endif