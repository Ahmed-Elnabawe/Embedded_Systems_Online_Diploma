/*
 * Example1.c : Program to Find the Largest Number Among Three Numbers
 *
 *  Created on: Apr 9, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> //calling stander input output lib
int main ()
{
	int num1,num2,num3 ; // declaring a variables to read the values from user
	printf("enter three numbers  :"); // asking user to enter the values
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%d%d%d",&num1,&num2,&num3); // reading  values form user
	if ((num1>=num2)&&(num1>=num3)) // check if num1 > num2 and num1 > num3
			printf("largest number is %d",num1); // if true then num1 is the largest number
	else if (num2>=num3) // if false then check if the num2 > num3
		printf("largest number is %d",num2); // if true then num2 is the largest number
	else //if false
		printf("largest number is %d",num3);//then the num3 is the largest number
	return 0;
}
