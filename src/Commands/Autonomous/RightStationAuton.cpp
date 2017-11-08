#include <Commands/Autonomous/RightStationAuton.h>
#include <Commands/Autonomous/PlaceGear.h>
#include <Commands/Drivetrain/ZeroGyro.h>
#include <Commands/Autonomous/DriveStraightForTime.h>

RightStationAuton::RightStationAuton() {
	AddSequential(new ZeroGyro());
	AddSequential(new DriveStraightForTime(3.4));
	AddSequential(new PlaceGear(60));
}
