#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  leftEncoder,    sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  rightEncoder,   sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           leftMotor,     tmotorVex393_HBridge, PIDControl, driveLeft, encoderPort, I2C_1)
#pragma config(Motor,  port10,          rightMotor,    tmotorVex393_HBridge, PIDControl, reversed, driveLeft, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#include "driveDistance.h"
task main()
{
	while(true) {
		motor[port1] = 127;
		motor[port10] = 127;
	}
	//driveDistance(-12, SMALL_WHEEL, leftMotor, rightMotor);
}
