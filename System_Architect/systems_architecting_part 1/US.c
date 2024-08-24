/*
 * US.c
 *
 *  Created on: Aug 23, 2024
 *      Author: Lenovo
 */

#include "US.h"

int US_distance =0;

void US_init()
{
	// init all drivers
	printf("US_init\n");
}


STATE_define(US_busy)
{
	// set state id
	US_state_id=US_busy;
	// get random distance
	US_distance=US_get_distance_random(45,55,1);
	//print the currant state info
	printf("\n-----------------------------------------");
	printf("\n-------- US_busy -----> distance = %d \n",US_distance);
	// call the connection to send data to CA block
	 US_set_distance(US_distance);
	// call US_state to generate a new distance
	 US_state=STATE(US_busy);

}
int US_get_distance_random(int l , int r , int count){
	volatile int i ;
	for (i = 0; i < count; ++i) {
		int rand_num = (rand()%(r-l+1))+l;
		return rand_num;
	}
	return 1;
}
