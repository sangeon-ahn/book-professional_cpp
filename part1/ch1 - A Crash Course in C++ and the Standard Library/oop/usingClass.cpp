#include "AirlineTicket.h"

int main()
{
    AirlineTicket ticket;
    ticket.setPassengerName("Sangeon");
    ticket.setNumberOfMiles(2999);

    AirlineTicket ticket2("SSangeon", 1000, true);
    std::cout << ticket2.getPassengerName() << ticket2.getNumberOfMiles() << std::endl;
}