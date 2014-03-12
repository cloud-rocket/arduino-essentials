#include <Arduino.h>

#include <ctype.h>
#include <ArduinoEssentials.h>
#include <StateMachine.h>


StateMachine stateMachine;

// MODE A

class ModeA : public StateMachineMode {
	DECLARE_STATE(ModeA, State1);
	DECLARE_STATE(ModeA, EndlessLoop);

	BEGIN_STATES_REGISTRATION
		ADD_STATE(stateMachine, State1);
		ADD_STATE(stateMachine, EndlessLoop);
	END_STATES_REGISTRATION
};


SM_COMMAND ModeA::State1(uint16_t eventType, uint32_t param1, uint32_t param2) {
	Serial.println("in State1");

	return SM_NEXT_STATE;
}

SM_COMMAND ModeA::EndlessLoop(uint16_t eventType, uint32_t param1, uint32_t param2) {
	Serial.println("in EndlessLoop");

	while(1)	;

	return SM_DO_NOTHING;
}


ModeA modeA;


// MODE B


class ModeB : public StateMachineMode {
	DECLARE_STATE(ModeB, StateOfB1);
	DECLARE_STATE(ModeB, StateOfB2);

	BEGIN_STATES_REGISTRATION
		ADD_STATE(stateMachine, StateOfB1);
		ADD_STATE(stateMachine, StateOfB2);
	END_STATES_REGISTRATION

public:
	void begin();
	void end();


};


SM_COMMAND ModeB::StateOfB1(uint16_t eventType, uint32_t param1, uint32_t param2) {
	Serial.println("in StateOfB1");

	return SM_NEXT_STATE;
}

SM_COMMAND ModeB::StateOfB2(uint16_t eventType, uint32_t param1, uint32_t param2) {
	Serial.println("in StateOfB2");

	stateMachine.setMode(modeA);

	return SM_DO_NOTHING;
}

void ModeB::begin() {
	Serial.println("ModeB::begin");
}

void ModeB::end() {
	Serial.println("ModeB::end");
}


ModeB modeB;



void setup() {

	Serial.begin(115200);
	Serial.println("Initializing State Machine:");

	modeA.init(stateMachine);
	modeB.init(stateMachine);

	RUNTIME.Attach(&stateMachine);
	
	stateMachine.setMode(modeB);
	
	Serial.println("State Machine initialized!");
}



void loop() {
	RUNTIME.exec();
}

int main(void) {

	init();
	setup();

	while (true) {
		loop();
	}
}
