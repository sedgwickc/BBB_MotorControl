/* MotorControl_test.cpp
 * Charles Sedgwick
 * licence: GPLv3
 */

#include <iostream>
#include "MotorControl.hpp"
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace rover;

int main() {
	
	MotorControl* mc = new MotorControl(NULL,NULL);
	mc->forward();
	sleep(5);
	mc->stop();
	sleep(5);
	mc->clean_up();
	
	return 0;
}
