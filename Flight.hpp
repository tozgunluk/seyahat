#ifndef FLIGHT_HPP
#define FLIGHT_HPP
#include <string>
#include "Cruise.hpp"
/* 
ÝSÝM: TUBA
SOYÝSÝM:ÖZGÜNLÜK
ÖÐRENCÝ KÝMLÝÐÝ: 190504023
TARÝH: 22,01,2021
 */

class Flight : public Cruise
{
    public:
        std::string flightCode;
        bool isCruise;
    public: 
        Flight();
        Flight(const std::string& tripName, const std::string& flightCode, float cost);
        ~Flight();
        void setTripName(const std::string& tripName) override;
        void setCost(float cost) override;
        void setFlightCode(const std::string& flightCode);
};

#endif
