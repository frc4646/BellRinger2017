#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/MecanumDriveTrain.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
std::unique_ptr<ExampleSubsystem> CommandBase::exampleSubsystem =
		std::make_unique<ExampleSubsystem>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();
std::unique_ptr<MecanumDriveTrain> CommandBase::mecanum = std::make_unique<MecanumDriveTrain>();

CommandBase::CommandBase(const std::string &name) :
		frc::Command(name) {

}
