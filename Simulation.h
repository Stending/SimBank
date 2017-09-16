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
    	virtual void execute() = 0;
    	void addEvent(Event *evt);
    	double time() const;
};

#endif
