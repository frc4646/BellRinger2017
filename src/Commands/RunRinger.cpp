#include "RunRinger.h"
#include "WPILib.h"
#include "Subsystems/RingerSystem.h"
#include "../PinEnums.h"
#include "OI.h"
#include "CommandBase.h"

RunRinger::RunRinger():
	CommandBase("RingerSystem"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(ringer.get());
}

// Called just before this Command runs the first time
void RunRinger::Initialize() {
	// Set ringer speed to 0.
	ringer->SetRingerSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void RunRinger::Execute() {
	// If statement to control ringer based on trigger input.
	if (oi->getMechanismJoystick().GetTrigger()){
		// Set the ringer speed to 1.
		ringer->SetRingerSpeed(1);
	}
	// OTHERWISE...
	else{
		ringer->SetRingerSpeed(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RunRinger::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunRinger::End() {
	// Set the ringer speed to 0.
	ringer->SetRingerSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunRinger::Interrupted() {

}
