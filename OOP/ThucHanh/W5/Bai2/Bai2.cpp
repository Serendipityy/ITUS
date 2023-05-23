#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<sstream>
using namespace std;

// Lớp Sinh Viên
class Student {
private:
    string id;
    string name;
    string dob;
    string address;
    vector<string> courses; // Danh sách khóa học đăng ký

public:
    Student(string id, string name, string dob, string address) {
        this->id = id;
        this->name = name;
        this->dob = dob;
        this->address = address;
    }
    string getID() {
        return id;
    }
    string getName() {
        return name;
    }
    string getDob() {
        return dob;
    }
    string getAddress() {
        return address;
    }
    vector<string> getCourses() {
        return courses;
    }

    // Đăng ký khóa học
    void registerCourse(string course) {
        if (courses.size() < 5) {
            courses.push_back(course);
        }
        else {
            cout << "Sinh vien da dang ky toi da 5 khoa hoc!" << endl;
        }
    }

    // In thông tin sinh viên
    void printInfo() {
        cout << "Ma sinh vien: " << id << endl;
        cout << "Ten sinh vien: " << name << endl;
        cout << "Ngay sinh: " << dob << endl;
        cout << "Dia chi: " << address << endl;
        cout << "Danh sach khoa hoc da dang ky: " << endl;
        for (string course : courses) {
            cout << "- " << course << endl;
        }
    }
};

// Lớp Khóa học
class Course {
private:
    string id;
    string name;
    string schedule;
    vector<string> roster; // Danh sách sinh viên đăng ký

public:
    Course(string id, string name, string schedule) {
        this->id = id;
        this->name = name;
        this->schedule = schedule;
    }
    string getID() {
        return id;
    }
    string getName() {
        return name;
    }
    string getSchedule() {
        return schedule;
    }
    vector<string> getRoster() {
        return roster;
    }

    // Đăng ký sinh viên
    void registerStudent(string student) {
        if (roster.size() < 40) {
            roster.push_back(student);
        }
        else {
            cout << "Khoa hoc da day!" << endl;
        }
    }

    // In danh sách sinh viên đăng ký
    void printRoster() {
        cout << "Danh sach sinh vien dang ky khoa hoc " << name << ":" << endl;
        for (string student : roster) {
            cout << "- " << student << endl;
        }
    }


    void printCourse() {
        cout << "Ma khoa hoc: " << id << endl;
        cout << "Ten khoa hoc: " << name << endl;
        cout << "Thoi khoa bieu: " << schedule << endl;
    }
};

// Lớp Đăng ký
class Registrar {
private:
    vector<Student> students;
    vector<Course> courses;

public:
    // Thêm sinh viên
    void addStudent(Student student) {
        students.push_back(student);
    }

    // Thêm khóa học
    void addCourse(Course course) {
        courses.push_back(course);
    }

    // Tìm sinh viên theo mã sinh viên
    Student* findStudent(string id) {
        for (auto& student : students) {
            if (student.getID() == id) {
                return &student;
            }
        }
        return nullptr;
    }

    // Tìm khóa học theo mã khóa học
    Course* findCourse(string id) {
        for (auto& course : courses) {
            if (course.getID() == id) {
                return &course;
            }
        }
        return nullptr;
    }
    // Đăng ký sinh viên vào khóa học
    void enroll(string studentId, string courseId) {
        Student* student = findStudent(studentId);
        if (student == nullptr) {
            cout << "Khong tim thay sinh vien co ma so " << studentId << endl;
            return;
        }

        Course* course = findCourse(courseId);
        if (course == nullptr) {
            cout << "Khong tim thay khoa hoc co ma so " << courseId << endl;
            return;
        }

        student->registerCourse(course->getName());
        course->registerStudent(student->getName());
        cout << "Dang ky thanh cong!" << endl;
    }

    // In thông tin sinh viên
    void printStudentInfo(string id) {
        Student* student = findStudent(id);
        if (student == nullptr) {
            cout << "Khong tim thay sinh vien co ma so " << id << endl;
            return;
        }

        student->printInfo();
    }

