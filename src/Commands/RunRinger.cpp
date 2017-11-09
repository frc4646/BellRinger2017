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
	ringer->SetRingerSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void RunRinger::Execute() {
	if (oi->getMechanismJoystick().GetTrigger()){
		ringer->SetRingerSpeed(1);
	}
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
	ringer->SetRingerSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunRinger::Interrupted() {

}
