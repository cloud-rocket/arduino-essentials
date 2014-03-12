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


const extern uint8_t EVENT_TYPE_DIGITAL_INPUT;

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
	
	uint8_t type() {return EVENT_TYPE_DIGITAL_INPUT;}

protected:
	void onEvent(Event* o, uint16_t eventType = 0, uint32_t param1 = 0, uint32_t param2 = 0);

private:
	uint8_t _pin;
	uint8_t _lastValue;
};

#endif /* DIGITALINPUTEVENT_H_ */
