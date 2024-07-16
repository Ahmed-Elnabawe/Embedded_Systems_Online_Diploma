/*
 * Sum_Of_Two_Complex_Using_Struct.c
 *
 *  Created on: Jun 17, 2024
 *      Author: Lenovo
 */


#include <stdio.h> // including stander input output lib

struct SComplex {  // define a new user define data type "structure"

	float  SReal;
	float Simg;
	// the struct has two members one for real number and the other is to complex number
};

int main (void) //main function
{
	struct SComplex Snum1, Snum2 ;// two objects from a struct
	printf("Enter the first number  \n\n"); // ask user to enter the first number
	// reading informations for the first number
	printf(" real  :");
	fflush(stdin);fflush(stdout);//clearing the buffer
	scanf("%f",&Snum1.SReal);
	printf(" imaginary :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&Snum2.Simg);
	printf("Enter the second number  \n\n"); // ask user to enter the second number
	// reading informations for the second number
	printf(" real  :");
	fflush(stdin);fflush(stdout);//clearing the buffer
	scanf("%f",&Snum2.SReal);
	printf(" imaginary :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&Snum2.Simg);

	// display the sum to user
	printf("the sum of two numbers   \n\n");
	printf(" %f + ",(Snum1.SReal+Snum2.SReal));
	printf("%f j \n",(Snum1.Simg+Snum2.Simg));
}