    // In danh sách sinh viên đăng ký khóa học
    void printCourseRoster(string id) {
        Course* course = findCourse(id);
        if (course == nullptr) {
            cout << "Khong tim thay khoa hoc co ma so " << id << endl;
            return;
        }

        course->printRoster();
    }


    void readCourses(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Khong mo duoc file " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, schedule;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, schedule, ',');
            Course course(id, name, schedule);
            addCourse(course);
        }

        file.close();
    }


    void writeStudents(string filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Khong mo duoc file " << filename << endl;
            return;
        }

        for (auto& student : students) {
            //file << student.getID() << " " << student.getName() << " " << student.getDob() << " " << student.getAddress() << endl;
            file << "Ma sinh vien: " << student.getID() << endl;
            file << "Ten sinh vien: " << student.getName() << endl;
            file << "Ngay sinh: " << student.getDob() << endl;
            file << "Dia chi: " << student.getAddress() << endl;
            file << endl;
        }

        file.close();
    }
    void readStudents(string filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Khong mo duoc file " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, name, dob, address;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, dob, ',');
            getline(ss, address, ',');
            Student student(id, name, dob, address);
            addStudent(student);
        }

        file.close();
    }

    void printStudents() {
        for (auto& student : students) {
            student.printInfo();
            cout << endl;
        }
    }
    void printCourses() {
        for (auto& course : courses) {
            course.printCourse();
            cout << endl;
        }
    }

    void printStudentSchedule(string id) {
        Student* student = findStudent(id);
        if (student == nullptr) {
            cout << "Khong tim thay sinh vien co ma so " << id << endl;
            return;
        }
        cout << "Thoi khoa bieu cua sinh vien " << student->getName() << ":" << endl;
        for (string course : student->getCourses()) {
            Course* currentCourse = findCourse(course);
            if (currentCourse != nullptr) {
                currentCourse->printCourse();
                //cout << "- " << currentCourse->getName() << ": " << currentCourse->getSchedule() << endl;
            }
        }
    }

};
int main() {
    Registrar registrar;

    int ch;
    bool quit = false;
    do {
        system("cls");
        cout << "-------QUAN LY HE THONG DANG KY PHONG BAN-------" << endl;
        cout << "1. Doc danh sach khoa hoc" << endl;
        cout << "2. Xuat danh sach khoa hoc" << endl;
        cout << "3. Doc danh sach sinh vien" << endl;
        cout << "4. Xuat danh sach sinh vien" << endl;
        cout << "5. Ghi danh sach sinh vien len file" << endl;
        cout << "6. Sinh vien dang ky khoa hoc" << endl;
        cout << "7. Danh sach sinh vien cua mot khoa hoc" << endl;
        cout << "8. Thoi khoa bieu cua sinh vien" << endl;
        cout << "------------------------------------------------" << endl;

        cout << "\nNhap lua chon cua ban: ";
        cin >> ch;
        switch (ch) {
        case 1:
        {
            registrar.readCourses("readCourses.txt");
            system("pause");
        }
        break;
        case 2:
        {
            registrar.printCourses();
            system("pause");
        }
        break;
        case 3:
        {
            registrar.readStudents("readStudents.txt");
            system("pause");
        }
        break;
        case 4:
        {
            registrar.printStudents();
            system("pause");
        }
        break;
        case 5:
        {
            registrar.writeStudents("writeStudents.txt");
            system("pause");
        }
        break;
        case 6:
        {
            string studentID, courseID;
            cout << "Nhap ma sinh vien va ma khoa hoc can dang ky: ";
            cin >> studentID >> courseID;
            registrar.enroll(studentID, courseID);
            system("pause");
        }
        break;
        case 7:
        {
            string courseID;
            cout << "Nhap ID khoa hoc: ";
            cin >> courseID;
            registrar.printCourseRoster(courseID);
            system("pause");
        }
        break;
        case 8:
        {
            string studentID;
            cout << "Nhap ID sinh vien: ";
            cin >> studentID;
            registrar.printStudentSchedule(studentID);
            system("pause");
        }
        break;
        }
    } while (!quit);

    return 0;
}
