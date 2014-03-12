/*
 * SoftTimer.cpp
 *
 *  Created on: 30 αιεπ 2012
 *      Author: Miro
 */

#include "Runtime.h"
#include "Log.h"

#include <Arduino.h>

const uint8_t EVENT_TYPE_RUNTIME = 10;

Runtime RUNTIME;

void Runtime::exec() {
	while (1) {
		Notify(EVENT_TYPE_RUNTIME);
	}
}


