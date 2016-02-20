#ifndef AdjustShoot_H
#define AdjustShoot_H

#include "../CommandBase.h"
#include "WPILib.h"

class AdjustShoot: public CommandBase
{
public:
	AdjustShoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
