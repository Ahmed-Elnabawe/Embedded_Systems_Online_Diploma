/*
 * state.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Lenovo
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_


// state connection
void US_set_distance(int d );
void DC_motor_set_speed(int s );
#endif /* STATE_H_ */
