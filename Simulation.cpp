#include "Simulation.h"


Simulation::Simulation(){
	_time = 0;
}

void Simulation::execute(){
	if(!_eventQueue.empty()){
		cout << "On traite un événement :" << endl;
		Event* e = _eventQueue.firstEvent();
		_eventQueue.removeFirstEvent();	

		_time = e->time();

		e->process();

		execute();
	}




}

void Simulation::addEvent(Event *evt){
	_eventQueue.addEvent(evt);
}

double Simulation::time(){
	return 0;
}
