
#define SMALL_WHEEL 8.6394
#define STANDERD_WHEEL 12.5664
#define LARGE_WHEEL 15.7080
void driveDistance(int distance, float wheel_circumference, short leftMotor, short rightMotor) {

	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;
	//calculate distance degrees to travel based on desired distance and wheel circumference
	int distanceToTravel = (360 / wheel_circumference) * distance;

	writeDebugStreamLine("Sensor Value: %i Distance: %i\n", SensorValue(leftEncoder), distanceToTravel);

	//Go until desired distance is traveled
	while(SensorValue(getEncoderForMotor(leftMotor)) > distanceToTravel) {

		writeDebugStreamLine("Left Encoder:%i - Right Encoder:%i", SensorValue(getEncoderForMotor(leftMotor)), SensorValue(getEncoderForMotor(rightMotor)));
		
		//Go straight
		if(SensorValue(getEncoderForMotor(leftMotor)) == SensorValue(getEncoderForMotor(rightMotor))) {

			motor[leftMotor] = 127;
			motor[rightMotor] = 127;
		//Correct if pulling right
		} else if(SensorValue(getEncoderForMotor(leftMotor)) > SensorValue(getEncoderForMotor(rightMotor))) {

			motor[leftMotor] = 114;
			motor[rightMotor] = 127;
		//Correct if pulling left
		} else if(SensorValue(getEncoderForMotor(leftMotor)) < SensorValue(getEncoderForMotor(rightMotor))) {

			motor[leftMotor] = 127;
			motor[rightMotor] = 114;

		}
	}
	//stop
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;
}
