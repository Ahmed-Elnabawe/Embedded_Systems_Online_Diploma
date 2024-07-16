/*
 * Store_Information_Of_Student_Using_Structure.c
 *
 *  Created on: Jun 17, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> // including stander input output lib
#include <string.h>// including string lib

struct SStudent {  // define a new user define data type "structure"
	char Sname [20];
	float Sroll_number ;
	int Smarks;
	// the struct has three members name , roll and marks of a student
};

int main (void) //main function
{
	struct SStudent s ;// an object from a struct
	printf("Enter information of the student \n\n"); // ask user to enter  informations of the student
	// reading informations
	printf("student name  :");
	fflush(stdin);fflush(stdout);//clearing the buffer
	gets(s.Sname);
	printf("student roll number :");
	fflush(stdin);fflush(stdout);
	scanf("%f",&s.Sroll_number);
	printf("student marks :\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&s.Smarks);
	// display informations to user
	printf("display informations  \n\n");
	printf("student name  : %s \n",s.Sname);
	printf("student roll number : %f \n",s.Sroll_number);
	printf("student marks : %d \n",s.Smarks);
}
