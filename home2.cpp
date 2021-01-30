#include "Cruise.hpp"
/* 
�S�M: TUBA
SOY�S�M:�ZG�NL�K
��RENC� K�ML���: 190504023
TAR�H: 22,01,2021
 */
Cruise::Cruise()
    : tripName(""), cost(0.0f), isCruise(true) {}

Cruise::Cruise(const std::string& tripName, float cost)
    : tripName(tripName), cost(cost), isCruise(true) {}

Cruise::~Cruise() {}

void Cruise::setTripName(const std::string& tripName)
{
    this->tripName = tripName;
}

void Cruise::setCost(float cost)
{
    this->cost = cost;
}
