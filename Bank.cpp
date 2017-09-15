#include "Bank.h"


Bank::Bank(double averageArrivalTime, double providedTime, int cashiersNbr):_waitingQueue(10,20) //en dur pour le moment, à changer
{
	_averageArrivalTime = averageArrivalTime;
	_providedTime = providedTime;
	_cashiersNbr = cashiersNbr;
	_cashiers = new Cashier*[cashiersNbr];
	_currentCashiersNbr = 0;

	for (int i=0;i<cashiersNbr;i++){
		_cashiers[i] = new Cashier(10, this);
	}

	double timeBeforeNextCustomer = _averageArrivalTime; //TODO loi de Poisson;
	double nextCustomerTime = _time + timeBeforeNextCustomer;
	//Arrive arrive(this, nextCustomerTime);
}

double Bank::averageArrivalTime() const
{
    return _averageArrivalTime;
}

Cashier Bank::freeCashier() const
{
	//TODO
	return **_cashiers; //retourne le tout premier caissier (à changer)
}

WaitingQueue& Bank::waitingQueue(){
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

Customer* Bank::nextCustomer(){
	return _waitingQueue.remove();
}

Bank::~Bank()
{
	
}
