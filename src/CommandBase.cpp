#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/MecanumDriveTrain.h"
#include "HardwareConfiguration.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
//		std::make_unique<ExampleSubsystem>();

std::unique_ptr<OI> CommandBase::oi = NULL;
std::unique_ptr<MecanumDriveTrain> CommandBase::mecanum = NULL;

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}

void CommandBase::init() {
	mecanum.reset(new MecanumDriveTrain(frontLeft, frontRight, backLeft, backRight));
	oi.reset(new OI());
}
