#include "Simulation.h"


Simulation::Simulation(){
	_time = 0;
}

void Simulation::execute(){
	if(!_eventQueue.empty()){
		Event* e = _eventQueue.firstEvent();
		_eventQueue.removeFirstEvent();	

		e->process();

		execute();
	}
}

void Simulation::add(Event *evt){

}

double Simulation::time(){
	return 0;
}
