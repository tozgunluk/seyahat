#ifndef CRUISE_HPP
#define CRUISE_HPP
#include <string>
/* 
�S�M: TUBA
SOY�S�M:�ZG�NL�K
��RENC� K�ML���: 190504023
TAR�H: 22,01,2021
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
