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
	cout << this << "On s'occupe du client " << c << " et on sera libre au temps " << serviceEnd << endl;
	Release r(this, serviceEnd);
	_bank->addEvent(&r);
}

void Cashier::wait(){
	delete _currentCustomer;
	
	Customer* nextCustomer = _bank->nextCustomer();

	if(nextCustomer){
		serve(nextCustomer);
	}else{
		_currentCustomer = NULL;
	}
	
}


