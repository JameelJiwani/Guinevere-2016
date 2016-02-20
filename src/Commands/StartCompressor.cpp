#include "StartCompressor.h"

StartCompressor::StartCompressor()
{
	Requires(CommandBase::pSFM);
}

// Called just before this Command runs the first time
void StartCompressor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StartCompressor::Execute()
{
	CommandBase::pSFM->StartCompressor();
}

// Make this return true when this Command no longer needs to run execute()
bool StartCompressor::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StartCompressor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StartCompressor::Interrupted()
{

}
