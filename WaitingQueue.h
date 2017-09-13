#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include <iostream>
#include <deque>
#include "customer.h"
using namespace std;


class WaitingQueue{
	protected:
		deque<Customer> _customers;
		int _maxLength;
		double _averageLength;
		double _averageWaitingTime;
		
	public:
		WaitingQueue(int, double);
		~WaitingQueue();
		int maxLength();
		double averageLength();
		double averageWaitingTime();
		void add(Customer);
		Customer remove();
		bool isEmpty();

};

#endif
