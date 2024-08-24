/*
 * DC.c
 *
 *  Created on: Aug 23, 2024
 *      Author: Lenovo
 */
#include "DC.h"

int DC_speed=0;
void DC_init()
{

	// init all drivers
	printf("DC_init\n");
}
void DC_motor_set_speed(int s ){
	DC_speed=s;
	printf(" CA -------> DC speed= %d \n",DC_speed);
	DC_state=STATE(DC_busy);
}
STATE_define(DC_idle)
{
	// set state id
	DC_state_id=DC_idle;
	// print state info
	printf("-------- DC_idle -----> speed = %d \n",DC_speed);

	DC_state=STATE(DC_idle);

}
STATE_define(DC_busy)
{
	// set state id
	DC_state_id=DC_busy;
	printf("-------- DC_busy -----> speed = %d \n",DC_speed);
	DC_state=STATE(DC_idle);
}
