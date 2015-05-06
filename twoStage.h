#define AUTONTIME 5
#define TELEOPTIME 30

void twoStage() {
	int startButton;
	int startTime;
	int upTime;

	//writeDebugStream("Waiting");
	while(true) {
		startButton = SensorValue(dgtl1);
		//writeDebugStream(".");
		if(startButton == 1) {
			//writeDebugStreamLine("Starting");
			startTime = time100[T1] / 10;
			break;
		}
	}
	//writeDebugStreamLine("Starting Main Loop");
	while(true) {
		upTime = time100[T1] / 10 - startTime;
		if(upTime <= AUTONTIME) {
			auton();
		} else if(upTime > AUTONTIME && upTime <= TELEOPTIME) {
			teleop();
		} else {
			break;
		}
	}
}
