#pragma once
#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instances[5];
    static int count;
    int id;
    Singleton();
public:
    static Singleton* getInstance();
    void printId();
};
