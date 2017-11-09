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
	mecanum->Stop();
	mecanum->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void MecanumDrive::Execute() {
	mecanum->JoyDrive(oi->getLeftJoystick(), oi->getRightJoystick());
	frc::SmartDashboard::PutNumber("Heading", mecanum->GetHeading());
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDrive::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumDrive::End() {
	mecanum->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDrive::Interrupted() {
	End();
}
