/*
 * CA.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Lenovo
 */


//variables
#include "CA.h"
int CA_speed =0;
int CA_distance =0;
int CA_threshold =50;
void CA_init ()
{
	printf("CA_init\n");
}
void US_set_distance(int d ){
	CA_distance=d;
	(CA_distance <= CA_threshold)? (CA_state= STATE(CA_waiting)):(CA_state= STATE(CA_driving));
	printf(" US -------------> CA  distance = %d \n",CA_distance);
}
STATE_define(CA_waiting){

	// state name
	CA_state_id=CA_waiting;
	printf("\n CA_waiting_state distance=%d , speed=%d \n",CA_distance,CA_speed);
	// state Action
	CA_speed=0;
	DC_motor_set_speed(CA_speed);

}
STATE_define(CA_driving){
	// state name
	CA_state_id=CA_driving;
	printf("CA_driving_state distance=%d , speed=%d \n",CA_distance,CA_speed);
	// state Action
	CA_speed=30;
	DC_motor_set_speed(CA_speed);
}



