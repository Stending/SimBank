#include "Poisson.h"
#include "Arrive.h"
#include "Bank.h"

Arrive::Arrive(Bank *_bank, double _time) : Event(_time)
{
    (*this)._bank = _bank;
}

void Arrive::process()
{
    cout << "On est dans Arrive.process()" << endl;

    double nextTime;

    if((*_bank).freeCashier() == NULL)
        ((*_bank).waitingQueue()).add(new Customer((*_bank).time()));
    else
        (*(*_bank).freeCashier()).serve(new Customer((*_bank).time()));

    //TODO vérifier que l'on ne dépasse pas le temps total de simulation

	double nextCustomerIn = Poisson::next((*_bank).averageArrivalTime());
	cout << "Le prochain client arrivera dans " << nextCustomerIn << endl;
	cout << "La bank est au temps t = " << (*_bank).time() << endl;
    nextTime = (_time + nextCustomerIn);
    if(nextTime < (*_bank).providedTime())
    {
        (*_bank).addEvent(new Arrive(_bank, nextTime));
        cout << "Un client arrive, et un prochain arrivera à " << nextTime << endl;
    }
}
