#include "AdjustShoot.h"

AdjustShoot::AdjustShoot()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::pBIOS);

}

// Called just before this Command runs the first time
void AdjustShoot::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AdjustShoot::Execute()
{
	CommandBase::pBIOS->StartTimer();
	CommandBase::pBIOS->Intake(CommandBase::pBIOS->GetAdjustSpeed());
}

// Make this return true when this Command no longer needs to run execute()
bool AdjustShoot::IsFinished()
{
	if(CommandBase::pBIOS->GetCurrentTime() >= 0.5){
			return true;
		}else{
			return false;
		}
}

// Called once after isFinished returns true
void AdjustShoot::End()
{
	CommandBase::pBIOS->Intake(CommandBase::pBIOS->StopIntake());
	CommandBase::pBIOS->StopTimer();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AdjustShoot::Interrupted()
{

}
