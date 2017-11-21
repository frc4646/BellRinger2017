#ifndef RunXylo_H
#define RunXylo_H

#include "../CommandBase.h"

class RunXylo : public CommandBase {
public:
	RunXylo();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // RunXylo_H
