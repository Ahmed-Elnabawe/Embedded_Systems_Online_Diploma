/*
 * Example1.c : Program to Check Whether a Character is an Alphabet or not
 *
 *  Created on: Apr 9, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> //calling stander input output lib
void main ()
{
	char ch ; // declaring a variable to read the value from user
	printf(" Enter a character: "); // asking user to enter the value
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%c",&ch); // reading  value form user
	if ((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) // check if ch is in the range of alphabet characters
			printf(" %c is alphabet ",ch); // if true then ch is alphabet
	else // if the character is not in the range of the alphabet characters
		printf(" %c is not alphabet ",ch);//then print the character is not alphabet

}
