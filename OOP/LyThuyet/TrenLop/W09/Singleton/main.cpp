#include "Singleton.h"

int main() {
    Singleton* s1 = Singleton::getInstance(); // Tao instance co ID 0
    s1->printId(); // ID: 0

    Singleton* s2 = Singleton::getInstance();
    s2->printId(); // ID: 1

    Singleton* s3 = Singleton::getInstance();
    s3->printId(); // ID: 2

    Singleton* s4 = Singleton::getInstance();
    s4->printId(); // ID: 3

    Singleton* s5 = Singleton::getInstance();
    s5->printId(); // ID: 4

    Singleton* s6 = Singleton::getInstance(); // Khong the tao nhieu hon 5 instance
    std::cout << "s6 is nullptr: " << (s6 == nullptr) << endl; // s6 is nullptr: 1

    return 0;
}

