/*
 * Example1.c : Write C Program to Check Whether a Number is Even or Odd
 *
 *  Created on: Apr 9, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h> //calling stander input output lib
int main ()
{
	int number ; // declaring a variable to read the value from user
	printf("enter the number to check whether it is odd or even :"); // asking user to enter the value
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%d",&number); // reading the value form user
	if(number%2==0) // check if the remainder of modulus is 0
		printf("%d is even",number); // if the remainder is 0 then the number is even
	else
		printf("%d is odd",number); // if the remainder is not 0 then the number is odd

	return 0;
}
