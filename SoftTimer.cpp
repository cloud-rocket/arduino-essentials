/*
 * SoftTimer.cpp
 *
 *  Created on: 30 αιεπ 2012
 *      Author: Miro
 */

#include "SoftTimer.h"
#include "Log.h"
#include "Runtime.h"

#include <Arduino.h>

const uint8_t EVENT_TYPE_SOFT_TIMER = 20;


SoftTimer TIMER;

void SoftTimer::init() {
	RUNTIME.Attach(this);
}

void SoftTimer::Attach(TimerListener* listener, unsigned long timerPeriod) {

	listener->timerPeriod = timerPeriod;

	Event::Attach(listener);
}


void SoftTimer::Notify(uint16_t type) {

	if (!_listeners.isEmpty()) {
		for (_listeners.first(); !_listeners.isDone(); _listeners.next()) {


			// Check if client should be executed (internal_data1 used to store lastEventTime, option1 to store period)
			unsigned long now = millis();

			TimerListener* node = (TimerListener*) _listeners.currentItem();

			if (!node->lastTimestamp || now > node->lastTimestamp + node->timerPeriod) {

				node->onEvent(this, type);
				node->lastTimestamp = now;

				//DEBUG_PRINT(DEBUG_INFO,"Now=");
				//DEBUG_PRINTLN(DEBUG_INFO,now);
			}
		}
	}
}

void SoftTimer::onEvent(Event* o, uint16_t eventType, uint32_t param1, uint32_t param2) {
	Notify(EVENT_TYPE_SOFT_TIMER);
}
