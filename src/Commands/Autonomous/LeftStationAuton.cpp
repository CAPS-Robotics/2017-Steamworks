#include <Commands/Autonomous/LeftStationAuton.h>
#include <Commands/Autonomous/DriveUntilDistance.h>
#include <Commands/Autonomous/RotateToAngle.h>
#include <Commands/Autonomous/DriveStraightForTime.h>
#include <Commands/Autonomous/StrafeAlign.h>
#include <Commands/Drivetrain/ZeroGyro.h>

LeftStationAuton::LeftStationAuton() {
	AddSequential(new ZeroGyro());
	AddSequential(new DriveStraightForTime(2.15));
	AddSequential(new RotateToAngle(-55));
	AddSequential(new DriveStraightForTime(0.5));
	AddSequential(new StrafeAlign());
	AddSequential(new DriveUntilDistance(9.1));
}
