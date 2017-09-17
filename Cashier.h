#ifndef CASHIER_H
#define CASHIER_H

#include "Customer.h"
#include "Release.h"
#include "Bank.h"

#include <cstddef>

class Release;
class Bank;

class Cashier
{
	protected :

        Customer* _currentCustomer;
		Bank* _bank;

		double _averageServiceTime;
		double _occupationRate;
		double _occupationTime;
		int _customersNbr;
		bool _isFree;

	public :

        Cashier(double, Bank*);

		double averageServiceTime() const;
		double occupationRate() const;
		double occupationTime() const;
		int customersNbr() const;
		bool isFree() const;
		Bank* bank() const;

		void serve(Customer*);
		void wait();
};

#endif

