#include "WaitingQueue.h"	


		
WaitingQueue::WaitingQueue(int maxLength, double averageWaitingTime){
	_maxLength = maxLength;
	_averageWaitingTime = averageWaitingTime;
}

WaitingQueue::~WaitingQueue(){

}

int WaitingQueue::maxLength() const{
	return _maxLength;
}

double WaitingQueue::averageLength() const{
	return _averageLength;
}
double WaitingQueue::averageWaitingTime() const{
	return _averageWaitingTime;
}
bool WaitingQueue::isEmpty() const{
	return _customers.empty();
}

void WaitingQueue::add(Customer* customer){
	_customers.push_back(customer);
}
Customer* WaitingQueue::remove(){
	Customer* c = _customers.front();
	_customers.pop_front();
	return c;
}
