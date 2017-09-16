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

	cout << "La banque est crée" << endl;
	double timeBeforeNextCustomer = _averageArrivalTime; //TODO loi de Poisson;
	double nextCustomerTime = _time + timeBeforeNextCustomer;
	cout << "Le premier client arrivera à " << nextCustomerTime << endl;
	Arrive* arrive = new Arrive(this, nextCustomerTime);
	addEvent(arrive);
	cout << "L'event Arrive dit qu'un client arrivera à " << arrive->time() << endl;
	cout << "Il reste " << _eventQueue.size() << " à dérouler." << endl;
}

double Bank::averageArrivalTime() const
{
    return _averageArrivalTime;
}

Cashier* Bank::freeCashier() const
{
	for(int i = 0; i < _cashiersNbr; i++)
    {
        if(_cashiers[i] != NULL && (*_cashiers[i]).isFree())
            return _cashiers[i];
    }

	return NULL;
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

void Bank::execute()
{
	if(!_eventQueue.empty())
	{
		Event* e = _eventQueue.firstEvent();
		_eventQueue.removeFirstEvent();
		_time = e->time();

		cout << "L'évènement, de type " << (*e).eventType() << ", à lieu au temps t = " << (*e).time() << endl;

		(*e).process();
		execute();

		//cout << "Il reste " << _eventQueue.size() << " évènement(s) à dérouler." << endl;

		delete e;
	}
}

Bank::~Bank()
{

}
