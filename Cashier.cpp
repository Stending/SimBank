#include "Cashier.h"

Cashier::Cashier(double averageServiceTime, Bank *bank){
	_averageServiceTime = averageServiceTime;
	_bank = bank;
	_isFree = true;
}

double Cashier::averageServiceTime() const{
	return _averageServiceTime;
}

double Cashier::occupationRate() const{
	return _occupationRate;
}

bool Cashier::isFree() const{
	return _isFree;
}

Bank* Cashier::bank() const{
	return _bank;
}

void Cashier::serve(Customer* c){
	double serviceTime = _averageServiceTime; 	//TODO utiliser Poisson pour générer une durée
	double serviceEnd = _bank->time() + serviceTime;
	cout << "Au même ou le client sert, il voit que la bank est à t = " << _bank->time() << endl;
	_currentCustomer = c;
	_isFree = false;
	cout << this << "On s'occupe du client " << c << " et on sera libre au temps " << serviceEnd << endl;
	Release *r = new Release(this, serviceEnd);
	_bank->addEvent(r);
}

void Cashier::wait(){
    delete _currentCustomer;


	Customer* nextCustomer = _bank->nextCustomer();

	if(nextCustomer){
	cout << "Quelqu'un dans la file" << endl;
		serve(nextCustomer);
	}else{

	cout << "Personne dans la file dans la file" << endl;
		_currentCustomer = NULL;
		_isFree = true;
	}

}


