#include "Student.h"

Student::Student() {
    gpa = 0.0;
}

Student::Student(long id, double gp) : Person(id) {
    assert(gpa >= 0.0 && gpa <= 10.0);
    gpa = gp;
}

Student::~Student() {
}

Student::Student(const Student& student) : Person(student) {
    gpa = student.gpa;
}

double Student::getGpa() const {
    return gpa;
}

void Student::setGpa(double gp) {
    assert(gpa >= 0.0 && gpa <= 10.0);
    gpa = gp;
}

void Student::input() {
    Person::input(); // gọi lại phương thức input của lớp cha Person để nhập identity
    cout << "Enter GPA: ";
    cin >> gpa;
    assert(gpa >= 0.0 && gpa <= 10.0);
}

void Student::output() {
    Person::output(); // gọi lại phương thức output của lớp cha Person để xuất identity
    cout << "GPA: " << gpa << endl;
}
