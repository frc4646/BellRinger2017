#include "OI.h"

#include <WPILib.h>

OI::OI() :
	left(0),
	right(1),
	mechanism(2) {
	// Process operator interface input here.
}

Joystick& OI::getLeftJoystick() {
	return left;
}

Joystick& OI::getRightJoystick() {
	return right;
}

Joystick& OI::getMechanismJoystick() {
	return mechanism;
}
