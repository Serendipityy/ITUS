class TicketBookingSystem
{
private:
    vector<FlightTicket*> tickets;
public:
    void bookTicket(string _passengerName, string _flightName, string _ticketType, double _price, string _seatNumber);
    void printTicketsList();
    ~TicketBookingSystem();
};
