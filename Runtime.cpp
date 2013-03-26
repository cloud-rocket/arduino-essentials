/*
 * SoftTimer.cpp
 *
 *  Created on: 30 αιεπ 2012
 *      Author: Miro
 */

#include "Runtime.h"
#include "Log.h"

#include <Arduino.h>


Runtime RUNTIME;

void Runtime::exec() {
	while (1) {
		Notify();
	}
}


