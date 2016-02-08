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
MotorControl::MotorControl(unsigned int *p_front, unsigned int *p_rear)
{
	if( p_front == NULL || p_rear == NULL){
		cout<<"No pins passed in... \nUsing defaults..."<<endl;
		return; // temporary!!
		set_default_pins();
	}

	/* Set up GPIO pins */
	for( int i = 0; i < 4; i++)
	{
		pins_front[i] = new mraa::Gpio(p_front[i]);
		res_front[i] = pins_front[i]->dir(mraa::DIR_OUT);

		pins_rear[i] = new mraa::Gpio(p_rear[i]);
		res_rear[i] = pins_rear[i]->dir(mraa::DIR_OUT);
	}
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
	return 1;
}

int MotorControl::forward()
{
	// check state
	for( int i = 0; i < PIN_COUNT; i++ )
	{
		res_front[i] = pins_front[i]->write(HIGH);
		res_rear[i] = pins_rear[i]->write(HIGH);
	}
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
	return 1;
}

int MotorControl::clean_up()
{
	return 1;
}

MotorControl::~MotorControl(){}

}; // rover namespace

