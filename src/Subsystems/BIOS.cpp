 #include "BIOS.h"
#include "../RobotMap.h"

BIOS::BIOS() :
Subsystem("BIOS")
{
	prefs = Preferences::GetInstance();
	fShootSpeed = prefs->GetFloat("ShootSpeed", 0.6f);
	fIntakeSpeed = prefs->GetFloat("IntakeSpeed", 0.25f);
	fKickerSpeed =prefs->GetFloat("KickerSpeed", 1.0f);
	fAdjustSpeed =prefs->GetFloat("AdjustSpeed", 0.4f);
	pCollectorMotor = new CANTalon(TALON_COLLECTOR);
	pShooterMotorRight = new CANTalon(TALON_RIGHT_SHOOTER);
	pShooterMotorLeft = new CANTalon(TALON_LEFT_SHOOTER);
	limitSwitch = new DigitalInput(9);
	counter = new Counter(limitSwitch);
	pTimer = new Timer;
	pShooterMotorLeft->SetInverted(true);
}

void BIOS::Intake(float speed)
{
	pCollectorMotor->Set(-speed);
}

void BIOS::Shoot(float speed)
{
	pShooterMotorRight->Set(speed);
	pShooterMotorLeft->Set(speed);
}

float BIOS::StopIntake()
{
	pCollectorMotor->Set(0);
}

float BIOS::StopShoot()
{
	pShooterMotorRight->Set(0);
	pShooterMotorLeft->Set(0);
}

void BIOS::LowGoal()
{
	pCollectorMotor->Set(0.75);
}

void BIOS::StartTimer()
{
	pTimer->Start();
}

double BIOS::GetCurrentTime()
{
	return pTimer->Get();
}

void BIOS::StopTimer()
{
	pTimer->Stop();
	pTimer->Reset();
}


float BIOS::GetShootSpeed()
{
	fShootSpeed = prefs->GetFloat("ShootSpeed", 0.6f);
	return fShootSpeed;
}

float BIOS::GetIntakeSpeed()
{
	fIntakeSpeed = prefs->GetFloat("IntakeSpeed", 0.5f);
	return fIntakeSpeed;
}

float BIOS::GetKickerSpeed(){
	fKickerSpeed =prefs->GetFloat("KickerSpeed", 1.0f);
	return fKickerSpeed;
}

float BIOS::GetAdjustSpeed(){
	fAdjustSpeed = prefs->GetFloat("AdjustSpeed",-0.4f);
	return fAdjustSpeed;
}

bool BIOS::IsSwitchSet() {
	return limitSwitch->Get();
	//return counter->Get() > 0;
}

void BIOS::InitializeCounter() {
	counter->Reset();
}

void BIOS::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
