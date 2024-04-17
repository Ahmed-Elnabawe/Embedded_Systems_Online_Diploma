/*
 * Example1.c : reverse a string using recursion
 *
 *  Created on: Apr 17, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> // including stander input output lib

void reverse(void); // function prototype

int main(void) {


	printf("enter the sentence : ");// asking user to enter a sentence
	fflush(stdin);fflush(stdout);// clearing the buffer
	reverse();

	return 0;
}

void reverse ()// function definition
{
	char ch; // char variable to be read from user
	scanf("%c",&ch); // reading variable from user
	if(ch!='\n')// if the user did not press enter
	{
		reverse(); // now the function is calling itself so user can enter any number of characters but not enter '\n'
		// lets see what will happen
		// user enter : ahmed elnabawe and then press enter '\n'
		// so the stack of the last function('\n') will be removed
		// then the compiler will jump to the stack of  previous function('e') and print 'e'
		// and then to stack of  previous function('w') and so on
		// this is the concept of "LIFO"(last in first out)
		printf("%c",ch);
	}
}
