#include "NullAuto.h"

NullAuto::NullAuto() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void NullAuto::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void NullAuto::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool NullAuto::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void NullAuto::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void NullAuto::Interrupted() {
	End();
}
