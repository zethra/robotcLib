void auton() {
	motor[port1] = 50;
	motor[port10] = 50;
}

void teleop() {
	motor[port1] = vexRT[Ch3];
	motor[port10] = vexRT[Ch2];
}
