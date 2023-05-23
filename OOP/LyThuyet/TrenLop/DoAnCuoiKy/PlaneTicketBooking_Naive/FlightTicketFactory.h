// FlightTicketFactory.h

#pragma once
#include "FlightTicket.h"

class FlightTicketFactory {
private:
    // Lưu trữ danh sách các vé máy bay
    vector<FlightTicket> ticketLists; 
public:
    // Đặt vé máy bay
    void bookTicket(string _passengerName, string _flightName, string _ticketType, double _price, string _seatNumber);
    // In danh sách các vé máy bay đã đặt
    void printTicketLists();
};
