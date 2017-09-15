#include "Event.h"

Event::Event(double _time)
{
    (*this)._time = _time;
}

double Event::time()
{
	return _time;
}
