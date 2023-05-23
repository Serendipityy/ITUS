#include "Rectange.h"

/*----- Implement methods: IsSelected(), Clone() -----*/
// method IsSelected
bool Rectange::IsSelected(Point p) {
    return (p.X >= X.X && p.X <= X.X + W && p.Y >= X.Y && p.Y <= X.Y + H);
}

// Deep copy
Shape* Rectange::Clone() {
    Rectange* p = new Rectange;
    if (p == NULL) return NULL;
    p->X = X;
    p->W = W;
    p->H = H;
    return p;
}

void Rectange::input() {
    cout << "Nhap dinh ben trai phia tren (top-left) cua hinh chu nhat (x, y): ";
    cin >> X.X >> X.Y;
    cout << "Nhap chieu rong: ";
    cin >> W;
    cout << "Nhap chieu cao: ";
    cin >> H;
}

void Rectange::print() {
    cout << "\nHinh chu nhat:" << endl;
    cout << "\tTop-left point: (" << X.X << ", " << X.Y << ")" << endl;
    cout << "\tChieu rong: " << W << endl;
    cout << "\tChieu cao: " << H << endl;
}