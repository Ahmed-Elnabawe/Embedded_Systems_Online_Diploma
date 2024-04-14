/*
 * Example1.c : sum of two matrix of order 2*2
 *
 *  Created on: Apr 12, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h> // including stander input output lib

void main ()
{
	float matrix_a [2][2]; // declaring the first matrix
	float matrix_b [2][2]; // declaring the second matrix
	float matrix_sum [2][2]; // declaring a matrix to save the sum in it
	int i,j; // two variables to be counters
	/*---------------------- reading the first matrix from user ----------------------*/
	printf("enter the element of 1st matrix \n"); //asking user to enter the first matrix
	for(i=0;i<2;i++) // making for loop to go through the rows of the matrix
	{
		for(j=0;j<2;j++)// making for loop to go through the colons of the matrix
		{
			printf("a[%d,%d] = ",i+1,j+1); // print to user the location of the element
			fflush(stdin);fflush(stdout);// clearing the buffer
			scanf("%f",&matrix_a[i][j]);// scanning the value from user
		}
	}
	/*---------------------- reading the second matrix from user ----------------------*/
	printf("enter the element of 2nd matrix \n"); //asking user to enter the second matrix
	for(i=0;i<2;i++) // making for loop to go through the rows of the matrix
	{
		for(j=0;j<2;j++)// making for loop to go through the colons of the matrix
		{
			printf("b[%d,%d] = ",i+1,j+1); // print to user the location of the element
			fflush(stdin);fflush(stdout);// clearing the buffer
			scanf("%f",&matrix_b[i][j]);// scanning the value from user
		}
	}
	/*---------------------- making the sum  ----------------------*/
	for(i=0;i<2;i++) // making for loop to go through the rows of the matrix
	{
		for(j=0;j<2;j++)// making for loop to go through the colons of the matrix
		{
			matrix_sum[i][j]=matrix_a[i][j]+matrix_b[i][j]; // adding the values of the same locations in the two matrix and set the result in the same location in the sum matrix
		}
	}
	/*---------------------- printing the result to user ----------------------*/
	printf("the result of sum  \n");
	for(i=0;i<2;i++) // making for loop to go through the rows of the matrix
	{
		for(j=0;j<2;j++)// making for loop to go through the colons of the matrix
		{
			printf("%f\t",matrix_sum[i][j]); // print to user each element of sum

		}
		printf("\n");// print new line
	}
}
