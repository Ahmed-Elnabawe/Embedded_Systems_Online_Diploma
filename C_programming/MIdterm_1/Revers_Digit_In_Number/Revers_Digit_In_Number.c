/*
 * Revers_Digit_In_Number.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> // including stander input output lib
int Number_Length(int);// length function prototype
int Reverse_Calculator (int, int);//revers function prototype
int main ()
{
	int number; // define variable to read value from user
	int number_length;
	int result;
	printf("enter the number : "); // asking user to enter the value
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&number);// scanning value from user
	number_length = Number_Length(number);//calling length function
	result = Reverse_Calculator(number,number_length);//calling revers function
	printf("the reversed number is : %d",result);// printing the result to user
}

int Number_Length(int number )// definition of function to calculate length
{
	int length=0 ; //define variable to calculate the length
	while (number !=0 ) // while number not equal zero (counting each digit)
	{
		number /=10 ;// remove one digit in each iteration
		length++;// increase the value of the length by one
	}
	return length;// return the length of the number to main
}

int Reverse_Calculator (int number , int length) // definition of function to reverse number
{
	int sum =0;// define a variable to save the sum
	int i ; // counter for loop
	int digit=number % 10; // save the smallest digit(most right in the original number) in the number (most left in the reversed number)
	for(i=1;i<length;i++)// staring a loop from 1 to length
	{
		// in decimal system the base of numbers is 10
		// if we have an example 123 is = 1*10^2 + 2*10^1 +3*10^0
		// so if we want to reverse the number and we started from the most right digit 3*10^0
		// we need to make a loop to calculate the new digit in the most left 3*10^2(length-1)
		digit*=10; // this is the step which we will repeat it in each iteration

	}
	if(number!=0)// condition to end the recursion
	sum = digit + Reverse_Calculator (number/10 , length-1);// adding a new digit to the sum and repeat the function to the end of the number
	return sum;//return sum to the main
}
