
#define SMALL_WHEEL 8.6394
#define STANDERD_WHEEL 12.5664
#define LARGE_WHEEL 15.7080
void driveDistance(int distance, float wheel_circumference, short leftMotor, short rightMotor, short leftEncoder, short rightEncoder) {
	int distanceToTravel = (360 / wheel_circumference) * distance;
	while(SensorValue(leftEncoder) < distanceToTravel) {
		if(SensorValue(leftEncoder) == SensorValue(rightEncoder)) {
			motor[leftMotor] = 127;
			motor[rightMotor] = 127;
		} else if(SensorValue(leftEncoder) > SensorValue(rightEncoder)) {
			motor[leftMotor] = 114;
			motor[rightMotor] = 127;
		} else if(SensorValue(leftEncoder) < SensorValue(rightEncoder)) {
			motor[leftMotor] = 127;
			motor[rightMotor] = 114;
		}
	}
}
