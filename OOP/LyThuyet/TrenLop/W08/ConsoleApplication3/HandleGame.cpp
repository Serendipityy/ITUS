#include "HandleGame.h"
using namespace std;



BusinessGate::BusinessGate(int p, int s) : price(p), stock(s) {}
bool BusinessGate::enter(int& money, int& iq, int& strength) {
    if (money >= price && stock > 0) {
        money -= price;
        stock--;
        return true;
    }
    else {
        return false;
    }
}


AcademicGate::AcademicGate(int i) : iq(i) {}
bool AcademicGate::enter(int& money, int& iq, int& strength) {
    if (iq >= this->iq) {
        return true;
    }
    else {
        return false;
    }
}


PowerGate::PowerGate(int s) : strength(s) {}
bool PowerGate::enter(int& money, int& iq, int& strength) {
    if (strength >= this->strength) {
        strength -= this->strength;
        return true;
    }
    else {
        return false;
    }
}


Castle::Castle(int numGates) {
    this->numGates = numGates;
    gates = new Gate * [numGates];
}
Castle::~Castle() {
    for (int i = 0; i < numGates; i++) {
        delete gates[i];
    }
    delete[] gates;
}
void Castle::addGate(int index, Gate* gate) {
    gates[index] = gate;
}
bool Castle::enterCastle(int& money, int& iq, int& strength) {
    for (int i = 0; i < numGates; i++) {
        if (!gates[i]->enter(money, iq, strength)) {
            return false;
        }
    }
    return true;
}

bool Castle::rescuePrincess(int& money, int& iq, int& strength) {
    bool canRescue = enterCastle(money, iq, strength);
    if (canRescue) {
        if (money == 0 || iq == 0 || strength == 0) {
            return false;
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

