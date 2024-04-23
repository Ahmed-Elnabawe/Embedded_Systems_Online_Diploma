/*
 * Calculate_Square_Root.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> // include stander input output lib
float sqr (int);
int main ()
{
	int number; // variable to read the value from user
	float root=0;// variable to save the output of calling function
	printf("enter the number : "); // asking user to enter the value
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&number);// scanning value from user
	root = sqr(number);// calling the function
	printf("square root of %d is : %0.3f",number,root); // printing the result to user
	return 0;// return of the main
}
float sqr (int number)// function definition
{
	float i=0.0001 ; // define variable to calculate the root with small initial value
	while(i*i < number) // calculate i*i and compare it with the number
		i+=0.0001;//if we did not reach the number so increase i with small value until we reach it
	return i; // return the value of i to the main
}
