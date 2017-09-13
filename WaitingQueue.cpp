#include "WaitingQueue.h"	


		
WaitingQueue::WaitingQueue(int maxLength, averageWaitingTime){
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
	retun _averageWaitingTime;
}
bool WaitingQueue::isEmpty() const{
	return _customers.empty();
}

void WaitingQueue::add(Customer customer){
	_customers.push_front(customer);
}
Customer WaitingQueue::remove(){
	return _customers.pop_back();
}
