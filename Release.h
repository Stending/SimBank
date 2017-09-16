#ifndef RELEASE_H
#define RELEASE_H


#include "Event.h"
#include "Cashier.h"

#include <string>

class Cashier;

class Release : public Event{

	protected:
		Cashier* _cashier;
	public:
		Release(Cashier*, double);
		std::string eventType();
		void process();
};

#endif
