#ifndef MecanumDriveTrain_H
#define MecanumDriveTrain_H

#include "WPILib.h"
#include "PinEnums.h"
#include "Spark.h"
#include "Commands/MecanumDrive.h"

#include <Commands/Subsystem.h>

class MecanumDriveTrain : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark wheel1;
	Spark wheel2;
	Spark wheel3;
	Spark wheel4;
	RobotDrive *rb;

public:
	MecanumDriveTrain(MotorPin w1, MotorPin w2, MotorPin w3, MotorPin w4);
	void InitDefaultCommand();
	void JoyDrive(Joystick &rotation, Joystick &movement);
	void AutoDrive(double x, double y, double rot);
	double GetHeading();
	void STAHP();
	void Stop();
};

#endif  // MecanumDrive_H
