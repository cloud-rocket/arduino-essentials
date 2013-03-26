/*
 * DigitalInputEvent.cpp
 *
 *  Created on: 24 ���� 2013
 *      Author: Miro
 */

#include "DigitalInputEvent.h"
#include "Log.h"
#include "Runtime.h"

#include <Arduino.h>

DigitalInputEvent::DigitalInputEvent(): _lastValue(LOW) {


}

DigitalInputEvent::~DigitalInputEvent() {
	// TODO Auto-generated destructor stub
}

void DigitalInputEvent::init(uint8_t pin) {

	_pin = pin;

	pinMode(pin, INPUT);

	// Receive runtime events
	RUNTIME.Attach(this);

	LOG_PRINTLN(DEBUG_INFO, "DigitalInputEvent initialized");
}


void DigitalInputEvent::onEvent(Event* o) {

	uint8_t val = (uint8_t) digitalRead(_pin);

	if (val != _lastValue) {
		_lastValue = val;

		if (!_listeners.isEmpty()) {

			// Do callback
			for (_listeners.first(); !_listeners.isDone(); _listeners.next()) {

				if (val == HIGH) {
					((DigitalInputListener*)_listeners.currentItem())->onRising(this);
				} else {
					((DigitalInputListener*)_listeners.currentItem())->onFalling(this);
				}

			}
		}

	}
}


