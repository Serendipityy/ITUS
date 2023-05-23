#include "Bike.h"

Bike::Bike() {

}

Bike::~Bike() {

}

void Bike::input() {
	Vehicle::input();
}

void Bike::print() {
	Vehicle::print();
}

double Bike::calcRentMoney() {
	return 10000 + ((rentHour - 1) * 8000);
}