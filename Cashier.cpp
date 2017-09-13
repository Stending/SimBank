#include "Cashier.h"

Cashier::Cashier(double averageServiceTime, Bank *bank){
	_averageServiceTime = averageServiceTime;
	_bank = bank;
}

double Cashier::averageServiceTime() const{
	return _averageServiceTime;
}

double Cashier::occupationRate() const{
	return _occupationRate;
}

bool Cashier::isFree() const{
	return _currentCustomer == NULL;
}

Bank* Cashier::bank() const{
	return _bank;
}

void Cashier::serve(Customer){
 	//TODO
}

void Cashier::wait(){
	//TODO
}


