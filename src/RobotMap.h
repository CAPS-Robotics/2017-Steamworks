#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// PWMs
const int BR_DRIVE_TALON  		= 4;
const int FR_DRIVE_TALON 		= 1;
const int FL_DRIVE_TALON 		= 2;
const int BL_DRIVE_TALON  		= 3;

// CAN IDs
const int FL_TALON_SRX 			= 0;
const int BL_TALON_SRX 			= 1;
const int BR_TALON_SRX 			= 2;
const int CLIMBER2_TALON_SRX	= 3;
const int FR_TALON_SRX 			= 4;
const int CLIMBER1_TALON_SRX 	= 5;

// Analog
const int FR_STEER_ENCODER		= 0;
const int FL_STEER_ENCODER		= 1;
const int BL_STEER_ENCODER		= 2;
const int BR_STEER_ENCODER		= 3;

const int RANGE_FINDER			= 4;

const float FL_OFFSET			= 4.5690;
const float FR_OFFSET			= 2.0739;
const float BL_OFFSET			= 2.4523;
const float BR_OFFSET			= 2.4340;

const double PI = 3.1415926536;
const float GR = 1.0 / 1.2;
const float GEAR_DISTANCE = 9.3;

#endif  // ROBOTMAP_H
