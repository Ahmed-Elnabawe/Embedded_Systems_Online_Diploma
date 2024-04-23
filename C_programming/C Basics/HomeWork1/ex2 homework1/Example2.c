/*
 * Example2.c
 *
 *  Created on: Apr 8, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h> //calling the stander input output lib
int main (){
	int value =0 ; // declare a variable to read value from user
	printf("Enter a integer :"); // asking user to enter the value
	fflush(stdin);fflush(stdout); // clearing the buffer
	scanf("%d",&value); // scanning the value
	printf("You entered : %d ",value); // print the value to user
	return 0;
}
