#ifndef CASHIER_H
#define CASHIER_H
#include "Customer.h"

class Cashier{
	protected:
		double _averageServiceTime;
		Customer _currentCustomer;
		double _occupationRate;
		Bank* _bank;
	public:
		Cashier(double, Bank);
		double averageServiceTime();
		double occupationRate();
		void serve(Customer);
		void wait();
		bool isFree();
		Bank* bank();
};

#endif

