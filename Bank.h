#ifndef BANK_H
#define BANK_H

#include "Cashier.h"
#include "Simulation.h"
#include "WaitingQueue.h"
#include "Arrive.h"

class Arrive;
class Cashier; //Permet de dire que Cashier existe avant que le code soit inclus.

class Bank : public Simulation
{
    protected :
		WaitingQueue _waitingQueue;
        double _averageArrivalTime;
        double _providedTime;
        int _customersNbr;
        Cashier** _cashiers;
        double _realTime;
        int _cashiersNbr;
		int _currentCashiersNbr;
    public :
        //TODO : Gérer les Temps de services différents pour chaque caissier.
        Bank(double _averageArrivalTime, double _providedTime, int _cashiersNbr);
	  	WaitingQueue& waitingQueue();
		double averageArrivalTime() const;
		void addCashier(Cashier&);
		void addCashier(double);
        Cashier freeCashier() const;
        double providedTime() const;
        int customersNbr() const;
        double realTime() const;
        int cashiersNbr() const;
		Customer* nextCustomer();
        ~Bank();
};

#endif
