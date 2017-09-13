#ifndef SIMULATION_H
#define SIMULATION_H
#include "Event.h"
class Simulation
{
	protected:
		double _time;
		Event* _events;
    public :
		Simulation();
    	void execute();
    	void add(Event *evt);
    	double time();
};

#endif
