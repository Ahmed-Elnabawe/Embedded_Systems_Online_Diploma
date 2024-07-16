/*
 * Pointer_Q3.c
 *
 *  Created on: Jul 9, 2024
 *      Author: Ahmed Elnabawe
 */
#include "stdio.h"
int main()
{
	int i =0;
	char str[50];
	char strv[50];
	char* ptr=str;
	char* ptrv=strv;
	printf("enter the string : ");
	fflush(stdin);fflush(stdout);
	scanf("%s",str);
	while(*ptr)
	{
		ptr++;
		i++;
	}
	while(i>0)
	{
		ptr --;
		*ptrv=*ptr;
		ptrv ++;
		i--;
	}
	*ptrv='\0';
	printf("the reversed string : %s",strv);
	return 0;
}



