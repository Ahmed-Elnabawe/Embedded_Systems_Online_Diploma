/*
 * memory_map.h
 *
 * Created: 11/29/2024 3:34:26 PM
 *  Author: Lenovo
 */ 


#ifndef MEMORY_MAP_H_
#define MEMORY_MAP_H_
#define PORTD *(volatile unsigned char*)(0x32)
#define DDRD *(volatile unsigned char*)(0x31)
#define PIND *(volatile unsigned char*)(0x30)
#endif /* MEMORY_MAP_H_ */