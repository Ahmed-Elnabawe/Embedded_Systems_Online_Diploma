/*
 * Example2.c : find the length of string
 *
 *  Created on: Apr 14, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> // including stander input output lib
int main ()
{
	char c[50]; // array of character (string)

	int counter =0; // counter to save the length
	int i ; // counter for loop
	printf("enter the string :"); //asking user to enter the string
	fflush(stdin);fflush(stdout);// clearing the buffer
	gets(c);//reading string from user
	for(i=0;c[i]!='\0';i++) // if we did not reach the end of string
	{
			counter++;// increment counter at each character
	}
	printf("the length is : %d ",counter); // print the length to user
	return 0;
}
