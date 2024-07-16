/*
 * Store_Information_Of_Students_Using_Structure(ex4).c
 *
 *  Created on: Jun 17, 2024
 *      Author: Lenovo
 */

#include <stdio.h> // including stander input output lib
#include <string.h>// including string lib

struct SStudent {  // define a new user define data type "structure"
	char Sname [20];
	int Sroll_number ;
	int Smarks;
	// the struct has three members name , roll and marks of a student
};

int main (void) //main function
{
	struct SStudent s[10] ;// array of struct

	int counter=0;
	for(counter=0;counter<10;counter++) {
		s[counter].Sroll_number=counter+1;
		printf("student of roll number : %d \n",s[counter].Sroll_number);
		// reading informations
		printf("student name  :");
		fflush(stdin);fflush(stdout);//clearing the buffer
		gets(s[counter].Sname);
		printf("student marks :");
		fflush(stdin);fflush(stdout);
		scanf("%d",&s[counter].Smarks);
	}
	// display informations to user
	printf("\n display informations  \n\n");
	for(counter=0;counter<10;counter++)
	{
		printf("---------------------------------\n");
		printf("student of roll number : %d",s[counter].Sroll_number);
		printf("\n student name  : %s \n",s[counter].Sname);
		printf("student marks : %d \n",s[counter].Smarks);
	}
}

