#ifndef OI_H
#define OI_H

#include "Joystick.h"

class OI {
private:
	Joystick left;
	Joystick right;
	Joystick mechanism;
public:
	OI();
	Joystick& getLeftJoystick();
	Joystick& getRightJoystick();
	Joystick& getMechanismJoystick();
};

#endif  // OI_H
