/*
 * StateMachine.h
 *
 *  Created on: 20 αταψ 2014
 *      Author: Miro
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include <stdint.h>

enum SM_COMMAND {
	SM_DO_NOTHING,
	SM_NEXT_STATE,
	SM_PREV_STATE,
};

#define SM_TOTAL_MODES 4
#define SM_TOTAL_STATES 5
const uint8_t UNDEFINED_MODESTATE = 255;

#define DECLARE_STATE(STATE_CONTAINER, STATE_NAME) \
		SM_COMMAND STATE_NAME(uint16_t eventType, uint32_t param1, uint32_t param2); \
		static SM_COMMAND stat_##STATE_NAME(STATE_CONTAINER* container, uint16_t eventType, uint32_t param1, uint32_t param2) { \
			return container->STATE_NAME(eventType, param1, param2); \
		}


#define IMPLEMENT_STATE(STATE_CONTAINER, STATE_NAME) \
		SM_COMMAND STATE_CONTAINER::STATE_NAME(uint16_t eventType, uint32_t param1, uint32_t param2)


#define ADD_STATE(STATE_CONTAINER, STATE_NAME) \
		STATE_CONTAINER.addState((StateMachineMode::STATE_FUNCTION_STATIC_T)stat_##STATE_NAME);

class StateMachine;

class StateMachineMode {
public:
	void init(StateMachine& stateMachine);

	// Default begin/end implementations for each mode
	virtual SM_COMMAND begin() {return SM_DO_NOTHING; };
	static SM_COMMAND stat_begin(StateMachineMode* container) {
		return container->begin();
	}

	virtual SM_COMMAND end() {return SM_DO_NOTHING; }
	static SM_COMMAND stat_end(StateMachineMode* container) {
		return container->end();
	}

	// State function prototypes
	typedef SM_COMMAND (StateMachineMode::*BEGINEND_FUNCTION_T)();
	typedef SM_COMMAND (*BEGINEND_FUNCTION_STATIC_T)(StateMachineMode*);

	typedef SM_COMMAND (StateMachineMode::*STATE_FUNCTION_T)(uint16_t, uint32_t, uint32_t);
	typedef SM_COMMAND (*STATE_FUNCTION_STATIC_T)(StateMachineMode*, uint16_t, uint32_t, uint32_t);


	virtual void addStates(StateMachine& stateMachine) = 0;

	virtual SM_COMMAND stub(uint16_t eventType, uint32_t param1, uint32_t param2) {	return SM_DO_NOTHING;}


protected:
	friend class StateMachine;
};

class StateMachine {
public:
	StateMachine();
	//virtual ~StateMachine();

	// Add next mode (should be called in order of modes)
	uint8_t addMode(StateMachineMode& mode);

	// Add next state to the current mode
	uint8_t addState(StateMachineMode::STATE_FUNCTION_STATIC_T state);

	bool setMode(StateMachineMode& mode, uint8_t state = UNDEFINED_MODESTATE);
	bool setMode(uint8_t mode, uint8_t state = UNDEFINED_MODESTATE);
	bool setState(uint8_t state);

	// Start state machine execution - call current mode/state init functions
	void begin();

	// Event function is delivered to the current mode/state
	void onEvent(uint16_t eventType, uint32_t param1, uint32_t param2);


private:
	uint8_t _currMode;
	uint8_t _currState[SM_TOTAL_MODES];

	StateMachineMode* _modesMap[SM_TOTAL_MODES];
	StateMachineMode::STATE_FUNCTION_STATIC_T _statesMap[SM_TOTAL_MODES][SM_TOTAL_STATES];

	uint8_t _totalModes;
	uint8_t _totalStates[SM_TOTAL_MODES];
};

#endif /* STATEMACHINE_H_ */
