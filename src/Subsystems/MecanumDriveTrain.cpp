#include <Subsystems/MecanumDriveTrain.h>
#include "../RobotMap.h"

MecanumDriveTrain::MecanumDriveTrain(MotorPin w1, MotorPin w2, MotorPin w3, MotorPin w4) :
	Subsystem("MecanumDriveTrain"),
	wheel1(w1),
	wheel2(w2),
	wheel3(w3),
	wheel4(w4),
	Gyro(),
	rb(wheel1, wheel2, wheel3, wheel4) {
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
	rb->MecanumDrive_Cartesian(movement.GetRawAxis(0) * -1.0, rotation.GetRawAxis(0) * -1.0, movement.GetRawAxis(1) * -1.0, GetHeading())
}

void MecanumDriveTrain::AutoDrive(double x, double y, double rot) {
	rb->MecanumDrive_Cartesian(x, rot, y, GetHeading());
}

double MecanumDriveTrain::GetHeading() {
	return -Gyro.GetAngle();
}

void MecanumDriveTrain::STAHP() {
	wheel1.Set(0.0);
	wheel2.Set(0.0);
	wheel3.Set(0.0);
	wheel4.Set(0.0);
}

void MecanumDriveTrain::Stop() {
	STAHP();
}
