#ifndef TimedShoot_H
#define TimedShoot_H

#include "../CommandBase.h"
#include "WPILib.h"

class TimedShoot: public CommandBase
{
public:
	TimedShoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
