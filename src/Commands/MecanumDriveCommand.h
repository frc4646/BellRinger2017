#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class MecanumDriveCommand: public CommandBase {
public:
	MecanumDriveCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // MecanumDrive_H
