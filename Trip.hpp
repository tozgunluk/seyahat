#ifndef TRIP_HPP
#define TRIP_HPP
#include <iostream>
#include "Cruise.hpp"
#include "Flight.hpp"

template<class T> class Trip;
/*template<class T> std::ostream& operator<<(std::ostream& os, const Trip<Cruise>& tripCruise);
template<class T> std::ostream& operator<<(std::ostream& os, const Trip<Flight>& tripFlight);
template<class T> std::ostream& operator<<(std::ostream& os, const Trip<Trip<Cruise>>& nestedTripCruise);
template<class T> std::ostream& operator<<(std::ostream& os, const Trip<Trip<Flight>>& nestedTripFlight);*/

template<class T>
class Trip
{
    private:
        T* elements;
        int size;
        int maxSize;
    public:
        int discount;
    public:
        Trip();
        Trip(const T& object);
        Trip(const T* object, int tSize);
        ~Trip();
        void Add(const T& object);
        void setDiscount(int discount);
        int Size() const;
        float totalCost() const;
        T& operator[](int index) const;
        void operator+=(const Trip<T>& trip);
        friend std::ostream& operator<<(std::ostream& os, const Trip<Cruise>& tripCruise);
        friend std::ostream& operator<<(std::ostream& os, const Trip<Flight>& tripFlight);
        friend std::ostream& operator<<(std::ostream& os, const Trip<Trip<Cruise>>& nestedTripCruise);
        friend std::ostream& operator<<(std::ostream& os, const Trip<Trip<Cruise>>& nestedTripFlight);
    private:
        void Allocate();
        void Allocate(int tSize);
};

#include "Trip.cpp"

#endif