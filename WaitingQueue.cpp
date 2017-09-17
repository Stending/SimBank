#include "WaitingQueue.h"

WaitingQueue::WaitingQueue()
{
	_maxLength = 0;
	_currentLength = 0;
	_lastModifTime = 0;
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

void WaitingQueue::increaseWaitingTime(double time)
{
    _averageWaitingTime += time;
}

void WaitingQueue::incrCurrentLength(double time)
{
    _averageLength += (time - _lastModifTime) * _currentLength;
    _currentLength++;

    if(_currentLength > _maxLength)
        _maxLength = _currentLength;

    _lastModifTime = time;
}

void WaitingQueue::decrCurrentLength(double time)
{
    _averageLength += (time - _lastModifTime) * _currentLength;
    _currentLength--;

    _lastModifTime = time;
}

int WaitingQueue::currentLength() const
{
    return _currentLength;
}

WaitingQueue::~WaitingQueue()
{
}
