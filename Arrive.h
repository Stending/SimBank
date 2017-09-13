#ifndef ARRIVE_H
#define ARRIVE_H

#include "Event.h"

class Arrive : public Event{

	public:
		Arrive();
		void process();
};

#endif
