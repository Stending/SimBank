#include "customer.h"

Customer::Customer(double _arrivalTime)
{
    (*this)._arrivalTime = _arrivalTime;
}

double Customer::arrivalTime()
{
    return _arrivalTime;
}
