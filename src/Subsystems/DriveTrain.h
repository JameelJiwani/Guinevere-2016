#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
private:
	RobotDrive* pRobot;
	DigitalInput* pDipSwitchOne;
	DigitalInput* pDipSwitchTwo;
	DigitalInput* pDipSwitchThree;
	DigitalInput* pDipSwitchFour;
	DigitalOutput* pLED1;
	AnalogInput* pLeftFrontUltra;
	ADXRS450_Gyro* pGyro;
public:
	DriveTrain();
	void InitDefaultCommand();
	void Drive(Joystick* stick);
	void Turn(float speed, float direction);
	void TankDrive(double leftAxis, double rightAxis);
	void LightLED();
	void Calibrate();
	int GetLeftEncoderValue();
	int GetRightEncoderValue();
	double GetUltraAt(int presetPort);
	double GetGyro();
	bool GetSwitchPositionOne();
	bool GetSwitchPositionTwo();
	bool GetSwitchPositionThree();
	bool GetSwitchPositionFour();
	void ResetGyro();
	CANTalon* pLeftFrontMotor;
	CANTalon* pLeftRearMotor;
	CANTalon* pRightFrontMotor;
	CANTalon* pRightRearMotor;
};

#endif
