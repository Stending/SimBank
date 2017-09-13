#include "Customer.h"

Customer::Customer(double _arrivalTime)
{
    (*this)._arrivalTime = _arrivalTime;
}

double Customer::arrivalTime() const
{
    return _arrivalTime;
}
