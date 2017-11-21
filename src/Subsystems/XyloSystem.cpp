#include <Subsystems/XyloSystem.h>
#include "../RobotMap.h"
#include "../PinEnums.h"
#include <Commands/RunXylo.h>

XyloSystem::XyloSystem(MotorPin x) :
	Subsystem("XyloSystem"),
	xyloMotor(x)
{
	// do nothing
}

void XyloSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RunXylo());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void XyloSystem::SetXyloSpeed(float speed) {
	xyloMotor.SetSpeed(speed);
}
