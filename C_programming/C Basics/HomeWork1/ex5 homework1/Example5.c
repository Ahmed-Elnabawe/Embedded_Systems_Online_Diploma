/*
 * Example5.c
 *
 *  Created on: Apr 8, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> //calling the stander input output lib
int main (){
	char ch;
	printf("Enter a character :");
	fflush(stdin);fflush(stdout);
	scanf("%c",&ch);
	printf("ASCII value of %c : %d",ch,ch);
	return 0;
}

