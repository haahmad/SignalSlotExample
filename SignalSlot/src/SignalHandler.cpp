/*
 * SignalHandler.cpp
 *
 *  Created on: Oct 27, 2013
 *      Author: hasahm
 */

#include "SignalHandler.hpp"

SignalHandler::SignalHandler(SignalSlot *jsContext) {
	m_jsContext = jsContext;
	m_led = new bb::device::Led(this);
	bool result = connect(m_led, SIGNAL(activeChanged(bool value)), this, SLOT(handleSignal(bool value)));
}

SignalHandler::~SignalHandler() {
	delete m_jsContext;
	delete m_led;
}

void SignalHandler::handleSignal(bool value) {
	m_jsContext->NotifyEvent("signalCaught!");
}

