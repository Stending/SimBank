#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include <iostream>
#include <deque>
#include "Customer.h"
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
		int maxLength() const;
		double averageLength()const;
		double averageWaitingTime() const;
		bool isEmpty() const;
		void add(Customer);
		Customer remove();

};

#endif
