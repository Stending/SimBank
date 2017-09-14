#include "Bank.h"


Bank::Bank(double _averageArrivalTime, double _providedTime, int _cashiersNbr)
{
	this->_averageArrivalTime = _averageArrivalTime;
	this->_providedTime = _providedTime;
	this->_cashiersNbr = _cashiersNbr;
	_cashiers = new *Cashier[_cashiersNbr];
	_currentCashiersNbr = 0;
}

double Bank::averageArrivalTime() const
{
    return _averageArrivalTime;
}

Cashier Bank::freeCashier() const
{
	//TODO
	return *_cashiers;
}

WaitingQueue& Bank::waitingQueue() const{
	return _waitingQueue;

}

void Bank::addCashier(Cashier& c){
	_cashiers[_currentCashiersNbr] = &c;
}
void Bank::addCashier(double averageServiceTime){
	Cashier c(averageServiceTime, this);
	addCashier(c);
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
