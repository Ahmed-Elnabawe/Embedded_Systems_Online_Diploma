/*
 * Example2.c : calculating average using Arrays
 *
 *  Created on: Apr 12, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> // including stander input output lib
void main()
{
	float arr[100]; // array to get the values from user
	int i ; // counter
	int n; // declaring variable to read the number of values from user
	float sum=0;
	printf("enter the number of values ( smaller than 100 ): "); // asking user to enter the nuber of values
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&n);// scanning number of values from user
	/*------------------- reading values from user -------------------*/
	for(i=0;i<n;i++)
	{
		printf("element number [%d] : ",i+1); // print to user the number of the element
		fflush(stdin);fflush(stdout);// clearing the buffer
		scanf("%f",&arr[i]);// scanning the value from user
	}
	/*------------------ calculating the sum ------------------*/
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	printf("the average is = %f ",(sum/n));
}
