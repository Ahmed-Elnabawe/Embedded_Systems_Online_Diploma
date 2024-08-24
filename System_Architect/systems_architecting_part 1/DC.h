/*
 * DC.h
 *
 *  Created on: Aug 23, 2024
 *      Author: Lenovo
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
enum{
	DC_idle,
	DC_busy
}DC_state_id;
// init function prototype
void DC_init();
// declare states functions for DC
STATE_define(DC_idle);
STATE_define(DC_busy);

// declare a pointer to function
void (*DC_state)();

#endif /* DC_H_ */
