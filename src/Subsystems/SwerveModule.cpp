#include "SwerveModule.h"
#include "../RobotMap.h"
#include <CANTalon.h>

SwerveModule::SwerveModule(int steerMotor, int driveMotor, bool isInverted) : Subsystem("SwerveModule") {
	this->steer = new CANTalon(steerMotor);
	this->steer->ConfigNeutralMode(CANTalon::NeutralMode::kNeutralMode_Brake);
	this->drive = new Talon(driveMotor);
	this->drive->SetInverted(isInverted);
	steer->SetFeedbackDevice(CANTalon::FeedbackDevice::QuadEncoder);
	steer->ConfigEncoderCodesPerRev(497);
	steer->SetControlMode(CANTalon::kPosition);
	steer->SetPosition(0);
	steer->SetPID(25.f, 0.f, 1.f);
	steer->SetAllowableClosedLoopErr(2);
	steer->ConfigNominalOutputVoltage(+0.f, -0.f);
	steer->ConfigPeakOutputVoltage(+12.f, -12.f);
	steer->SetStatusFrameRateMs(CANTalon::StatusFrameRate::StatusFrameRateFeedback, 10);
	steer->Set(0);
	currentSpeed = 0;
}

void SwerveModule::InitDefaultCommand() {

}

void SwerveModule::Drive(double speed, double angle) {
	//speed = fabs(speed) > 0.1 ? speed : 0;

	double dist = angle - this->GetAngle();

	if (fabs(dist) > 90 && fabs(dist) < 270) {
		angle = fmod(180 + angle, 360);
		speed = -speed;
	}

	if (speed == 0 || fabs(speed - currentSpeed) > 1.f) {
		currentSpeed = 0;
	} else if (currentSpeed > speed) {
		currentSpeed -= 0.04;
	} else if (currentSpeed < speed) {
		currentSpeed += 0.04;
	}

	SmartDashboard::PutNumber("Distance", dist);

	this->steer->Set(angle / 1.2 / 360);
	this->drive->Set(currentSpeed);
}

void SwerveModule::ReturnToZero() {
	this->steer->Set(0);
}

void SwerveModule::ResetEncoder() {
	this->steer->SetPosition(0);
}

double SwerveModule::GetAngle() {
	float someAngle = this->steer->Get() * 1.2 * 360;
	while (someAngle > 360.f) {
		someAngle -= 360;
	}
	while (someAngle < 0.f) {
		someAngle += 360;
	}
	return someAngle;
}
