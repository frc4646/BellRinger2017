#ifndef RunRinger_H
#define RunRinger_H

#include "../CommandBase.h"
#include "WPILib.h"

class RunRinger: public CommandBase {
public:
	RunRinger();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunRinger_H
