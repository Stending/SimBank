#include "SortedEventQueue.h"

SortedEventQueue::SortedEventQueue(){
	
}

void SortedEventQueue::addEvent(Event* e){
	

	std::deque<Event*>::iterator it;
	for (it=_queue.begin(); it!=_queue.end(); ++it){
    	if(e->time() < (*it)->time()){
			it--;
			_queue.insert(it, e);
			break;
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

void SortedEventQueue::printEvents(){

	std::deque<Event*>::iterator it;

	for (it=_queue.begin(); it!=_queue.end(); ++it){
    	std::cout << ' ' << (*it)->time();
	}
}
