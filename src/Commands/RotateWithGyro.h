#ifndef RotateWithGyro_H
#define RotateWithGyro_H

#include "../CommandBase.h"
#include "WPILib.h"

class RotateWithGyro: public CommandBase
{
private:
	double refPoint;
	double degrees;
public:
	RotateWithGyro(double magnitude);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
