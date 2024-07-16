/*
 * Add_Two_Distances_Using_Struct.c
 *
 *  Created on: Jun 17, 2024
 *      Author: Lenovo
 */


#include <stdio.h> // including stander input output lib

struct SDistance {  // define a new user define data type "structure"

	int SFEEt ;
	float SINCH;
	// the struct has two members one for inch system and the other is to feet system
};

int main (void) //main function
{
	struct SDistance distance1, distance2,sum ;// three objects from a struct
	printf("Enter distance 1  \n\n"); // ask user to enter  informations of distance 1
	// reading informations for distance 1
	printf(" INCH  :");
	fflush(stdin);fflush(stdout);//clearing the buffer
	scanf("%f",&distance1.SINCH);
	printf(" FEET :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&distance1.SFEEt);
	// reading informations for distance 2
	printf("Enter distance 2  \n\n"); // ask user to enter  informations of distance 2
	printf(" INCH  :");
	fflush(stdin);fflush(stdout);//clearing the buffer
	scanf("%f",&distance2.SINCH);
	printf(" FEET :");
	fflush(stdin);fflush(stdout);
	scanf("%d",&distance2.SFEEt);
	sum.SFEEt=distance1.SFEEt+distance2.SFEEt;
	sum.SINCH=distance1.SINCH+distance2.SINCH;
	if(sum.SINCH>12)
	{
		sum.SINCH=sum.SINCH-12;
		sum.SFEEt++;
	}
	// display the sum to user
	printf("the sum of two distance   \n\n");
	printf("sum of inch : %d/'-%.1f/\n",sum.SFEEt,sum.SINCH);

}
