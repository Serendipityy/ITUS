
/*********************************************************
* Define Rectange class, File giao dien cho lop Rectange
*********************************************************/
#ifndef RECTANGE_H
#define RECTANGE_H

#include "shape.h"

// Dinh nghia lop Rectange
class Rectange : public Shape {
protected:
    Point X; // Toa do goc trai tren
    double W, H; // Chieu rong va chieu cao

public:
    // Constructors
    Rectange() : X({ 0,0 }), W(0), H(0) {}
    Rectange(Point x, double w, double h) : X(x), W(w), H(h) {}
    /* area of rectange */
    double area() { return W * H; }
    bool IsSelected(Point p);
    Shape* Clone();
    void input();
    void print();
};
#endif