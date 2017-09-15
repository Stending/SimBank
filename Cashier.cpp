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

void Cashier::serve(Customer* c){
	double serviceTime = _averageServiceTime; 	//TODO utiliser Poisson pour générer une durée
	double serviceEnd = _bank->realTime() + serviceTime;

	_currentCustomer = c;
	//Release r(this, serviceEnd);
	//bank->AddEvent(&r);
}

void Cashier::wait(){
	//TODO
}


