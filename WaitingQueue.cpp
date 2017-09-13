#include "WaitingQueue.h"	



deque<Customer> _customers;
		int _maxLength;
		double _averageLength;
		double _averageWaitingTime;
		
WaitingQueue::WaitingQueue(int maxLength, averageWaitingTime){
	_maxLength = maxLength;
	_averageWaitingTime = averageWaitingTime;
}

WaitingQueue::~WaitingQueue(){

}

int WaitingQueue::maxLength(){
	return _maxLength;
}

double WaitingQueue::averageLength(){
	return _averageLength;
}
double WaitingQueue::averageWaitingTime(){
	retun _averageWaitingTime;
}
void WaitingQueue::add(Customer customer){
	_customers.push_front(customer);
}
Customer WaitingQueue::remove(){
	return _customers.pop_back();
}
bool WaitingQueue::isEmpty(){
	return _customers.empty();
}
