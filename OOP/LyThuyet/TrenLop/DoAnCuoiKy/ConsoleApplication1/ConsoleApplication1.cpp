#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FlightTicket {
public:
    string flightName;
    string ticketType;
    string seatNumber;
    double price;

    FlightTicket(string _flightName, string _ticketType, string _seatNumber, double _price) 
        : flightName(_flightName), ticketType(_ticketType), seatNumber(_seatNumber), price(_price) {}
};

class FlightTicketBooking {
public:
    string passengerName;
    FlightTicket* flight;

    FlightTicketBooking(string _passengerName, FlightTicket* f) : passengerName(_passengerName), flight(f) {}
};

class FlightManager {
private:
    vector<FlightTicket*> flights;
    vector<FlightTicketBooking*> bookings;

public:

    void addFlight(string flightName, string ticketType, string seatNumber, double price) {
        flights.push_back(new FlightTicket(flightName, ticketType, seatNumber, price));
    }

    void bookFlight(string passengerName, string flightName, string ticketType) {
        FlightTicket* flight = findFlight(flightName, ticketType);
        if (flight == nullptr) {
            cout << "Sorry, no available flight found." << endl;
        }
        else {
            bookings.push_back(new FlightTicketBooking(passengerName, flight));
            cout << "Booking confirmed for " << passengerName << " on flight " << flightName << " with seat type " << ticketType << "." << endl;
        }
    }

    FlightTicket* findFlight(string flightName, string ticketType) {
        for (FlightTicket* flight : flights) {
            if (flight->flightName == flightName && flight->ticketType == ticketType) {
                return flight;
            }
        }
        return nullptr;
    }
};

// Driver program
int main() {
    // Create a new flight manager
    FlightManager fm;

    // Add some flights
    fm.addFlight("Flight 001", "Economy", "2A", 100.25);
    fm.addFlight("Flight 002", "Economy","3B", 150);
    fm.addFlight("Flight 003", "Business", "20F", 300);
    fm.addFlight("Flight 004", "Business","4G", 500);

    // Book some flights
    fm.bookFlight("John Smith", "Flight 001", "Economy");
    fm.bookFlight("Mary Brown", "Flight 002", "Economy");
    fm.bookFlight("Peter Davis", "Flight 003", "Business");
    fm.bookFlight("Lisa White", "Flight 004", "Business");

    return 0;
}
