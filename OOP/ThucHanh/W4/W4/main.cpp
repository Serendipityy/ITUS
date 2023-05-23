#include "Student.h"
#include "Person.h"
int main() {
    Person p1;
    cout << "Input person: " << endl;
    p1.input();
    Person p2(p1);
    Person p3 = p2;
    cout << "Person: " << endl;
    p1.output();
    p2.output();
    p3.output();

    Student s1;
    cout << "Input student: " << endl;
    s1.input();
    Student s2(s1);
    Student s3 = s2;
    cout << "Student: " << endl;
    s1.output();
    s2.output();
    s3.output();
    s3.setGpa(8.0);
    s1.output();
    s2.output();
    s3.output();

    return 0;
}