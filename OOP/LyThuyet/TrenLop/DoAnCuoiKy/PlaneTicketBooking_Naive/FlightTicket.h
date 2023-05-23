// FlightTicket.h
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

using namespace std;

class FlightTicket {
private:
    string passengerName; // Tên hành khách
    string flightName; // Tên chuyến bay
    string ticketType; // Loại vé
    double price; // Giá vé
    string seatNumber; // Chỗ ngồi
public:
    // Constructor
    FlightTicket();
    FlightTicket(string _passengerName, string _flightName, string _ticketType, double _price, string _seatNumber);
    // In thông tin vé máy bay
    void printTicket();
};