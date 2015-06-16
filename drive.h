void drive(int speed) {
	//Go straight
	if(SensorValue(getEncoderForMotor(leftMotor)) == SensorValue(getEncoderForMotor(rightMotor))) {

		motor[leftMotor] = speed;
		motor[rightMotor] = speed;
	//Correct if pulling right
	} else if(SensorValue(getEncoderForMotor(leftMotor)) > SensorValue(getEncoderForMotor(rightMotor))) {

		motor[leftMotor] = speed * 0.2;
		motor[rightMotor] = speed * 1.2;
	//Correct if pulling left
	} else if(SensorValue(getEncoderForMotor(leftMotor)) < SensorValue(getEncoderForMotor(rightMotor))) {

		motor[leftMotor] = speed * 1.2;
		motor[rightMotor] = speed * 0.2;

	}
}
