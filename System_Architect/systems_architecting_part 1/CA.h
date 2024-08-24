/*
 * CA.h
 *
 *  Created on: Aug 22, 2024
 *      Author: Lenovo
 */

#ifndef CA_H_
#define CA_H_
#include "state.h"
enum{
	CA_waiting,
	CA_driving
}CA_state_id;
void CA_init ();
// declare states functions for CA

STATE_define(CA_waiting);
STATE_define(CA_driving);

void (*CA_state)();


#endif /* CA_H_ */
