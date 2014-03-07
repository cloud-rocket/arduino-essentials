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

extern class SoftTimer : public Event, public EventListener {

public:
	void init();
	void Attach(TimerListener* listener, unsigned long timerPeriod);


protected:
	void onEvent(Event* o);
	void Notify();

} TIMER;


#endif /* SOFTTIMER_H_ */
