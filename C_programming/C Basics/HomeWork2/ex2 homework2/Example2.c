/*
 * Example1.c : Consonant or Vowel Check to Program C
 *
 *  Created on: Apr 9, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> //calling stander input output lib
void main ()
{
	char ch; // declaring a variable read the value from user
	printf("Enter an alphabet: "); // asking user to enter the alphabet
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%c",&ch); // reading the alphabet form user
	switch (ch){ // making a switch on the ch variable to check if the user entered a value of {a,e,i,o,u}
	case 'a' :  // in the case of 'a'
	{
		printf(" %c is a vowel.",ch); // print to user that 'a' is vowel
	}
	break; // breaking from the switch
	case 'e' :// in the case of 'e'
	{
		printf(" %c is a vowel.",ch);// print to user that 'e' is vowel
	}
	break;// breaking from the switch
	case 'i' :// in the case of 'i'
	{
		printf(" %c is a vowel.",ch);// print to user that 'i' is vowel
	}
	break;// breaking from the switch
	case 'o' :// in the case of 'o'
	{
		printf(" %c is a vowel.",ch);// print to user that 'o' is vowel
	}
	break;// breaking from the switch
	case 'u' :// in the case of 'u'
	{
		printf(" %c is a vowel.",ch);// print to user that 'u' is vowel
	}
	break;// breaking from the switch
	default : // if the user entered another value then the alphabet is consonant
	{
		printf(" %c is a consonant.",ch); // print to user that the alphabet is consonant
	}
	}

}
