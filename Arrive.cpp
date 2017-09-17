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

    double nextCustomerIn = Poisson::next((*_bank).averageArrivalTime());
	nextTime = (_time + nextCustomerIn);

    if(nextTime < (*_bank).providedTime())
    {
        (*_bank).addEvent(new Arrive(_bank, nextTime));
        cout << "Le prochain client arrivera à t = " << nextTime << endl;
    }
}

string Arrive::eventType()
{
    return "arrivé";
}
