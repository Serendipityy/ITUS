#include <iostream>
#include <vector>
using namespace std;
// Cau truc Diem
struct Point {
	double X;
	double Y;
};
class Shape {
public:
    Shape() {}
    virtual ~Shape() {}
    virtual Shape* Clone() = 0;
    virtual bool IsSelected(Point p) = 0;
    virtual void input();
    virtual void print();
};


class Circle : public Shape {
protected:
    Point C;
    double R;
public:
    Circle() {}
    Circle(const Circle& other) {
        C = other.C;
        R = other.R;
    }
    ~Circle() {}
    bool IsSelected(Point);
    Shape* Clone();
    void input();
    void print();
};

class Rectangle : public Shape {
protected:
    Point X;
    double W, H;
public:
    Rectangle() {}
    Rectangle(const Rectangle& other) {
        X = other.X;
        W = other.W;
        H = other.H;
    }
    ~Rectangle() {}
    bool IsSelected(Point);
    Shape* Clone();
    void input();
    void print();
};

class ComplexShape : public Shape {
protected:
    int sz;
    Shape** Children;
public:
    ComplexShape() {
        sz = 0;
        Children = NULL;
    }
    ComplexShape(const ComplexShape& other) {
        sz = other.sz;
        Children = new Shape * [sz];
        for (int i = 0; i < sz; i++) {
            Children[i] = other.Children[i]->Clone();
        }
    }
    ~ComplexShape() {
        if (Children != NULL) {
            for (int i = 0; i < sz; i++) {
                delete Children[i];
            }
            delete[] Children;
            Children = NULL;
        }
    }
    bool IsSelected(Point);
    Shape* Clone();
    void input();
    void print();
    int circle_Num();
};

bool Circle::IsSelected(Point p) {
    double d = sqrt((C.X - p.X) * (C.X - p.X) + (C.Y - p.Y) * (C.Y - p.Y));
    return (d <= R);
}

Shape* Circle::Clone() {
    return new Circle(*this);
}

bool Rectangle::IsSelected(Point p) {
    if (p.X < X.X || p.X > X.X + W || p.Y < X.Y || p.Y > X.Y + H) {
        return false;
    }
    return true;
}

Shape* Rectangle::Clone() {
    return new Rectangle(*this);
}

bool ComplexShape::IsSelected(Point p) {
    for (int i = 0; i < sz; i++) {
        if (Children[i]->IsSelected(p)) {
            return true;
        }
    }
    return false;
}

Shape* ComplexShape::Clone() {
    return new ComplexShape(*this);
}

void ComplexShape::input() {
    cout << "Enter the number of shapes: ";
    cin >> sz;
    Children = new Shape * [sz];
    for (int i = 0; i < sz; i++) {
        cout << "Enter shape " << i + 1 << ":" << endl;
        cout << "  1. Circle" << endl;
        cout << "  2. Rectangle" << endl;
        int type;
        cin >> type;
        if (type ==1) { // Circle
            Children[i] = new Circle;
        }
        else if (type == 2) { // Rectangle
            Children[i] = new Rectangle;
        }
        else {
            cout << "Invalid input. Please enter 1 or 2." << endl;
            i--;
            continue;
        }
        Children[i]->input();
    }
}
void ComplexShape::print() {
    cout << "ComplexShape with " << sz << " shapes:" << endl;
    for (int i = 0; i < sz; i++) {
        cout << "Shape " << i + 1 << ":" << endl;
        Children[i]->print();
    }
}


void ComplexShape::countShapes() {
    int circleCount = 0;
    int rectangleCount = 0;
    for (int i = 0; i < sz; i++) {
        Circle* c = dynamic_cast<Circle*>(Children[i]);
        if (c != nullptr) {
            circleCount++;
        }
        else {
            Rectangle* r = dynamic_cast<Rectangle*>(Children[i]);
            if (r != nullptr) {
                rectangleCount++;
            }
        }
    }
    cout << "Number of circles: " << circleCount << endl;
    cout << "Number of rectangles: " << rectangleCount << endl;
}
