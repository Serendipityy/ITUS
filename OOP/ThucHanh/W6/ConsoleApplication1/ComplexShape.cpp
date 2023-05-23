#include "ComplexShape.h"



/* area of ComplexShape */
double ComplexShape::area() {
    double total = 0;
    for (int i = 0; i < Children.size(); i++) {
        total += Children[i]->area();
    }
    return total;
}
bool ComplexShape::IsSelected(Point p) {
    for (int i = 0; i < Children.size(); i++) {
        if (Children[i]->IsSelected(p)) {
            return true;
        }
    }
    return false;
}
Shape* ComplexShape::Clone() {
    vector<Shape*> clonedChildren;
    for (int i = 0; i < Children.size(); i++) {
        clonedChildren.push_back(Children[i]->Clone());
    }
    return new ComplexShape(clonedChildren);
}
void ComplexShape::input() {
    int n;
    cout << "Nhap vao so luong hinh: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int shapeType;
        cout << "Nhap loai hinh (1 - hinh tron, 2 - hinh chu nhat): ";
        cin >> shapeType;

        if (shapeType == 1) {
            Circle* c = new Circle();
            c->input();
            Children.push_back(c);
        }
        else if (shapeType == 2) {
            Rectange* r = new Rectange();
            r->input();
            Children.push_back(r);
        }
    }
}
void ComplexShape::print() {
    for (int i = 0; i < Children.size(); i++) {
        Children[i]->print();
    }
}
int ComplexShape::circle_Num() {
    int count = 0;
    for (int i = 0; i < Children.size(); i++) {
        if (dynamic_cast<Circle*>(Children[i]) != NULL) {
            count++;
        }
    }
    return count;
}
int ComplexShape::rectange_Num() {
    int count = 0;
    for (int i = 0; i < Children.size(); i++) {
        if (dynamic_cast<Rectange*>(Children[i]) != NULL) {
            count++;
        }
    }
    return count;
}
