#include "MecanumDrive.h"
#include "WPILib.h"
#include "Subsystems/MecanumDriveTrain.h"
#include "../PinEnums.h"



MecanumDrive::MecanumDrive()
: CommandBase("MecanumDrive")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time
void MecanumDrive::Initialize() {
	MecanumDriveTrain->MecanumDrive(M1, M2, M3, M4);
}

// Called repeatedly when this Command is scheduled to run
void MecanumDrive::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDrive::Interrupted() {

}
