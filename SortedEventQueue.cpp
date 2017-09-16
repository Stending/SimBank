#include "SortedEventQueue.h"

SortedEventQueue::SortedEventQueue()
{
}

void SortedEventQueue::addEvent(Event* e)
{
    bool notAdded = true;

	if(_queue.empty())
	{
		_queue.push_front(e);
	}
	else
	{
		std::deque<Event*>::iterator it;

		for (it=_queue.begin(); it!=_queue.end(); it++)
		{
	    	if(e->time() < (*it)->time())
	    	{
                notAdded = false;
				_queue.insert(it, e);
				break;
			}
		}

		if(notAdded)
		{
            _queue.push_back(e);
		}
	}
}

Event* SortedEventQueue::firstEvent(){
	return _queue.front();
}

void SortedEventQueue::removeFirstEvent(){
	_queue.pop_front();
}

bool SortedEventQueue::empty(){
	return _queue.empty();
}

int SortedEventQueue::size(){
	return _queue.size();
}

void SortedEventQueue::printEvents(){

	std::deque<Event*>::iterator it;

	for (it=_queue.begin(); it!=_queue.end(); ++it){
    	std::cout << ' ' << (*it)->time();
	}
}
