// FlightTicket.cpp

#include "FlightTicket.h"
using namespace std;

FlightTicket::FlightTicket() {
	passengerName = "";
    flightName = "";
    ticketType = "";
    price = 0.0;
    seatNumber = "";
};

FlightTicket::FlightTicket(string _passengerName, string _flightName, string _ticketType, double _price, string _seatNumber) {
    passengerName = _passengerName;
    flightName = _flightName;
    ticketType = _ticketType;
    price = _price;
    seatNumber = _seatNumber;
}

void FlightTicket::printTicket() {
    cout << "Ten hanh khach: " << passengerName << endl;
    cout << "Ten chuyen bay: " << flightName << endl;
    cout << "Loai ve: " << ticketType << endl;
    cout << "Gia ve: " <<fixed << setprecision(1) << price << endl;
    cout << "So ghe ngoi: " << seatNumber << endl;
    cout << endl;
}