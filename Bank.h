#ifndef BANK_H
#define BANK_H

#include "Cashier.h"
#include "Simulation.h"

class Cashier; //Permet de dire que Cashier existe avant que le code soit inclus.

class Bank : public Simulation
{
    protected :
        double _averageArrivalTime;
        double _providedTime;
        int _customersNbr;
        Cashier* _cashiers;
        double _realTime;
        int _cashiersNbr;

    public :
        //TODO : Gérer les Temps de services différents pour chaque caissier.
        Bank(double _averageArrivalTime, double _providedTime, int _cashiersNbr);
        double averageArrivalTime() const;
        Cashier freeCashier() const;
        double providedTime() const;
        int customersNbr() const;
        double realTime() const;
        int cashiersNbr() const;
        ~Bank();
};

#endif
