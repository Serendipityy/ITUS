// FlightTicketFactory.cpp

#include "FlightTicketFactory.h"

void FlightTicketFactory::bookTicket(string _passengerName, string _flightName, string _ticketType, double _price, string _seatNumber) {
	FlightTicket ticket(_passengerName, _flightName, _ticketType, _price, _seatNumber);
	ticketLists.push_back(ticket);
	cout << "Da dat ve may bay thanh cong cho hanh khach " << _passengerName << " voi cho ngoi " << _seatNumber << endl;
}

void FlightTicketFactory::printTicketLists() {
	cout << "\n----------* THONG TIN DAT VE MAY BAY* ----------\n" << endl;
	for (auto& ticket : ticketLists) {
		ticket.printTicket();
	}
}