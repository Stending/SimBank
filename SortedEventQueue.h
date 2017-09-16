#ifndef SORTEDEVENTQUEUE_H
#define SORTEDEVENTQUEUE_H

#include <iostream>
#include <deque>
#include "Event.h"
using namespace std;

class SortedEventQueue {

	protected :
		deque<Event*> _queue;
	public :
		SortedEventQueue();
		void addEvent(Event*);
		Event* firstEvent();
		void removeFirstEvent();
		bool empty();
		int size();
		void printEvents();
		

};

#endif
