#ifndef Student_h
#define Student_h

#include <iostream>
#include <string>
using namespace std;

class School {
private:
    string name;
    int numHolidays;
public:
    School() {
        name = "";
        numHolidays = 5;
    }
    School(string _name) {
        name = _name;
        numHolidays = 5;
    }
    void setNumHolidays(int x) {
        cout << "school1.setNumHolidays => " << x << endl;
        numHolidays = x;
    }
    void getHolidays() {
        cout << "Nghi le " << numHolidays << " ngay" << endl;
    }

    // Bổ sung:
    // Copy constructor
    School(const School& s) {
        name = s.name;
        numHolidays = s.numHolidays;
    }

    // Assignment operator
    School& operator=(const School& s) {
        if (this == &s) {
            return *this;
        }
        name = s.name;
        numHolidays = s.numHolidays;

        return*this;
    }
    // Destructor
    ~School() {
    }

};

class Student {
private:
    int id;
    string name;
    School* sch;
public:
    // Bổ sung default constructor, destructor
    Student() {
        id = 0;
        name = "";
        sch = NULL;
    }

    ~Student() {
        sch = NULL;
    }
    //------------

    Student(int _id, string _name, School& _sch) {
        id = _id;
        name = _name;
        sch = &_sch;
    }

    // Bổ sung copy constructor, assignment operator
    Student(const Student& s) {
        id = s.id;
        name = s.name;
        sch = s.sch;

    }

    Student& operator=(const Student& s) {
        if (this == &s) {
            return *this;
        }
        id = s.id;
        name = s.name;
        sch = s.sch;
        return*this;
    }

    //-----------------------

    void print() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        // Sửa lại: sch. thành sch -> 
        sch->getHolidays();
    }

};

#endif /* Student_h */
