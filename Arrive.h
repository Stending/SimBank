#ifndef ARRIVE_H
#define ARRIVE_H

#include "Event.h"

class Bank;
class Arrive : public Event{

	protected:
		Bank* _bank;
	public:
		Arrive();
		void process();
};

#endif
