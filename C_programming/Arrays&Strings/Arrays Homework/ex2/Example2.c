/*
 * Example2.c : calculating average using Arrays
 *
 *  Created on: Apr 12, 2024
 *      Author: Ahmed Elnabawe
 */

#include <stdio.h> // including stander input output lib
int main()
{
	float arr[100]; // array to get the values from user
	int i ; // counter
	int n; // declaring variable to read the number of values from user
	float sum=0; // declaring a variable to calculate the sum
	printf("enter the number of values ( smaller than 100 ): "); // asking user to enter the number of values
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&n);// scanning number of values from user
	/*------------------- reading values from user -------------------*/
	for(i=0;i<n;i++)//loop to go through each element
	{
		printf("element number [%d] : ",i+1); // print to user the number of the element
		fflush(stdin);fflush(stdout);// clearing the buffer
		scanf("%f",&arr[i]);// scanning the value from user
	}
	/*------------------ calculating the sum ------------------*/
	for(i=0;i<n;i++) //loop to go through each element
	{
		sum+=arr[i]; // adding the value of each element to the sum
	}
	printf("the average is = %f ",(sum/n)); // printing the average to the user
	return 0;
}
