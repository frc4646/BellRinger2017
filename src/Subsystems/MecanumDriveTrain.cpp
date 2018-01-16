#include <Commands/MecanumDriveCommand.h>
#include <Subsystems/MecanumDriveTrain.h>
#include "../RobotMap.h"

MecanumDriveTrain::MecanumDriveTrain(MotorPin w1, MotorPin w2, MotorPin w3, MotorPin w4) :
	Subsystem("MecanumDriveTrain"),
	frontleftwheel(w1),
	frontrightwheel(w2),
	backleftwheel(w3),
	backrightwheel(w4),
	gyro(),

	robotdrive(frontleftwheel, frontrightwheel, backleftwheel, backrightwheel)
{
	gyro.Calibrate();
	backleftwheel.SetInverted(true);
	//backrightwheel.SetInverted(true);
}

void MecanumDriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MecanumDriveCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void MecanumDriveTrain::JoyDrive(Joystick& rotation, Joystick& movement, int mode, int speed) {
	robotdrive.DriveCartesian(rotation.GetRawAxis(0) * speed, rotation.GetRawAxis(1) * speed, movement.GetRawAxis(0) * speed, GetHeading());
}

void MecanumDriveTrain::AutoDrive(double x, double y, double rot) {
	robotdrive.DriveCartesian(x, rot, y, GetHeading());
}

void MecanumDriveTrain::DriveInDirection(double speed, double theta) {
	robotdrive.DrivePolar(speed, theta, GetHeading());
}

double MecanumDriveTrain::GetHeading() {
	return gyro.GetAngle();
}

void MecanumDriveTrain::ResetGyro() {
	gyro.Reset();
}

void MecanumDriveTrain::Stop() {
	frontleftwheel.Set(0.0);
	frontrightwheel.Set(0.0);
	backleftwheel.Set(0.0);
	backrightwheel.Set(0.0);
}
