#include <iostream>
#include "Trip.hpp"
#include "Cruise.hpp"
#include "Flight.hpp"
/* 
ÝSÝM: TUBA
SOYÝSÝM:ÖZGÜNLÜK
ÖÐRENCÝ KÝMLÝÐÝ: 190504023
TARÝH: 22,01,2021
 */

int main()
{
    Flight flight1("Istanbul-Ankara", "TK213", 212.5);
    Trip<Flight> flightTrip(flight1); 
    try 
    {
        flightTrip[0].setCost(186.5); 
        flightTrip[1].setCost(186.5);
    }
    catch (const std::string& exc) 
    {
        std::cout << exc << std::endl; 
    } 
    std::cout << flightTrip << std::endl;

    Flight flight2("Ankara-Istanbul", "TK312",203.5);
    flightTrip.Add(flight2);
    std::cout << flightTrip << std::endl;

    Flight* flightArray = new Flight[2];
    flightArray[0] = Flight("Istanbul-Izmir", "TK113", 183.5);
    flightArray[1] = Flight("Izmir-Istanbul", "TK311", 162.5); 

    Trip<Flight> flightTrip2(flightArray, 2);

    delete[] flightArray; 

    flightTrip += flightTrip2;
    try 
    { 
        flightTrip.setDiscount(10);
        flightTrip.setDiscount(50);
    } 
    catch (const std::string& exc)
    {
        std::cout << exc << std::endl; 
    }
    std::cout << flightTrip << std::endl;

    Trip<Trip<Flight>> multipleTrips; 
    multipleTrips.Add(flightTrip);
    multipleTrips.Add(flightTrip2); 
    multipleTrips.setDiscount(20); 
    std::cout << multipleTrips << std::endl;

    Cruise c("Istanbul-Izmir", 180.2); 
    Trip<Cruise> crouseTrip(c); 
    crouseTrip.setDiscount(15); 
    std::cout << crouseTrip << std::endl;

    std::cin.get();

    std::exit(1);

    return 0;
}
