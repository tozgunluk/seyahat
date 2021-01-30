#include "Trip.hpp"
/* 
ÝSÝM: TUBA
SOYÝSÝM:ÖZGÜNLÜK
ÖÐRENCÝ KÝMLÝÐÝ: 190504023
TARÝH: 22,01,2021
 */
template<class T> Trip<T>::Trip()
    : maxSize(2), size(0), discount(-1)
{
    elements = new T[maxSize];
}

template<class T> Trip<T>::Trip(const T& object)
    : maxSize(2), size(1), discount(-1)
{
    elements = new T[maxSize];
    elements[0] = object;
}

template<class T> Trip<T>::Trip(const T* object, int tSize)
    : maxSize(tSize + 2), size(tSize), discount(-1)
{
    elements = new T[maxSize];

    for(int i = 0; i < tSize; i++)
        elements[i] = *(object + i);
}

template<class T> Trip<T>::~Trip()
{
    delete[] elements;
}

template<class T> void Trip<T>::Add(const T& object)
{
    if (size + 1 > maxSize)
        Allocate();
    
    elements[size] = object;
    size++;
}

template<class T> void Trip<T>::setDiscount(int discount)
{
    if(discount < 0 || discount > 40)
        throw std::string("Exception: Discount::Out_Of_Range");

    this->discount = discount;
}

template<class T> int Trip<T>::Size() const
{
    return size;
}

template<class T> T& Trip<T>::operator[](int index) const
{
    if(index < size)
        return elements[index];
    else throw std::string("Exception: Index::Out_Of_Range");
}

template<class T> void Trip<T>::operator+=(const Trip& trip)
{
    if(size + trip.size > maxSize)
        Allocate(trip.size);

    for(int i = size, j = 0; i < size + trip.size; i++, j++)
        elements[i] = trip.elements[j];

    size += trip.size;
}

template<class T> void Trip<T>::Allocate()
{
    maxSize = size * 2;
    T* temp = new T[maxSize];

    for(int i = 0; i < size; i++)
        temp[i] = elements[i];
    
    delete[] elements;

    elements = temp;
}

template<class T> void Trip<T>::Allocate(int tSize)
{
    maxSize = size * 2 + tSize;
    T* temp = new T[maxSize];

    for(int i = 0; i < size; i++)
        temp[i] = elements[i];
    
    delete[] elements;

    elements = temp;
}

template<class T> float Trip<T>::totalCost() const
{
    float total = 0.0f;
    for(int i = 0; i < size; i++)
        total += elements[i].cost;

    return total;
}

