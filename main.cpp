/*
* Ben Goldberg's 2 stage code framwork
*
*	Use:
*	-	Automatic switching between autonomous and teleop modes
*
*	Directions:
*
*	- Put autonomous code in the auton function
*	-	Put human remote control code in the teleop function
* - Start Button must be plugged into digital port 1
*	-	Digital port 1 must be configure as a touch sensor in Motor and Sensor Setup
*	-	The file "twoStage.h" must be in the same folder as this one
*
*	Errors:
*
*	-	If you get the error "Couldn't open '#include' file 'twoStage.h'"
*		then twoStage.h is not is the right place
*/

void auton() {
	//Put autonomous code here
	motor[port1] = 50;
	motor[port10] = 50;
}

void teleop() {
	//Put teleop code here
	motor[port1] = vexRT[Ch3];
	motor[port10] = vexRT[Ch2];
}


//Do not edit code bellow this point!
#include "twoStage.h"
task main() {
	twoStage();
}
