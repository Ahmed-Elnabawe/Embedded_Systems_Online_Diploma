/*
 * Pointer_Q2.c
 *
 *  Created on: Jul 9, 2024
 *      Author: Ahmed Elnabawe
 */

#include "stdio.h"
int main()
{
	char alpha [26];
	char *ptr;
	for(int i=0;i<26;i++)
	{
		*(alpha+i)=i+65;
	}
	ptr = alpha;
	for(int i=0;i<26;i++)
	{
		printf("  %c  ",*(ptr+i));
	}
	return 0;
}