std::ostream& operator<<(std::ostream& os, const Trip<Cruise>& tripCruise)
{
    if(tripCruise.discount == -1)
    {
        os << "***********************" << std::endl
            << "Trip transfer count: " << tripCruise.size << std::endl;

        for(int i = 0; i < tripCruise.size; i++)
            os << i + 1 << " -> Cruise Name: " << tripCruise[i].tripName 
                << " Cost: " << tripCruise[i].cost << std::endl;

        os << "***********************" << std::endl
            << "Trip total cost: " << tripCruise.totalCost() << std::endl
            << "***********************" << std::endl; 
    }
    else if(tripCruise.discount != -1)
    {
        os << "***********************" << std::endl 
            << "Trip transfer count: " << tripCruise.size << std::endl;

        for(int i = 0; i < tripCruise.size; i++)
            os << i + 1 << " -> Cruise Name: " << tripCruise[i].tripName 
                << " Cost: " << tripCruise[i].cost << std::endl;

        os << "***********************" << std::endl
            << "Trip total cost: " << tripCruise.totalCost() << std::endl
            << "Discount: " << tripCruise.discount << std::endl
            << "Discount amount: " << -(tripCruise.totalCost() / 100 * tripCruise.discount) << std::endl
            << "Discounted cost: " << tripCruise.totalCost() - (tripCruise.totalCost() / 100 * tripCruise.discount) << std::endl
            << "***********************" << std::endl;
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const Trip<Flight>& tripFlight)
{   
    if(tripFlight.discount == -1)
    {
        os << "***********************" << std::endl
            << "Trip transfer count: " << tripFlight.size << std::endl;

        for(int i = 0; i < tripFlight.size; i++)
            os << i + 1 << " -> Flight Name: " << tripFlight[i].tripName 
                << " #" << tripFlight[i].flightCode << " Cost: " << tripFlight[i].cost << std::endl;

        os << "***********************" << std::endl
            << "Trip total cost: " << tripFlight.totalCost() << std::endl
            << "***********************" << std::endl; 
    }
    else if(tripFlight.discount != -1)
    {
        os << "***********************" << std::endl 
            << "Trip transfer count: " << tripFlight.size << std::endl;

        for(int i = 0; i < tripFlight.size; i++)
            os << i + 1 << " -> Flight Name: " << tripFlight[i].tripName 
                << " #" << tripFlight[i].flightCode << " Cost: " << tripFlight[i].cost << std::endl;

        os << "***********************" << std::endl
            << "Trip total cost: " << tripFlight.totalCost() << std::endl
            << "Discount: " << tripFlight.discount << std::endl
            << "Discount amount: " << -(tripFlight.totalCost() / 100 * tripFlight.discount) << std::endl
            << "Discounted cost: " << tripFlight.totalCost() - (tripFlight.totalCost() / 100 * tripFlight.discount) << std::endl
            << "***********************" << std::endl;
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const Trip<Trip<Cruise>>& nestedTripCruise)
{
    for(int i = 0; i < nestedTripCruise.Size(); i++)
    {   
        if(nestedTripCruise.discount == -1)
        {    
            os << "***********************" << std::endl
                << "Trip transfer count: " << nestedTripCruise[i].Size() << std::endl;

            for(int j = 0; j < nestedTripCruise[i].Size(); j++)
                os << j + 1 << " -> Cruise Name: " << nestedTripCruise[i][j].tripName 
                    << " Cost: " << nestedTripCruise[i][j].cost << std::endl;
            
            os << "***********************" << std::endl
                << "Trip total cost: " << nestedTripCruise[i].totalCost() << std::endl
                << "***********************" << std::endl; 
        }
        else if(nestedTripCruise.discount != -1)
        {
            os << "***********************" << std::endl 
                << "Trip transfer count: " << nestedTripCruise[i].Size() << std::endl;

            for(int j = 0; j < nestedTripCruise[i].Size(); j++)
                os << j + 1 << " -> Cruise Name: " << nestedTripCruise[i][j].tripName 
                    << " Cost: " << nestedTripCruise[i][j].cost << std::endl;

            os << "***********************" << std::endl
                << "Trip total cost: " << nestedTripCruise[i].totalCost() << std::endl
                << "Discount: " << nestedTripCruise.discount << std::endl
                << "Discount amount: " << -(nestedTripCruise[i].totalCost() / 100 * nestedTripCruise.discount) << std::endl
                << "Discounted cost: " << nestedTripCruise[i].totalCost() - (nestedTripCruise[i].totalCost() / 100 * nestedTripCruise.discount) << std::endl
                << "***********************" << std::endl;
        }
    }
    return os;
}
std::ostream& operator<<(std::ostream& os, const Trip<Trip<Flight>>& nestedTripFlight)
{
    for(int i = 0; i < nestedTripFlight.Size(); i++)
    {  
        if(nestedTripFlight.discount == -1)
        {    
            os << "***********************" << std::endl
                << "Trip transfer count: " << nestedTripFlight[i].Size() << std::endl;

            for(int j = 0; j < nestedTripFlight[i].Size(); j++)
                os << j + 1 << " -> Flight Name: " << nestedTripFlight[i][j].tripName 
                    << " #" << nestedTripFlight[i][j].flightCode << " Cost: " << nestedTripFlight[i][j].cost << std::endl;
            
            os << "***********************" << std::endl
                << "Trip total cost: " << nestedTripFlight[i].totalCost() << std::endl
                << "***********************" << std::endl; 
        }
        else if(nestedTripFlight.discount != -1)
        {
            os << "***********************" << std::endl
                << "Trip transfer count: " << nestedTripFlight[i].Size() << std::endl;

            for(int j = 0; j < nestedTripFlight[i].Size(); j++)
                os << j + 1 << " -> Cruise Name: " << nestedTripFlight[i][j].tripName 
                    << " Cost: " << nestedTripFlight[i][j].cost << std::endl;

            os << "***********************" << std::endl
                << "Trip total cost: " << nestedTripFlight[i].totalCost() << std::endl
                << "Discount: " << nestedTripFlight.discount << std::endl
                << "Discount amount: " << -(nestedTripFlight[i].totalCost() / 100 * nestedTripFlight.discount) << std::endl
                << "Discounted cost: " << nestedTripFlight[i].totalCost() - (nestedTripFlight[i].totalCost() / 100 * nestedTripFlight.discount) << std::endl
                << "***********************" << std::endl;
        }
    }
    return os;
}
