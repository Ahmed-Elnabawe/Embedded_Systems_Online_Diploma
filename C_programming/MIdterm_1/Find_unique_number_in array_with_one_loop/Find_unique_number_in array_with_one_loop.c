/*
 * Find_unique_number_in array_with_one_loop.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Ahmed Elnabawe
 */
#include <stdio.h> // including stander input output lib
int find_unique(int arr [],int size);// function prototype
int main ()
{
	int array []={4,2,5,2,5,7,4};// array
	int size=sizeof(array)/sizeof(array[1]) ; // variable to save size of array
	printf("unique number :%d ",find_unique(array,size));//print the out put for user
	return 0 ;
}
int find_unique(int arr [],int size)//function definition
{
	int result=0; // define a variable to save the result
	int i ;//counter for loop
	for (i=0;i<size;i++) //check each element in array
	{
		result^=arr[i];//make XOR with each element in array and result because XOR is repeated operation
	}
	return result;//return the result to main
}
