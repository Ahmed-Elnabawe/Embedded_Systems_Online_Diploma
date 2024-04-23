/*
 * Example1.c :   program to calculate the factorial
 *
 *  Created on: Apr 9, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> //calling stander input output lib
int main ()
{
	int number ,fact=1; //declaring a variable to read the value of number from user and another one to calculate factorial
	int i; // a counter for the loop
	printf("enter an integer number : "); // asking user to enter the value
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%d",&number); // reading the value from user
	if(number>=0)
	{
		for(i=1;i<=number;i++) // starting a loop from i = 1 to the number(from user)
		{
			fact*=i; // calculate the factorial
		}
		printf("the factorial is : %d ",fact);//printing the value to user
	}
	else printf("error factorial of a negative number is not exist  ");//tell user to enter a positive number
	return 0;
}
