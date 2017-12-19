#ifndef TestHi_H
#define TestHi_H

#include "../CommandBase.h"

class TestHi : public CommandBase {
public:
	TestHi();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TestHi_H
