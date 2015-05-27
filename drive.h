void drive(int speed) {
	if(SensorValue(getEncoderForMotor(leftMotor)) == SensorValue(getEncoderForMotor(rightMotor))) {

		motor[leftMotor] = speed;
		motor[rightMotor] = speed;

	} else if(SensorValue(getEncoderForMotor(leftMotor)) > SensorValue(getEncoderForMotor(rightMotor))) {

		motor[leftMotor] = speed * 0.2;
		motor[rightMotor] = speed * 1.2;

	} else if(SensorValue(getEncoderForMotor(leftMotor)) < SensorValue(getEncoderForMotor(rightMotor))) {

		motor[leftMotor] = speed * 1.2;
		motor[rightMotor] = speed * 0.2;

	}
}
