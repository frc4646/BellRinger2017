#include "RunRinger.h"
#include "WPILib.h"
#include "Subsystems/RingerSystem.h"
#include "../PinEnums.h"
#include "OI.h"
#include "CommandBase.h"

RunRinger::RunRinger():
	CommandBase("RingerSystem"){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(ringer.get());
}

// Called just before this Command runs the first time
void RunRinger::Initialize() {
	// Set ringer speed to 0.
	/*
	 * Just like the mecanum command, this also talks to a subsystem. But THIS subsystem is betterer,
	 * because it runs the ringer. VERY. QUICKLY. If we had a robot to test on, *ahem build* we could
	 * make it NOT run very quickly! :D
	 */
	ringer->SetRingerSpeed(0);


}

// Called repeatedly when this Command is scheduled to run
void RunRinger::Execute() {
	// If statement to control ringer based on trigger input.
	/*
	 * So this if/else combo runs our fantastic ringer method, provided by... *drumroll* THE RINGER
	 * SUBSYSTEM! *stereotypical child cheering sound* Basically this runs our actual ringer. Without
	 * this combo, we couldn't even run the ringer. Well, if we were missing the second part (the else
	 * statement), we would not be able to stop the ringer. Ever. Which would be unfortunate.
	 */
	// Set this to 0 for DS controls, 1 for gamepad controls.
	int robotmode = 1;
	if (robotmode == 0) {
		if (oi->getMechanismJoystick().GetTrigger()){
				// Set the ringer speed to 1.
				ringer->SetRingerSpeed((oi->getMechanismJoystick().GetThrottle() / 2));
			}
			// OTHERWISE...
			else {
				ringer->SetRingerSpeed(0);
			}
	}
	if (robotmode == 1) {
		if (oi->getLeftJoystick().GetRawButton(0)){
			ringer->SetRingerSpeed(0.25);
		} else if (oi->getLeftJoystick().GetRawButton(1)){
			ringer->SetRingerSpeed(0.4);
		} else if (oi->getLeftJoystick().GetRawButton(2)){
			ringer->SetRingerSpeed(0.75);
		} else if (oi->getLeftJoystick().GetRawButton(3)){
			ringer->SetRingerSpeed(1);
		}
		else {
			ringer->SetRingerSpeed(0);
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool RunRinger::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void RunRinger::End() {
	// Set the ringer speed to 0.
	/*
	 * This tells our ringer to stop if the robot is disabled. Cause that would be good.
	 */
	ringer->SetRingerSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunRinger::Interrupted() {

}
