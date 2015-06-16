#define AUTONTIME 30
#define TELEOPTIME 120

//code to make the robot wait for controller button to be pressed
int buttonWait() {
	int startWait = time100[T1] / 10;
	//stop motors
	postAuton();
	//wait for button press
	while(true) {
		if(vexRT[Btn8L] == 1)
			break;
	}
	return (time100[T1] / 10) - startWait;
}

int getTime() {
	return time100[T1] / 10;
}

void twoStage() {
	int startTime;
	int upTime;

	//wait for button on robot to be pressed
	while(true) {
		if(SensorValue(dgtl1) == 1) {
			startTime = time100[T1] / 10;
			break;
		}
	}
	//Run auton function on a loop for 30 seconds
	while(getTime() - startTime <= AUTONTIME) {
		writeDebugStreamLine("%i : %i : %i", upTime, AUTONTIME, upTime <= AUTONTIME);
		auton();
	}
	startTime += buttonWait();
	//Run teleop function on a loop for 120 seconds
	while(getTime() - startTime > AUTONTIME && getTime() - startTime <= TELEOPTIME) {
		teleop();
	}
	//stop motors
	postTeleop();
}
