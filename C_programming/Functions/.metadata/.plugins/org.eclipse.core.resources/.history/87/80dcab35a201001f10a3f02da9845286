/*
 * Example1.c : printing prime number between to intervals using function
 *
 *  Created on: Apr 17, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> // including stander input output lib
int check_prime(int);// prototype of the printing function
void main (void)
{
	int first_number , second_number ;// define to variable to be use as intervals
	int i ; // counter for loop
	printf("enter two numbers : "); // asking user to enter the intervals
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d%d",&first_number,&second_number);// scanning the intervals from user
	printf("prime numbers between %d and %d  : \n",first_number,second_number);
	for(i=first_number;i<second_number;i++)// now i is represent the numbers between two intervals
	{
		int flag =check_prime(i); // calling the function to check if the i is prime or not
		if (flag == 0) printf("%d ",i); // if the function returns 0 then i is prime so we will print it
	}
}
int check_prime(int num) // definition of the function check if the number is prime or not
{
	int flag =0; // flag variable to change its value in some conditions
	int i; // counter for loop
	for(i=2;i<num/2 ; i++) // check if the number is divided by any number smaller than it (without 1 and 0)
		if(num%i==0) // if the remainder is equal to zero
		{
			flag=1; // then the number is not prime and we will change the value of flag
			break; // after change the flag we will break from loop
		}
	return flag; // return the flag to make check on it
}
