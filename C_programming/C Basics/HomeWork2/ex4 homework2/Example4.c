/*
 * Example1.c : Program to Check Whether a Number is Positive or Negative
 *
 *  Created on: Apr 9, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> //calling stander input output lib
void main ()
{
	float num1 ; // declaring a variable to read the value from user
	printf("enter the number  :"); // asking user to enter the value
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%f",&num1); // reading  value form user
	if (num1>0) // check if num1 > 0
			printf(" %f is positive",num1); // if true then num1 is positive
	else if (num1==0)//check if the user entered zero value
		printf("you entered zero"); // print to user that he entered zero
	else // if the value is not positive and not zero then the value is negative
		printf(" %f is a negative ",num1);//then the num1 is negative

}
