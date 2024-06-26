/*
 * Example4.c : insert element in array
 *
 *  Created on: Apr 13, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h>
int main ()
{
	int array_size;// declare variable to read the size of array from user
	int array [50];// declare an array
	int i ; // counter
	int position; // variable to read the position
	int inserted_number ;//variable to read number to be inserted
	printf("enter the size of array ( smaller than 50 ): "); // asking user to enter the size of array
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&array_size);// scanning array size  from user
	/*------------------- reading values from user -------------------*/
	for(i=0;i<array_size;i++)//loop to go through each element
	{
		printf("element number [%d] : ",i+1); // print to user the number of the element
		fflush(stdin);fflush(stdout);// clearing the buffer
		scanf("%d",&array[i]);// scanning the value from user
	}
	/*----------------------- printing the array before insert the number  -----------------------*/
	for (i=0;i<array_size;i++)
	{
		printf("%d\t",array[i]);
	}

	printf("\n enter the number to be inserted :"); // asking user to enter the number to be inserted
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&inserted_number);// scanning the number from user
	printf("enter the  position :"); // asking user to enter the position
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&position);// scanning the position from user
	/*-------------------- moving array elements to insert the number  --------------------*/
	for (i=array_size-1;i>=position-1;i--) //starting the loop from the last element of array to end with the position
	// note : we read from user position+1 because in line 22 we are printing element number i+1 not i
	{
		array[i+1]=array[i]; // move each element to next slot
	}//now the position is empty

	array[position-1]=inserted_number ; // add the inserted number to the real position ( show note at line 40 )

	/*----------------------- printing the array after insert the number  -----------------------*/
	for (i=0;i<array_size+1;i++) // ending the loop with size+1 because we insert a number
	{
		printf("%d\t",array[i]);
	}
	return 0;
}
