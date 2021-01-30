#ifndef CRUISE_HPP
#define CRUISE_HPP
#include <string>
/* 
ÝSÝM: TUBA
SOYÝSÝM:ÖZGÜNLÜK
ÖÐRENCÝ KÝMLÝÐÝ: 190504023
TARÝH: 22,01,2021
 */
class Cruise
{
    public:
        std::string tripName;
        float cost;
        bool isCruise;
    public:
        Cruise();
        Cruise(const std::string& tripName, float cost);
        ~Cruise();
        virtual void setTripName(const std::string& tripName);
        virtual void setCost(float cost);
};

#endif
