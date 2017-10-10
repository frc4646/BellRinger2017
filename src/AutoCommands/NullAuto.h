#ifndef NullAuto_H
#define NullAuto_H

#include "../CommandBase.h"

class NullAuto : public CommandBase {
public:
	NullAuto();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // NullAuto_H
