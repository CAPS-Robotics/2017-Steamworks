#include <Commands/Autonomous/MiddleStationAuton.h>
#include <Commands/Autonomous/DriveUntilDistance.h>
#include <Commands/Autonomous/RotateToAngle.h>
#include <Commands/Autonomous/StrafeAlign.h>
#include <Commands/Autonomous/DriveStraightForTime.h>

MiddleStationAuton::MiddleStationAuton() {
	AddSequential(new DriveUntilDistance(30));
	AddSequential(new StrafeAlign());
	AddSequential(new DriveUntilDistance(9.1));
}
