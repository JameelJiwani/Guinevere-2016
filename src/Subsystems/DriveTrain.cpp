#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/JoystickDrive.h"

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain")
{
	pLeftFrontMotor = new CANTalon(TALON_LEFT_FRONT_DRIVE);
	pLeftRearMotor = new CANTalon(TALON_LEFT_REAR_DRIVE);
	pRightFrontMotor = new CANTalon(TALON_RIGHT_FRONT_DRIVE);
	pRightRearMotor = new CANTalon(TALON_RIGHT_REAR_DRIVE);

	pDipSwitchOne = new DigitalInput(0);
	pDipSwitchTwo = new DigitalInput(1);
	pDipSwitchThree = new DigitalInput(2);
	pDipSwitchFour = new DigitalInput(3);

	pLED1 = new DigitalOutput(14);

	// Assigns the Talons a device to receive feedback from
	pLeftFrontMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
	pRightFrontMotor->SetFeedbackDevice(CANTalon::QuadEncoder);

	// Only front motor Talons have encoders


	// Encoder Pulses [SET PHYSICALLY USING DIP SWITCHES]
	pLeftFrontMotor->ConfigEncoderCodesPerRev(2048);
	pRightFrontMotor->ConfigEncoderCodesPerRev(2048);

	pLeftFrontUltra = new AnalogInput(ULTRASONIC_LEFTFRONT_ANIPORT);

	pGyro = new ADXRS450_Gyro();

	// Default sensitivity
	pGyro->Reset();

	pRobot = new RobotDrive(pLeftFrontMotor, pLeftRearMotor, pRightFrontMotor, pRightRearMotor);

	pRobot->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	pRobot->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	pRobot->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	pRobot->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
}

void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new JoystickDrive());
}

void DriveTrain::Drive(Joystick* stick){
	pRobot->ArcadeDrive(stick);
}

void DriveTrain::TankDrive(double leftAxis, double rightAxis)
{
	pRobot->TankDrive(leftAxis, rightAxis);
}

// Equations for encoders = encoder ticks * (2PIr)

int DriveTrain::GetLeftEncoderValue(){
	double data = pLeftFrontMotor->GetPosition();
	double equation = 2.0 * 3.141 * 3.0;

	return data * equation;
}

int DriveTrain::GetRightEncoderValue(){
	double data = pRightFrontMotor->GetPosition();
	double equation = 2.0 * 3.141 * 3.0;

	return data * equation;
}

void DriveTrain::LightLED() {
	pLED1->Set(1);
}

double DriveTrain::GetUltraAt(int presetPort){
	switch(presetPort){
		case 5:
			return pLeftFrontUltra->GetAverageVoltage() * ULTRASONIC_READING_TO_INCH / ULTRASONIC_SCALEFACTOR;
			break;
		case 3:
			//return leftRearUltra->GetAverageVoltage() * ULTRASONIC_READING_TO_INCH / ULTRASONIC_SCALEFACTOR;
			return 9999.9;
			break;
		default:
			return 9999.9; //impossible value
	}
}

bool DriveTrain::GetSwitchPositionOne() {
	return pDipSwitchOne->Get();
}

bool DriveTrain::GetSwitchPositionTwo() {
	return pDipSwitchTwo->Get();
}

bool DriveTrain::GetSwitchPositionThree() {
	return pDipSwitchThree->Get();
}

bool DriveTrain::GetSwitchPositionFour() {
	return pDipSwitchFour->Get();
}

void DriveTrain::Turn(float speed, float direction)
{
	pRobot->ArcadeDrive(speed, direction);
}

double DriveTrain::GetGyro(){
	return pGyro->GetAngle();
}

void DriveTrain::Calibrate(){
	pGyro->Calibrate();
}

void DriveTrain::ResetGyro(){
	pGyro->Reset();
}
