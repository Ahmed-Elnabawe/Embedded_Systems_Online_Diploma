/*
 * US.h
 *
 *  Created on: Aug 23, 2024
 *      Author: Lenovo
 */

#ifndef US_H_
#define US_H_
#include "state.h"
enum{
	US_busy
}US_state_id;
// init function prototype
void US_init();
// declare states
STATE_define(US_busy);
// get random prototype
int US_get_distance_random(int l , int r , int count);

// global pointer to function
void (*US_state)();

#endif /* US_H_ */
