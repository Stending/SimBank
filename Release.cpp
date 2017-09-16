#include "Release.h"

Release::Release(Cashier* cashier, double time) : Event(time)
{
	_cashier = cashier;
	_time = time;
}

void Release::process(){
    cout << "On est dans Release.process()" << endl;
	cout << "Le caissier " << _cashier << " est libéré" << endl;
	_cashier->wait();
}
