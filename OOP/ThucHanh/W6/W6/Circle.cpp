#include "Circle.h"
/*----- Implement methods: IsSelected(), Clone() -----*/
// method IsSelected
bool Circle::IsSelected(Point p) {
    // pC <= R : Diem p nam tren hinh tron => IsSelected() = true
    return ((p.X - C.X) * (p.X - C.X) + (p.Y - C.Y) * (p.Y - C.Y)) <= R * R;
}

// Deep copy
Shape* Circle::Clone() {
    return new Circle(C, R);
}

// Method input
void Circle::input() {
    cout << "Nhap thong tin hinh tron:" << endl;
    cout << "Nhap toa do tam: "; cin >> C.X >> C.Y;
    cout << "Nhap ban kinh: "; cin >> R;
}

// Method print
void Circle::print() {
    cout << "\nHinh tron tam (" << C.X << ", " << C.Y << "), ban kinh " << R << endl;
}