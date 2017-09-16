#ifndef EVENT_H
#define EVENT_H
#include <string>



class Event
{
	protected :
		double _time;

	public :
        double time();
		Event(double _time);
		virtual void process() = 0;
		virtual std::string eventType() = 0;
};

#endif
