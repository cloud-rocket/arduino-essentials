/*
 * SoftTimer.h
 *
 *  Created on: 30 June 2012
 *      Author: Miro
 */

#ifndef RUNTIME_H_
#define RUNTIME_H_

#include "Event.h"

const extern uint8_t EVENT_TYPE_RUNTIME;

extern class Runtime : public Event {

public:

	void exec();
	
	uint8_t type() {return EVENT_TYPE_RUNTIME;}

} RUNTIME;


#endif /* RUNTIME_H_ */
