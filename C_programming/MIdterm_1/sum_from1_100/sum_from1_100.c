/*
 * sum_from1_100.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Lenovo
 */
#include <stdio.h>// including stander input output lib
int sum (int);//function prototype
int main ()
{
	int number;
	printf("enter the number : "); // asking user to enter the value
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&number);// scanning value from user
	printf("the sum from 1 to %d is : %d ",number,sum(number));//print the result to user
}
int sum (int number)//function definition
{
	return number*(number+1)/2 ;//calculate the sum using equation
}
