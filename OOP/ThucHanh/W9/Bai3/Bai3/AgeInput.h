#ifndef AGEINPUT_CPP
#define AGEINPUT_CPP

#include <iostream>
#include <exception>
#include <string>
#include "myexception.h"

using namespace std;

class AgeInput : public myException {
private:
    string DEFAULT_MESSAGE = "Your age: ";
    int DEFAULT_LOWER_BOUND = 0;
    int DEFAULT_UPPER_BOUND = 99;
    int lowerBound;
    int upperBound;
public:
    // Constructors
    AgeInput() : lowerBound(DEFAULT_LOWER_BOUND), upperBound(DEFAULT_UPPER_BOUND) {}
    AgeInput(int low, int high) : lowerBound(low), upperBound(high) {}

    // Method: enter age and check input data against bounds
    int getAge(string prompt) {
        if (prompt.empty()) {
            prompt = DEFAULT_MESSAGE;
        }
        int age;
        bool valid = false;
        while (!valid) {
            try {
                cout << prompt;
                cin >> age;
                if (cin.fail()) {
                    throw myException("Invalid input. Please enter a number.");
                }
                if (age < lowerBound || age > upperBound) {
                    throw myException("Input out of bound!");
                }
                valid = true;
            }
            catch (myException& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        //cout << "Input Okay. Age = " << age << endl;
        return age;
    }
};

#endif
