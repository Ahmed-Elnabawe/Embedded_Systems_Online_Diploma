/*
 * Example1.c :   program to calculate sum of natural numbers
 *
 *  Created on: Apr 9, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> //calling stander input output lib
int main ()
{
	int number,sum=0  ; //declaring a variable to read the value of number from user and another one with initial value of zero to calculate the sum
	int i; // a counter for the loop
	printf("enter an integer number : "); // asking user to enter the value
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%d",&number); // reading the value from user
	for(i=1;i<=number;i++) // starting a loop from i = 1 to the number(from user)
	{
		sum=sum+i; //adding the value of i in each iteration to the sum
	}
	printf("the sum is : %d ",sum);//printing the value to user
	return 0;
}
