#include "WaitingQueue.h"

WaitingQueue::WaitingQueue()
{
	_maxLength = 0;
	_averageWaitingTime = 0;
}

int WaitingQueue::maxLength() const
{
	return _maxLength;
}

double WaitingQueue::averageLength() const
{
	return _averageLength;
}

double WaitingQueue::averageWaitingTime() const
{
	return _averageWaitingTime;
}

bool WaitingQueue::isEmpty() const
{
	return _customers.empty();
}

void WaitingQueue::add(Customer* customer)
{
	_customers.push_back(customer);
}

Customer* WaitingQueue::remove()
{
	if(!_customers.empty())
	{
		Customer* c = _customers.front();
		_customers.pop_front();
		return c;
	}

	return NULL;
}

WaitingQueue::~WaitingQueue()
{
}
