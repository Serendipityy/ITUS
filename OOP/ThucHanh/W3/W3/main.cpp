#include "MyIntArray.h"
int main() {
    MyIntArray m1;
    m1.input();
    m1.print();


    cout << "Copy constructor" << endl;
    MyIntArray m3(m1);
    m3.print();


    cout << "Assignment operator" << endl;
    MyIntArray m4;
    m4 = m1;
    m4.print();

    return 0;
}

