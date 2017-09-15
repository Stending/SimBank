#include "Poisson.h"
#include "Arrive.h"
#include "Bank.h"

Arrive::Arrive(Bank *_bank, double _time) : Event(_time)
{
    (*this)._bank = _bank;
}

void Arrive::process()
{
    double nextTime;

    if((*_bank).freeCashier() == NULL)
        ((*_bank).waitingQueue()).add(new Customer((*_bank).time()));
    else
        (*(*_bank).freeCashier()).serve(new Customer((*_bank).time()));

    //TODO vérifier que l'on ne dépasse pas le temps total de simulation
    nextTime = ((*_bank).time() + Poisson::next((*_bank).averageArrivalTime()));
    if(nextTime < (*_bank).providedTime())
    {
        (*_bank).addEvent(new Arrive(_bank, nextTime));
        cout << "Un client arrive, et un prochain arrivera à " << nextTime << endl;
    }
}
