/*
 * Example4.c : calculating power using recursion
 *
 *  Created on: Apr 17, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> // including stander input output lib
int power_calc(int , int ); // function prototype
int main (void)
{
	int base , power ; // variables to read base and power from user
	printf("enter the base : ");//asking user to enter base
	fflush(stdin);fflush(stdout); // clearing the buffer
	scanf("%d",&base);//scanning the value from user
	printf("enter the power : ");//asking user to enter power
	fflush(stdin);fflush(stdout); // clearing the buffer
	scanf("%d",&power);//scanning the value from user
	printf("%d ^ %d = %d ",base , power , power_calc(power,base)); // calling the function and printing the result
	return 0;
}
int power_calc(int power , int base)// function definition
{
	if(power==0)//if the power is equal to zero
		return 1;// then return zero to end the recursion
	else
		return base*power_calc(power-1,base); // if the power is greater than zero so we will make the recursion
}
