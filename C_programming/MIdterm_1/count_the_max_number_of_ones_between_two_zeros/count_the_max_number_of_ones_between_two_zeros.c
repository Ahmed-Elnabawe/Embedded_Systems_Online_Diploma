/*
 * count_the_max_number_of_ones_between_two_zeros.c
 *
 *  Created on: Apr 23, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h>// including stander input output lib
int count_max_number_of_ones(int);//function prototype
int main ()
{
	int number ;//define a variable to read the number form user
	printf("enter the number :");// asking user to enter the nuber
	fflush(stdin);fflush(stdout);//clearing the buffer
	scanf("%d",&number);// scanning the number from user
	printf("the max number of ones is : %d " ,count_max_number_of_ones(number));//calling the function and print the result

}
int count_max_number_of_ones(int number)// function definition
{
	int i ;// counter for loop
	int counter=0;//counter to count number of ones between any two zeros
	int max=0;// define a variable to save the max number of ones
	for(i=32;i>=0;i--)// starting a loop form 32(integer is 4 byte so 34 bit )
	{
		if(number&(1<<i))
		{
			if(number&(1<<i)) // first we will shift 1 to be in front of the most left bit
			// then we will make a bitwise AND with the number
			// all bits after bitwise AND will be zero except the bit in the most left maybe = 0 or =1
			// if this bit equal 0 so the condition is false and the most left bit in the original number is 0
			// so we will go to the next bit
			// and if this bit is equal to 1 so the condition is true and the most left bit in the original number is 1
			counter++; // if the condition is true increment the counter of ones by one

		}
		else// if we found a zero then this is the end of the counter
		{
			max=(max>=counter)? max : counter; // we will compare the counter with the max to make sure that we have the max number of ones in the max variable
			counter=0;//starting a new counter
		}
	}

	return max;//return max to the main
}
