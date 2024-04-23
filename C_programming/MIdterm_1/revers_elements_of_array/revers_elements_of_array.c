/*
 * revers_elements_of_array.c
 *
 *  Created on: Apr 22, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h> // including stander input output lib
void revers_array(int arr[], int size);//function prototype
int main ()
{
	int arr [50];// array of 50 element
	int size ;//variable to read the size from user
	int i ;// counter for loop
	printf("enter the size of array :");//asking user to enter the size of array
	fflush(stdin);fflush(stdout);c
	scanf("%d",&size);//scanning the value from user
	for (i=0 ;i<size ;i++) // loop at each element in array
	{
		printf("element[%d] : ",i+1);// asking user to enter element of i
		fflush(stdin);fflush(stdout);//clearing the buffer
		scanf("%d",&arr[i]);//scanning the value from user
	}
	revers_array(arr,size);//calling the function
}
void revers_array(int arr[], int size)//function definition
{
	int i ;//counter for loop
	for(i=size-1;i>=0;i--)//loop at each element in array put from the end
	{
		printf("%d ",arr[i]);//print the last element in array
	}
}
