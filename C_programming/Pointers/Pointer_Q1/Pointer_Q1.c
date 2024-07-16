/*
 * Pointer_Q1.c
 *
 *  Created on: Jul 9, 2024
 *      Author: Ahmed Elnabawe
 */

#include "stdio.h"

int main()
{
	int m=29;
	int *ab;
	printf("address of m = %x \n",&m);
	printf("value of m = %d \n",m);
	printf("---------------------------\n");
	ab = &m;
	printf("now ab is pointing to address of m\n");
	printf("address of pointer ab %x \n",ab);
	printf("content of pointer ab %d \n",*ab);
	printf("---------------------------\n");
	m=34;
	printf("now m = 34\n");
	printf("address of pointer ab %x \n",ab);
	printf("content of pointer ab %d \n",*ab);
	printf("---------------------------\n");
	*ab=7;
	printf("now content of pointer ab = 7\n");
	printf("address of m = %x \n",&m);
	printf("value of m = %d \n",m);
	return 0;
}
