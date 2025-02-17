/*
 * Utils.h
 *
 * Created: 2/2/2025 10:44:13 PM
 *  Author: Lenovo
 */ 


#ifndef UTILS_H_
#define UTILS_H_
#define SET_BIT(reg,bit)  (reg=reg|(1<<bit))
#define CLEAR_BIT(reg,bit)  (reg=reg & ~(1<<bit))
#define TOGGLE_BIT(reg,bit)  (reg=reg^(1<<bit))
#define READ_BIT(reg,bit)  ((reg>>bit)&1)
#endif /* UTILS_H_ */