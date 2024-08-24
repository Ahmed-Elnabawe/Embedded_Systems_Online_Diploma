/*

 * main.c
 *
 *  Created on: Aug 22, 2024
 *      Author: Lenovo
 */

#include "CA.h"
#include "US.h"
#include "DC.h"
void setup (){
	US_init();
	CA_init();
	DC_init();
	// set pointer for each block
	US_state=STATE(US_busy);
	CA_state=STATE(CA_waiting);
	DC_state=STATE(DC_idle);
}
int main (){
	setup();
	volatile int i;
	while(1){
		US_state();
		CA_state();
		DC_state();
		// delay
		for (i = 0; i < 10000; ++i);
	}
}
