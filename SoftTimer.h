/*
 * SoftTimer.h
 *
 *  Created on: 30 June 2012
 *      Author: Miro
 */

#ifndef SOFTTIMER_H_
#define SOFTTIMER_H_

#include "Event.h"

class TimerListener : public Event, public EventListener {
public:
	TimerListener() : lastTimestamp(0) {}

private:
	unsigned long timerPeriod;
	unsigned long lastTimestamp;

	friend class SoftTimer;
};

const extern uint8_t EVENT_TYPE_SOFT_TIMER;

extern class SoftTimer : public Event, public EventListener {

public:
	void init();
	void Attach(TimerListener* listener, unsigned long timerPeriod);

	uint8_t type() {return EVENT_TYPE_SOFT_TIMER;}


protected:
	void onEvent(Event* o, uint16_t eventType = 0, uint32_t param1 = 0, uint32_t param2 = 0);
	void Notify(uint16_t type);

} TIMER;


#endif /* SOFTTIMER_H_ */
