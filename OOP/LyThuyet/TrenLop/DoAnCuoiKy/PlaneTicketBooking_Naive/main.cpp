// main.cpp
#include "FlightTicketFactory.h"

int main() {
    FlightTicketFactory factory;

    factory.bookTicket("Helen", "Ho Chi Minh City - Shanghai", "Business", 20500666.0, "16F");
    factory.bookTicket("Ming Ye", "Beijing - Shanghai", "Business", 25251325.0, "16E");
    factory.bookTicket("Edward Tian", "Princeton, New Jersey - Beijing", "Economic", 234552012.0, "20A");
    factory.bookTicket("Shunyu Yao", "Washington D.C - Chengdu", "Economic", 212552066.0, "19D");
    factory.bookTicket("Meiko", "Ho Chi Minh City - Shanghai", "Business", 20500666.0, "16D");
    factory.bookTicket("Serendipity", "Princeton, New Jersey - Beijing", "Economic", 25251325.0, "22C");

    factory.printTicketLists();

    return 0;
}