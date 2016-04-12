/***************************************************************************
 * Charles Sedgwick
 * MotorControl.cpp
 * The MotorControl class is reponsible for controlling the direction and speed
 * of the 4 motors. 
 ***************************************************************************/

#include "MotorControl.hpp"
#include <iostream>

using namespace std;

namespace rover {

/***************************************************************************
 CONSTRUCTOR
 ***************************************************************************/
 
/**************************************************************************/
/*!
    @brief  Instantiates a new motor control class
*/
/**************************************************************************/
MotorControl::MotorControl(unsigned int *p_right, unsigned int *p_left)
{
	if( p_right == NULL || p_left == NULL){
		cout<<"No pins passed in... \nUsing defaults..."<<endl;
		set_default_pins();
		return;
	}

	/* Set up GPIO pins if not 
	for( int i = 0; i < 4; i++)
	{
		pins_right[i] = new mraa::Gpio(p_right[i]);
		res_right[i] = pins_right[i]->dir(mraa::DIR_OUT);

		pins_left[i] = new mraa::Gpio(p_left[i]);
		res_left[i] = pins_left[i]->dir(mraa::DIR_OUT);
	}*/
}

/***************************************************************************
 PUBLIC FUNCTIONS
 ***************************************************************************/

/**************************************************************************/
/*!
    @brief  Setups the HW
*/
/**************************************************************************/

int MotorControl::turn_left()
{
	return 1;
}

int MotorControl::turn_right()
{
	return 1;
}

int MotorControl::stop()
{
	cout<<"Stopping all motors..."<<endl;
	for( int i = 0; i < PIN_COUNT; i++ )
	{
		res_right[i] = pins_right[i]->write(LOW);
		//res_left[i] = pins_left[i]->write(HIGH);
	}
	return 1;
}

int MotorControl::forward()
{
	cout<<"Setting motor direction forward..."<<endl;
	// check state
	//set pins
	res_right[0] = pins_right[0]->write(HIGH);
	res_right[2] = pins_right[2]->write(HIGH);
	return 1;
}

int MotorControl::backward()
{
	return 1;
}

int MotorControl::set_speed()
{
	return 1;
}

int MotorControl::get_speed()
{
	return 1;
}

int MotorControl::set_default_pins()
{
	cout<<"Setting default pins..."<<endl;
	//create pins
	pins_right[0] = new mraa::Gpio(40);
	if (pins_right[0] == NULL) {
	    return mraa::ERROR_UNSPECIFIED;
	}
	pins_right[1] = new mraa::Gpio(42);
	if (pins_right[0] == NULL) {
	    return mraa::ERROR_UNSPECIFIED;
	}
	pins_right[2] = new mraa::Gpio(44);
	if (pins_right[0] == NULL) {
	    return mraa::ERROR_UNSPECIFIED;
	}
	pins_right[3] = new mraa::Gpio(46);
	if (pins_right[0] == NULL) {
	    return mraa::ERROR_UNSPECIFIED;
	}
	// TODO: add left pins

	//set pin direction
	for( int i = 0; i < PIN_COUNT; i++ ){
		res_right[i] = pins_right[i]->dir(mraa::DIR_OUT);
		if(res_right[i] != mraa::SUCCESS){
			mraa::printError(res_right[i]);
			return 1;
		}
		// TODO: add left pins
	}
	return 1;
}

int MotorControl::clean_up()
{
	for(int i = 0; i < PIN_COUNT; i++){
		delete pins_right[i];
		// TODO: delete left pin objects
	}
	return 1;
}

MotorControl::~MotorControl(){}

}; // rover namespace

