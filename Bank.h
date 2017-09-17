#ifndef BANK_H
#define BANK_H


#include "WaitingQueue.h"
#include "Simulation.h"
#include "Cashier.h"
#include "Arrive.h"

class Arrive;
class Cashier; //Permet de dire que Cashier existe avant que le code soit inclus.

class Bank : public Simulation
{
    protected :

        Cashier** _cashiers;

		WaitingQueue _waitingQueue;
        double _averageArrivalTime;
        int _currentCashiersNbr;
        double _providedTime;
        int _customersNbr;
        double _realTime;
        int _cashiersNbr;

    public :

        //TODO : Gérer les Temps de services différents pour chaque caissier.
        Bank(double _averageArrivalTime, double _providedTime, int _cashiersNbr);

	  	double averageArrivalTime() const;
        WaitingQueue& waitingQueue();
        Cashier* freeCashier() const;
        double providedTime() const;
        Cashier &iemeCashier(int);
        int customersNbr() const;
        double realTime() const;
        int cashiersNbr() const;

		Customer* nextCustomer();
		void addCashier(double);
		void incrCustomers();
		void execute();

        ~Bank();
};

#endif
