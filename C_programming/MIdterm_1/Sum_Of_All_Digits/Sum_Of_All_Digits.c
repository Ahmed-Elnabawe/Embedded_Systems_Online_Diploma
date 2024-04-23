/*
 * Sum_Of_All_Digits.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> // include stander input output lib
int Sum_Digits(int);// function prototype
int main()
{
	int number; // variable to read the value from user
	int sum=0;// variable to save the output of calling function
	printf("enter the number : "); // asking user to enter the value
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&number);// scanning value from user
	sum=Sum_Digits(number);// calling the function and save the output in sum variable
	printf("the sum of digits is : %d",sum);// printing the sum to user
	return 0;// return of main
}
int Sum_Digits(int number)//function definition
{
	int result;// define a variable to store the result of recursion
	int remain ;// define a variable to store the remainder of ( number % 10 ) and pass the value to the function again
	if (number == 0 )// check if no more digits
		return 0; // return zero to avoid affects in the sum and end the recursion
	else // if there is more digits
	{
		remain = number % 10; // save the value of the digit
		result=remain + Sum_Digits(number/10); // add this value to the sum and call the function again

	}
	return result; // at the end return the result of sum to the main
}
