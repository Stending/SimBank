#ifndef WAITINGQUEUE_H
#define WAITINGQUEUE_H

#include "Customer.h"

#include <iostream>
#include <deque>

using namespace std;

class WaitingQueue
{
	protected :

		int _maxLength;
		int _currentLength;
		double _averageLength;
		double _lastModifTime;
		double _averageWaitingTime;
		deque<Customer*> _customers;

	public :

		WaitingQueue();

		bool isEmpty() const;
		int maxLength() const;
        int currentLength() const;
		double averageLength()const;
		double averageWaitingTime() const;

		Customer* remove();
		void add(Customer*);
		void incrCurrentLength(double time);
        void decrCurrentLength(double time);
        void increaseWaitingTime(double time);

		~WaitingQueue();
};

#endif
