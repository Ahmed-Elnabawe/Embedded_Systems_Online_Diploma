/*
 * Example6.c
 *
 *  Created on: Apr 8, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> //calling the stander input output lib
void main (){

	int num1, num2; // declaring to variable to store values from user
	int temp; // variable to save the value of one of the two variables
	printf("Enter the first number :"); // asking user to enter the first number
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%d",&num1); // scanning the first number
	printf("Enter the second number :"); // asking user to enter the second number
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%d",&num2); // scanning the second number
	// printing numbers before swapping
	printf("--------------------------------\n");
	printf("two numbers before swapping \n");
	printf("num1 = %d  num2 = %d \n",num1,num2);
	/*----------------------- swapping -----------------------*/
	temp=num1;   // store the value of num1 in temp
	num1=num2;   // store the value of num2 in num1 and lose the value in num1
	num2=temp;   // restore the value of num1 from the temp and put it in num2
	/*--------------------------------------------------------*/
	// printing numbers after swapping
	printf("--------------------------------\n");
	printf("two numbers after swapping \n");
	printf("num1 = %d  num2 = %d \n",num1,num2);


}
