#include "Poisson.h"
#include "Bank.h"

Bank::Bank(double averageArrivalTime, double providedTime, int cashiersNbr) : _waitingQueue()
{
	_averageArrivalTime = averageArrivalTime;
	_cashiers = new Cashier*[cashiersNbr];
	_providedTime = providedTime;
	_cashiersNbr = cashiersNbr;
	_currentCashiersNbr = 0;
	_customersNbr = 0;

	for(int i = 0; i < cashiersNbr; i++)
	{
		_cashiers[i] = new Cashier(10, this);
	}

	double nextTime = Poisson::next(_averageArrivalTime);
	Arrive* arrive = new Arrive(this, nextTime);
	addEvent(arrive);

	cout << "Le premier client arrivera à " << nextTime << endl;
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

WaitingQueue& Bank::waitingQueue()
{
	return _waitingQueue;
}

void Bank::addCashier(double averageServiceTime)
{
    if(_currentCashiersNbr < _cashiersNbr)
    {
        _cashiers[_currentCashiersNbr] = new Cashier(averageServiceTime, this);

        _currentCashiersNbr++;
    }
    else
        cout << "La banque ne dispose pas de fonds suffisant pour embaucher un nouvel employé" << endl;
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

Customer* Bank::nextCustomer()
{
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

		delete e;
	}
	else
	{
        _realTime = _time;
	}
}

void Bank::incrCustomers()
{
    _customersNbr++;
}

Bank::~Bank()
{
    for(int i = 0; i < _cashiersNbr; i++)
        delete _cashiers[i];

    delete[] _cashiers;
}

Cashier &Bank::iemeCashier(int i)
{
    return *_cashiers[i];
}
