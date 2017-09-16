#include "Simulation.h"


Simulation::Simulation()
{
	_time = 0;
}

void Simulation::addEvent(Event *evt)
{
	_eventQueue.addEvent(evt);
}

double Simulation::time() const
{
	return _time;
}
