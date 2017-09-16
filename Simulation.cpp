#include "Simulation.h"


Simulation::Simulation(){
	_time = 0;
}

void Simulation::execute(){
	if(!_eventQueue.empty()){
		cout << "On traite un événement :" << endl;
		Event* e = _eventQueue.firstEvent();
		cout << "ça passe" << endl;
		_eventQueue.removeFirstEvent();
		cout << "ça casse" << endl;
		cout << "L'evenement à lieu au temps t = " << e->time() << endl;

		_time = e->time();
		cout << "Il est actuellement t = " << _time << endl;
		e->process();
		cout << "Il reste " << _eventQueue.size() << " à dérouler." << endl;
		execute();
	}




}

void Simulation::addEvent(Event *evt){
	cout << "evt : " << evt <<endl;
	_eventQueue.addEvent(evt);
}

double Simulation::time(){
	return _time;
}
