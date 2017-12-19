#include "TestHi.h"

TestHi::TestHi() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	//hi
}

// Called just before this Command runs the first time
void TestHi::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TestHi::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool TestHi::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TestHi::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TestHi::Interrupted() {

}
