#ifndef TimedIntake_H
#define TimedIntake_H

#include "../CommandBase.h"
#include "WPILib.h"

class TimedIntake: public CommandBase
{
public:
	TimedIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
