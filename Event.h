#ifndef _EVENT_H
#define _EVENT_H

#include "StackArray.h"

class Event;

class EventListener {
protected:
	virtual void onEvent(Event* o) = 0;

	friend class Event;
};

class Event {

public:

	Event();

	void Attach(EventListener* listener);
	void Detach(EventListener* listener);
	byte IsAttached(EventListener* listener);

protected:
	virtual void Notify();

	StackArray<EventListener*> _listeners;
};

#endif
