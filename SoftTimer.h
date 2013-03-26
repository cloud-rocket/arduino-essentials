/*
 * SoftTimer.h
 *
 *  Created on: 30 June 2012
 *      Author: Miro
 */

#ifndef SOFTTIMER_H_
#define SOFTTIMER_H_

#include "Event.h"

class TimerListener : public EventListener {
public:
	TimerListener() : lastTimestamp(0) {}
private:
	unsigned long timerPeriod;
	unsigned long lastTimestamp;

	friend class SoftTimer;
};

class SoftTimer : public Event {

protected:
	void Notify();

};


#endif /* SOFTTIMER_H_ */
