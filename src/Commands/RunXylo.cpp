#include "RunXylo.h"
#include "WPILib.h"
#include "Subsystems/XyloSystem.h"
#include "../PinEnums.h"
#include "OI.h"
#include "CommandBase.h"

RunXylo::RunXylo():
	CommandBase("XyloSystem"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(xylo.get());
}


// Called just before this Command runs the first time
void RunXylo::Initialize() {
	xylo->SetXyloSpeed(0);
}

// Called repeatedly when this Command is scheduled to run
void RunXylo::Execute() {
	if (oi->getMechanismJoystick().GetRawButton(2)){
		xylo->SetXyloSpeed(1);
	}
	else{
		xylo->SetXyloSpeed(0);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RunXylo::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunXylo::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunXylo::Interrupted() {

}
