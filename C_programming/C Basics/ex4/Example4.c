/*
 * Example4.c
 *
 *  Created on: Apr 8, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h> // calling stander input output lib
void main (){
	float n1 , n2 ; // declaring two variables to be reading form user
	printf("enter two numbers : "); // asking user to enter the two numbers
	fflush(stdin);fflush(stdout); //clearing the buffer
	scanf("%f%f",&n1,&n2);//scanning the two number
	printf("the sum is = %f",(n1+n2));// printing the sum to user

}
