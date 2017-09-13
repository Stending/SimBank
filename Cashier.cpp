#include "Cashier.h"

		/*double _averageServiceTime;
		Customer _currentCustomer;
		double _occupationRate;
		Bank* _bank;*/

void Cashie::Cashier(double averageServiceTime, Bank *bank){
	_averageServiceTime = averageServiceTime;
	_bank = bank;
}

double Cashier::averageServiceTime(){
	return _averageServiceTime;
}

double Cashier::occupationRate(){
	return _occupationRate;
}

void Cashier::serve(Customer){

}

void Cashier::wait(){

}

bool Cashier::isFree(){
	return _currentCustomer == NULL;
}

Bank* Cashier::bank(){

}
