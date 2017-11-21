#ifndef XyloSystem_H
#define XyloSystem_H


#include "WPILib.h"
#include "PinEnums.h"
#include "Spark.h"
#include <Commands/Subsystem.h>

class XyloSystem : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark xyloMotor;

public:
	XyloSystem(MotorPin x);
	void InitDefaultCommand();
	void SetXyloSpeed(float speed);
};

#endif  // XyloSystem_H
