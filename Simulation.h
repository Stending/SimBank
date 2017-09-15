#ifndef SIMULATION_H
#define SIMULATION_H
#include "Event.h"
#include "SortedEventQueue.h"
class Simulation
{
	protected:
		double _time;
		SortedEventQueue _eventQueue;
    public :
		Simulation();
    	void execute();
    	void addEvent(Event *evt);
    	double time();
};

#endif
