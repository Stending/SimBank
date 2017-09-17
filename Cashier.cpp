#include "Cashier.h"
#include "Poisson.h"

Cashier::Cashier(double averageServiceTime, Bank *bank)
{
	_averageServiceTime = averageServiceTime;
	_bank = bank;

    _occupationTime = 0;
    _customersNbr = 0;
	_isFree = true;
}

double Cashier::occupationTime() const
{
    return _occupationTime;
}

double Cashier::averageServiceTime() const
{
	return _averageServiceTime;
}

double Cashier::occupationRate() const
{
	return _occupationRate;
}

bool Cashier::isFree() const
{
	return _isFree;
}

Bank* Cashier::bank() const
{
	return _bank;
}

int Cashier::customersNbr() const
{
    return _customersNbr;
}

void Cashier::serve(Customer* c)
{
    double serviceTime = Poisson::next(_averageServiceTime);
	double serviceEnd = (*_bank).time() + serviceTime;

    _isFree = false;
    _customersNbr++;
    _currentCustomer = c;
    (*_bank).incrCustomers();
	_occupationTime += serviceTime;
	_occupationRate = _occupationTime / (*_bank).time();

	Release *r = new Release(this, serviceEnd);
	(*_bank).addEvent(r);

	cout << "Le service commence au temps t = " << (*_bank).time() << " et finira au temps t = " << serviceEnd << endl;
}

void Cashier::wait()
{
    delete _currentCustomer;


	Customer* nextCustomer = _bank->nextCustomer();

    //TODO gérer le temps d'attente du client pris dans la file d'attente + la longueure moyenne de la file
	if(nextCustomer)
	{
        (*_bank).waitingQueue().decrCurrentLength((*_bank).time());
        (*_bank).waitingQueue().increaseWaitingTime((*_bank).time()-(*nextCustomer).arrivalTime());
        serve(nextCustomer);
	}
	else
	{
		_currentCustomer = NULL;
		_isFree = true;
	}
}
