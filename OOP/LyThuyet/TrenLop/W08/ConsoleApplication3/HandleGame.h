#include <iostream>
#include <string>
using namespace std;

class Gate {
public:
    virtual bool enter(int& money, int& iq, int& strength) = 0;
};

class BusinessGate : public Gate {
private:
    int price; // don gia hang hoa
    int stock; // so luong hang hoa con lai
public:
    BusinessGate(int p, int s);
    bool enter(int& money, int& iq, int& strength);
};

class AcademicGate : public Gate {
private:
    int iq; // chi so tri tue cua nha hien triet
public:
    AcademicGate(int i);
    bool enter(int& money, int& iq, int& strength);
};

class PowerGate : public Gate {
private:
    int strength; // chi so suc manh cua dung sy
public:
    PowerGate(int s);
    bool enter(int& money, int& iq, int& strength);
};

class Castle {
private:
    Gate** gates; // mang cac con tro toi cac cua
    int numGates; // so luong cua trong castle
public:
    Castle(int numGates);
    ~Castle();
    void addGate(int index, Gate* gate);
    bool enterCastle(int& money, int& iq, int& strength);
    bool rescuePrincess(int& money, int& iq, int& strength);

};