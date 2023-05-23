#include "Student.h"

int main() {
    School school1("VNU-HCMUS");

    Student st1(21127001, "Nguyen Van A", school1);
    cout << "st1" << endl;
    st1.print();

    Student st2(21127002, "Tran Anh Tai", school1);
    cout << "st2" << endl;
    st2.print();


    school1.setNumHolidays(7);

    cout << "st1" << endl;
    st1.print();
    cout << "st2" << endl;
    st2.print();

    School school2("VNU-HCMUT");
    Student st3(21217001, "Doan Chanh Thuan", school2);
    cout << "st3" << endl;
    st3.print();

    cout << "st1" << endl;
    st1.print();
    cout << "st2" << endl;
    st2.print();

    return 0;
}
