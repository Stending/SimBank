#ifndef RELEASE_H
#define RELEASE_H


#include "Event.h"

class Release : public Event{

	public:
		Release();
		void process();
};

#endif
