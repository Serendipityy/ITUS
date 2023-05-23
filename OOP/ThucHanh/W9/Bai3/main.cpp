#include <iostream>
#include "AgeInput.h"

int main() {
    AgeInput ageInput(0, 99);
    try {
        int age = ageInput.getAge("Enter age: ");
        std::cout << "Input Okay. Age = " << age << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
