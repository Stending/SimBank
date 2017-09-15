#ifndef RELEASE_H
#define RELEASE_H


#include "Event.h"

class Release : public Event{

	protected:
		Cashier* _cashier;
	public:
		Release();
		void process();
};

#endif
