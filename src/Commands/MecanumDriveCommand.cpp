#include <Commands/MecanumDriveCommand.h>
#include <Subsystems/MecanumDriveTrain.h>
#include "WPILib.h"
#include "../PinEnums.h"
#include "OI.h"

MecanumDriveCommand::MecanumDriveCommand() :
	CommandBase("MecanumDriveTrain") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(mecanum.get());
}

// Called just before this Command runs the first time
void MecanumDriveCommand::Initialize() {
	// Tell mecanum to stop.
	/*
	 * This line basically tells mecanum to run it's "Stop()" method with no arguments.
	 */
	mecanum->Stop();
	// Reset the gyro.
	/*
	 * This line also talks to mecanum, but it tells it to run it's "ResetGyro()" method with no arguments.
	 */
	mecanum->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void MecanumDriveCommand::Execute() {
	// Tell mecanum joydrive method to run with joysticks.
	/*
	 * Like the above commands, this also talks to the mecanum subsystem. This time it actually
	 * runs the drivetrain by passing the joysticks (provided by the OI subsystem) as arguments.
	 */


	// DS Mode:
	mecanum->JoyDrive(oi->getLeftJoystick(), oi->getRightJoystick(), 0, -1);

	// Gamepad Mode:
	//mecanum->JoyDrive(oi->getLeftJoystick(), oi->getLeftJoystick(), 1, 0.75);


	// Put the gyro heading on smart dashboard.
	/*
	 * This time, we talk to the frc class, then the SmartDashboard "subclass", and then run the PutNumber
	 * method.
	 */
	frc::SmartDashboard::PutNumber("Heading", mecanum->GetHeading());
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDriveCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void MecanumDriveCommand::End() {
	// Tell mecanum to stop when the robot is disabled in case the joysticks are tilted when we disable.
	/*
	 * I kinda told you about this above. Look up.
	 */
	mecanum->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDriveCommand::Interrupted() {
	// Ditto the comment in End.
	/*
	 * Seriously, look up!
	 */
	End();
}
