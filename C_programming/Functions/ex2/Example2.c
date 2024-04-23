/*
 * Example1.c : calculating the factorial using recursion
 *
 *  Created on: Apr 17, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> // including stander input output lib
int fact (int);// prototype
int main()
{
	int factorial=1; // variable to save the output of recursion
	int number; // variable to calculate factorial of it
	printf("enter  number : "); // asking user to enter the number
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&number);// scanning the number from user
	factorial = fact(number); // calling the function
	printf("factorial is : %d ",factorial); // print factorial to user
	return 0;
}
int fact (int num )// definition of the function
{
	if(num==0 || num==1) return 1 ;// the factorial of 1 and 0 is = 1
	else return num*fact(num-1);// now we are making recursion we return num * function of num-1 and so on
}
