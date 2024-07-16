/*
 * Pointer_Q4.c
 *
 *  Created on: Jul 9, 2024
 *      Author: Ahmed Elnabawe
 */
#include"stdio.h"
int main()
{
	int arr_size ;
	int i ;
	int arr[15];
	int *ptr;
	ptr=arr;
	printf("enter the array size : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&arr_size);
	for(i=0;i<arr_size ;i++)
	{
		printf("element %d :  ", i+1 );
		fflush(stdin);fflush(stdout);
		scanf("%d",&*(ptr+i));
	}
	printf("------------------------------\n" );
	ptr=ptr+arr_size;
	for(i=arr_size;i>0;i--)
	{
		ptr--;
		printf("element %d : %d \n", i , *ptr);
	}
	return 0;
}
