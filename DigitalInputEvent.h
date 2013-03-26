/*
 * DigitalInputEvent.h
 *
 *  Created on: 24 במרס 2013
 *      Author: Miro
 */

#ifndef DIGITALINPUTEVENT_H_
#define DIGITALINPUTEVENT_H_

#include "Event.h"

class DigitalInputEvent;

class DigitalInputListener : public EventListener {
protected:
	virtual void onRising(DigitalInputEvent* o) = 0;
	virtual void onFalling(DigitalInputEvent* o) = 0;

	friend class DigitalInputEvent;

	// We don't use original event callback
	//void onEvent(Event* o) {}

};


class DigitalInputEvent: public Event , public EventListener {
public:
	DigitalInputEvent();
	virtual ~DigitalInputEvent();

	void init(uint8_t pin);

protected:
	void onEvent(Event* o);

private:
	uint8_t _pin;
	uint8_t _lastValue;
};

#endif /* DIGITALINPUTEVENT_H_ */
