#include <Subsystems/MecanumDriveTrain.h>
#include "../RobotMap.h"

MecanumDriveTrain::MecanumDriveTrain(MotorPin w1, MotorPin w2, MotorPin w3, MotorPin w4) :
	Subsystem("MecanumDriveTrain"),
	frontleftwheel(w1),
	frontrightwheel(w2),
	backrightwheel(w3),
	backrightwheel(w4),
	Gyro(),
	robotdrive(frontleftwheel, frontrightwheel, backrightwheel, backrightwheel) {
	Gyro.Calibrate();
}

void MecanumDriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new MecanumDrive());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void MecanumDriveTrain::JoyDrive(Joystick &rotation, Joystick &movement) {
	robotdrive->MecanumDrive_Cartesian(movement.GetRawAxis(0) * -1.0, rotation.GetRawAxis(0) * -1.0, movement.GetRawAxis(1) * -1.0, GetHeading())
}

void MecanumDriveTrain::AutoDrive(double x, double y, double rot) {
	robotdrive->MecanumDrive_Cartesian(x, rot, y, GetHeading());
}

void MecanumDriveTrain::DriveInDirection(double speed, double theta) {
	robotdrive->MecanumDrive_Polar(speed, theta, GetHeading());
}

double MecanumDriveTrain::GetHeading() {
	return -Gyro.GetAngle();
}

void MecanumDriveTrain::STAHP() {
	frontleftwheel.Set(0.0);
	frontrightwheel.Set(0.0);
	backleftwheel.Set(0.0);
	backrightwheel.Set(0.0);
}

void MecanumDriveTrain::Stop() {
	STAHP();
}
