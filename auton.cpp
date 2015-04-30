#include "robotCode.h"
#define AUTONTIME 5
#define TELEOPTIME 30

task main()
{
	int startButton;
	int startTime;
	int upTime;

	while(true) {
		startButton = sensorValue[dgtl1];
		if(startButton == 1) {
			startTime = time100[T1] / 10;
			break;
		}
	}
	while(true) {
		upTime = time100[T1] / 10 - startButton;
		if(upTime <= AUTONTIME) {
			auton();
		} else if(upTime > AUTONTIME && upTime <= TELEOPTIME) {
			teleop();
		} else {
			break;
		}
	}
}
