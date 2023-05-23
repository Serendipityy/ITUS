#include "Person.h"

Person::Person() {
    identity = 0;
}

Person::Person(long id) {
    assert(identity >= 100000000 && identity <= 999999999);
    identity = id;
}

Person::~Person() {
}

Person::Person(const Person& person) {
    identity = person.identity;
}

long Person::getId() const {
    return identity;
}

void Person::setId(long id) {
    assert(identity >= 100000000 && identity <= 999999999);
    identity = id;
}



void Person::input() {
    cout << "Enter identity: ";
    cin >> identity;
    assert(identity >= 100000000 && identity <= 999999999);
}

void Person::output() {
    cout << "Identity: " << identity << endl;
}
