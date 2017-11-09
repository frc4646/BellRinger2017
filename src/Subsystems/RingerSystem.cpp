#include <Subsystems/RingerSystem.h>
#include "../RobotMap.h"
#include "../PinEnums.h"
#include <Commands/RunRinger.h>

RingerSystem::RingerSystem(MotorPin r) :
	Subsystem("RingerSystem"),
	ringerMotor(r)
{
	// do nothing
}
void RingerSystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new RunRinger());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void RingerSystem::SetRingerSpeed(float speed) {
	ringerMotor.Set(speed);
}

