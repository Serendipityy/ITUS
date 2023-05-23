#include "divde_two_integer.h"

int main() {
    Divide d;
    try {
        d.input();
        cout << d.division() << endl;
    }
    catch (myException e) {
        cout << "Exception caught: " << e.getMessage() << endl;
    }
    return 0;
}