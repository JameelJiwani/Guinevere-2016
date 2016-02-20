#ifndef StartCompressor_H
#define StartCompressor_H

#include "../CommandBase.h"
#include "WPILib.h"

class StartCompressor: public CommandBase
{
public:
	StartCompressor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
