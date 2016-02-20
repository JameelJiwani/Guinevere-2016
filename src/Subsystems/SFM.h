#ifndef SFM_H
#define SFM_H

#include "Commands/Subsystem.h"

#include "WPILib.h"

class SFM: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid* sfm;
public:
	Compressor* compressor;
	SFM();
	void InitDefaultCommand();
	void StartCompressor();
	void SetForward();
	void SetReverse();
};

#endif
