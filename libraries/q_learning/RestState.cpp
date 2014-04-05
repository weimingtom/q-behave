/*
 * RestState.cpp
 *
 *  Created on: Apr 4, 2014
 *      Author: marek
 */
#ifndef _TEST_
#include <Arduino.h>
#else
#include "mock_arduino.h"
#endif

#include "RestState.h"

namespace q_learning {

RestState::RestState() {

}

RestState::~RestState() {
}

char* RestState::getStateName(){
	return "rest";
}

State* RestState::switchTo(State* state){
#ifdef _INFO_
	char myConcatenation[80];
	sprintf(myConcatenation,"[INFO] switch from state %s to state %s ",this->getStateName(),state->getStateName());
	Serial.write(myConcatenation);
#endif
	if (this!=state){
		this->deactivate();
		state->activate();
	}
	return state;
}

void RestState::activate(){
	//do nothing
}

void RestState::deactivate(){
	//do nothing
}

} /* namespace q_learning */
