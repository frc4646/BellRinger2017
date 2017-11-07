#ifndef RingerSystem_H
#define RingerSystem_H


#include "WPILib.h"
#include "PinEnums.h"
#include "Spark.h"
#include <Commands/Subsystem.h>
class RingerSystem : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Spark ringerMotor;

public:
	RingerSystem(MotorPin r);
	void InitDefaultCommand();
	void SetRingerSpeed(double speed);
};

#endif  // RingerSystem_H
