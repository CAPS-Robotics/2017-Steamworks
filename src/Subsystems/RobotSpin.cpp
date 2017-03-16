#include "../RobotMap.h"
#include "../Robot.h"
#include <PigeonImu.h>
#include <Subsystems/RobotSpin.h>

RobotSpin::RobotSpin() {
	output = 0;
}

double RobotSpin::Get() {
	return output;
}

void RobotSpin::PIDWrite(double output) {
	SmartDashboard::PutNumber("PID Output", output);
	this->output = output;
}
