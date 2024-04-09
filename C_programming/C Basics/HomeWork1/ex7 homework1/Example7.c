/*
 * Example7.c
 *
 *  Created on: Apr 8, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h> //calling the stander input output lib
void main (){

	int num1, num2; // declaring to variable to store values from user
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
	num1=num1+num2; // store the sum of the two numbers in num1
	num2=num1-num2; // now num2 = num1-num2 which mean num2=(num1+num2)-num2 = num1
	// now num1 is still store the value of the sum and the num2 is store the value of the original num1
	num1=num1-num2; // now num1=num1(sum of two numbers)-num2(original value of num1)= original value of num2 which mean num1=original value of num2
	/*--------------------------------------------------------*/
	// printing numbers after swapping
	printf("--------------------------------\n");
	printf("two numbers after swapping \n");
	printf("num1 = %d  num2 = %d \n",num1,num2);


}
