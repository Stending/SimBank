#ifndef CASHIER_H
#define CASHIER_H
#include "Customer.h"
#include "Bank.h"
#include <cstddef>

class Bank; //Permet de dire que Bank existe avant que le code soit inclus.

class Cashier{
	protected:
		double _averageServiceTime;
		Customer* _currentCustomer;
		double _occupationRate;
		Bank* _bank;
	public:
		Cashier(double, Bank*);
		double averageServiceTime() const;
		double occupationRate()const;
		bool isFree() const;
		Bank* bank() const;
		void serve(Customer*);
		void wait();
};

#endif

