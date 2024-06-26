/*
 * Example3.c : program to find transpose matrix
 *
 *  Created on: Apr 13, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h>
int main ()
{
	int rows , colons;// two variables to read the number of rows and colons from user
	int original_matrix [50][50];// the original matrix
	int transpose_matrix [50][50];// the transpose matrix
	int i , j;// two counters for loops
	printf("enter the number of rows and colons : ");//asking user to enter the number of rows and colons
	fflush(stdin);fflush(stdout);//clearing the buffer
	scanf("%d%d",&rows,&colons);//scanning the values from user
	/*---------------------- reading the original matrix from user ----------------------*/
	printf("enter the element of original matrix \n"); //asking user to enter the original matrix
	for(i=0;i<rows;i++) // making for loop to go through the rows of the matrix
	{
		for(j=0;j<colons;j++)// making for loop to go through the colons of the matrix
		{
			printf("a[%d,%d] = ",i+1,j+1); // print to user the location of the element
			fflush(stdin);fflush(stdout);// clearing the buffer
			scanf("%d",&original_matrix[i][j]);// scanning the value from user
		}
	}
	/*---------------------- printing the entered matrix to user ----------------------*/
	printf("the entered matrix is \n");
	for(i=0;i<rows;i++) // making for loop to go through the rows of the matrix
	{
		for(j=0;j<colons;j++)// making for loop to go through the colons of the matrix
		{
			printf("%d\t",original_matrix[i][j]); // print to user each element of the original matrix

		}
		printf("\n");// print new line
	}
	/*---------------------- building the transpose matrix ----------------------*/
	for(i=0;i<rows;i++) // making for loop to go through the rows of the matrix
	{
		for(j=0;j<colons;j++)// making for loop to go through the colons of the matrix
		{
			transpose_matrix[j][i]=original_matrix[i][j]; // reverse the positions for the original matrix and set the result in the transpose matrix
		}
	}
	/*---------------------- printing the transpose matrix to user ----------------------*/
	printf("the transpose matrix is \n");
	for(i=0;i<colons;i++) // making for loop to go through the rows of the transpose matrix(the colons of the original matrix)
	{
		for(j=0;j<rows;j++)// making for loop to go through the colons of the transpose matrix(the rows of the original matrix)
		{
			printf("%d\t",transpose_matrix[i][j]); // print to user each element of the transpose matrix

		}
		printf("\n");// print new line
	}
	return 0;
}
