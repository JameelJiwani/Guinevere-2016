#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

static const int TALON_RIGHT_FRONT_DRIVE = 1;
static const int TALON_RIGHT_REAR_DRIVE = 2;
static const int TALON_LEFT_FRONT_DRIVE = 3;
static const int TALON_LEFT_REAR_DRIVE = 4;
static const int TALON_RIGHT_SHOOTER = 6;
static const int TALON_LEFT_SHOOTER = 7;
static const int TALON_COLLECTOR = 5;


static const int JOYSTICKPORT = 0;

// sensors
// Ultrasonic: refer to datasheet: http://maxbotix.com/documents/LV-MaxSonar-EZ_Datasheet.pdf
const int ULTRASONIC_LEFTFRONT_ANIPORT = 5;
const int ULTRASONIC_LEFTREAR_ANIPORT = 3;

/*****************************
* Formula [Voltage / 1024 = Volts per cm]
* [measured voltage / volts per cm = distance in cm]
*
*****************************/
const float VCC = 5.0f;
const float ULTRASONIC_SCALEFACTOR = VCC/1024.0f;
const float ULTRASONIC_READING_TO_INCH = 1.6f;

// conversion
const double METER_TO_INCH = 0.0254;
const double INCH_TO_METER = 1/METER_TO_INCH;
const double METER_TO_CM = 0.01;
const double CM_TO_METER = 1/METER_TO_CM;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;


#endif
