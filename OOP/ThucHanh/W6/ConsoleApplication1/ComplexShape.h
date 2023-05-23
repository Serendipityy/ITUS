/***********************************************************
* Define ComplexShape, File giao dien cho lop ComplexShape
***********************************************************/
#ifndef COMPLEXSHAPE_H
#define COMPLEXSHAPE_H

#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectange.h"

using namespace std;

// Dinh nghia lop ComplexShape
class ComplexShape : public Shape {
protected:
    vector<Shape*> Children; // Các hình vẽ thành phần: Circle, rectangle, ...
public:
    // Constructors
    ComplexShape() {}
    ComplexShape(vector<Shape*> children) {
        this->Children = children;
    }
    /* area of ComplexShape */
    double area();
    bool IsSelected(Point p);
    Shape* Clone();

    void input();
    void print();
    int circle_Num();
    int rectange_Num();
};

#endif
