#include "Flight.hpp"
/* 
�S�M: TUBA
SOY�S�M:�ZG�NL�K
��RENC� K�ML���: 190504023
TAR�H: 22,01,2021
 */
Flight::Flight()
    : Cruise(), isCruise(false) {}

Flight::Flight(const std::string& tripName, const std::string& flightCode, float cost)
    : Cruise(tripName, cost), flightCode(flightCode), isCruise(false) {}

Flight::~Flight() {}

void Flight::setTripName(const std::string& tripName)
{
    this->tripName = tripName;
}

void Flight::setCost(float cost)
{
    this->cost = cost;
}

void Flight::setFlightCode(const std::string& flightCode)
{
    this->flightCode = flightCode;
}
