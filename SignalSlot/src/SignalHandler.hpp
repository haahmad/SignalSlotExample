/*
 * SignalHandler.hpp
 *
 *  Created on: Oct 27, 2013
 *      Author: hasahm
 */

#ifndef SIGNALHANDLER_HPP_
#define SIGNALHANDLER_HPP_
#include <QObject>
#include "SignalSlotJS.hpp"
#include <bb/device/Led>

class SignalHandler : public QObject {
	Q_OBJECT
public:
	SignalHandler(SignalSlot *jsContext);
	virtual ~SignalHandler();
public Q_SLOTS:
	void handleSignal(bool value);
private:
	SignalSlot *m_jsContext;
	bb::device::Led *m_led;
};

#endif /* SIGNALHANDLER_HPP_ */
