/*
 * Example5.c : find element in array
 *
 *  Created on: Apr 13, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h>
int main ()
{
	int searched_element; // variable to read the value to be searched from user
	int array[50] ;// an array to save some data from user
	int i ; // counter
	int array_size;// variable to read array size from user
	int found; // variable to check if the element is found or not
	int position;// variable to save the position of founded element
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
	printf("enter the value to be searched : "); // asking user to enter the value to be searched
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&searched_element);// scanning value from user

	/*------------------- searching into array -------------------*/
	found=0; // initialize found variable to be check after loop
	for (i=0;i<array_size ; i++)
	{
		if(array[i]==searched_element)
		{
			found=1;//saving value of 1 to be checked after the loop
			position=i+1; // saving the position of the element
			break; // break from the loop if we found the element
		}
	}
	/*------------------------- printing the result to user -------------------------*/
	if(found==1) printf("%d is found in position %d",searched_element , position);
	else printf("%d is not found",searched_element);
	return 0;
}

