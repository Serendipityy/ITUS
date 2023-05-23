#include "Singleton.h"


Singleton* Singleton::getInstance() {
    if (count < 5) {
        if (instances[count] == nullptr) {
            instances[count] = new Singleton();
        }
        count++;
        return instances[count - 1];
    }
    else {
        cout << "Khong the tao nhieu hon 5 instances!" << endl;
        return nullptr;
    }
}

void Singleton::printId() {
    cout << "ID: " << id << endl;
}



Singleton::Singleton() {
    id = count;
    cout << "Tao instance voi ID " << id << endl;
}


Singleton* Singleton::instances[5] = { nullptr };
int Singleton::count = 0;
