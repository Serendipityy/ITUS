#include "ComplexShape.h"

int main() {
    ComplexShape myComplexShape;
    myComplexShape.input();
    // In danh sach hinh vua nhap
    myComplexShape.print();

    // So luong hinh tron va hinh chu nhat
    cout << "So luong hinh tron: " << myComplexShape.circle_Num() << endl;
    cout << "So luong hinh chu nhat: " << myComplexShape.rectange_Num() << endl;
    cout << "Tong dien tich cac hinh trong danh sach: " << myComplexShape.area();
    return 0;
}
