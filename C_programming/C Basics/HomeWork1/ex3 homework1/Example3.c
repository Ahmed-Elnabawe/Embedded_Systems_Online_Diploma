/*
 * Example3.c
 *
 *  Created on: Apr 8, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h> // calling stander input output lib

void main (){
	int num1=0,num2=0; // declaring two variables to be reading form user
	printf("Enter the first number :"); // asking user to enter the first number
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%d",&num1); // scanning the first number
	printf("Enter the second number :"); // asking user to enter the second number
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%d",&num2); // scanning the second number
	printf("the sum is = %d ", (num1+num2)); // printing the sum to user

}
