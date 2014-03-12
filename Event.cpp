#include "Event.h"

#include "Log.h"
#include <Arduino.h>


Event::Event() {

#ifdef DEBUG
	_listeners.setPrinter(Serial);
#endif
}

void Event::Attach(EventListener* listener) {

	// Check if event already attached
	if (IsAttached(listener)) return;

	_listeners.push(listener);
}


byte Event::IsAttached(EventListener* listener) {

	if (!_listeners.isEmpty()) {

		for (_listeners.first(); !_listeners.isDone(); _listeners.next()) {

			if (_listeners.currentItem() == listener) {
				return 1;
			}
		}
	}

	return 0;
}


void Event::Detach(EventListener* listener) {


	_listeners.remove(listener);
}



void Event::Notify(uint16_t type) {

	if (!_listeners.isEmpty()) {

		for (_listeners.first(); !_listeners.isDone(); _listeners.next()) {

			_listeners.currentItem()->onEvent(this, type);

		}
	}
}
