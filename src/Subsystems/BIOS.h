#ifndef BIOS_H
#define BIOS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BIOS: public Subsystem
{
private:
	Preferences* prefs;
	CANTalon* pCollectorMotor;
	CANTalon* pShooterMotorLeft;
	CANTalon* pShooterMotorRight;
	Timer* pTimer;
	DigitalInput* limitSwitch;
	Counter* counter;
	float fSpeed;
public:
	BIOS();
	float fIntakeSpeed;
	float fShootSpeed;
	float fKickerSpeed;
	float fAdjustSpeed;
	void Intake(float speed);
	void Shoot(float speed);
	void LowGoal();
	void StartTimer();
	double GetCurrentTime();
	void StopTimer();
	void InitDefaultCommand();
	float GetShootSpeed();
	float GetIntakeSpeed();
	float GetKickerSpeed();
	float GetAdjustSpeed();
	float StopShoot();
	float StopIntake();
	bool IsSwitchSet();
	void InitializeCounter();
};

#endif
