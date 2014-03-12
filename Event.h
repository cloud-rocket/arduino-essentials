#ifndef _EVENT_H
#define _EVENT_H

#include "StackArray.h"

class Event;

class EventListener {
protected:
	virtual void onEvent(Event* o, uint16_t eventType, uint32_t param1 = 0, uint32_t param2 = 0) = 0;

	friend class Event;
};

class Event {

public:

	Event();
	
	virtual uint8_t type() = 0;
	
	void Attach(EventListener* listener);
	void Detach(EventListener* listener);
	byte IsAttached(EventListener* listener);

protected:
	virtual void Notify(uint16_t type);

	StackArray<EventListener*> _listeners;
};

#endif
