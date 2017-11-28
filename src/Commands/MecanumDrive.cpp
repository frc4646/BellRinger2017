#include "MecanumDrive.h"
#include <Subsystems/MecanumDriveTrain.h>
#include "WPILib.h"
#include "../PinEnums.h"
#include "OI.h"

MecanumDrive::MecanumDrive() :
	CommandBase("MecanumDriveTrain") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(mecanum.get());
}

// Called just before this Command runs the first time
void MecanumDrive::Initialize() {
	// Tell mecanum to stop.
	mecanum->Stop();
	// Reset the gyro.
	mecanum->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void MecanumDrive::Execute() {
	// Tell mecanum joydrive method to run with joysticks.
	mecanum->JoyDrive(oi->getLeftJoystick(), oi->getRightJoystick());
	// Put the gyro heading on smart dashboard.
	frc::SmartDashboard::PutNumber("Heading", mecanum->GetHeading());
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumDrive::End() {
	// Tell mecanum to stop when the robot is disabled in case the joysticks are tilted when we disable.
	mecanum->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDrive::Interrupted() {
	// Ditto the comment in End.
	End();
}
