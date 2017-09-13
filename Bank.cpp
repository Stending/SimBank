#include "Bank.h"

Bank::Bank(double _averageArrivalTime, double _providedTime, int _cashiersNbr)
{

}

double Bank::averageArrivalTime() const
{
    return _averageArrivalTime;
}

Cashier Bank::freeCashier() const
{

}

double Bank::providedTime() const
{
    return _providedTime;
}

int Bank::customersNbr() const
{
    return _customersNbr;
}

double Bank::realTime() const
{
    return _realTime;
}

int Bank::cashiersNbr() const
{
    return _cashiersNbr;
}

Bank::~Bank()
{

}
