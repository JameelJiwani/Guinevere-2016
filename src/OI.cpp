#include "OI.h"
#include "RobotMap.h"

#include "Commands/ExtendSFM.h"
#include "Commands/RetractSFM.h"
#include "Commands/TimedIntake.h"
#include "Commands/TimedShoot.h"
#include "Commands/ShootLowGoal.h"
#include "Commands/StartCompressor.h"
#include "Commands/AdjustShoot.h"

OI::OI()
{
	// Process operator interface input here.
	stick = new Joystick(JOYSTICKPORT);
	button1 = new JoystickButton(stick,1);
	button2 = new JoystickButton(stick,2);
	button3 = new JoystickButton(stick,3);
	button4 = new JoystickButton(stick,4);
	button5 = new JoystickButton(stick,5);
	button6 = new JoystickButton(stick,6);

	button1->WhenPressed(new TimedShoot());
	button2->WhenPressed(new TimedIntake());
	button3->WhenPressed(new ShootLowGoal());
	button4->WhenPressed(new ExtendSFM());
	button5->WhenPressed(new RetractSFM());
	button6->WhenPressed(new AdjustShoot());
}

/* Notes for the XBox controller:
        Button A: 1
        Button B: 2
        Button X: 3
        Button Y: 4
        Button LB: 5
        Button RB: 6
        Button LT: Range 0 to 1.000 (stick.GetTrigger())
        Button RT: Range 0 to -1.000 (stick.GetTrigger())
        Button Back: 7
        Button Start: 8
        Left Axis press: 9
                         X-Axis: -1.000 to 1.000 (stick.GetX())
                         Y-Axis: -1.000 to 1.000 (stick.GetY())
        Right Axis press: 10
                         X-Axis: -1.000 to 1.000 (stick.GetTwist())
                         Y-Axis:
         */
