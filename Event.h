#ifndef EVENT_H
#define EVENT_H



class Event
{
	protected :
		double _time;
	public :
		Event(double _time);
		double time();
		virtual void process() = 0;
};

#endif
