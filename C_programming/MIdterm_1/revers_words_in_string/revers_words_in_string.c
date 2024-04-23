/*
 * revers_words_in_string.c
 *
 *  Created on: Apr 23, 2024
 *      Author: Ahmed Elnabawe
 */


#include <stdio.h>// including stander input output lib
#include <string.h>// including string lib
int main ()
{

	char string [20][50]; //declaring two dimensional array each row represents a name
	int i ;//counter for loop
	int size;// variable to read the size from user
	printf("enter the number of words : ");// asking user to enter the number of words
	fflush(stdin);fflush(stdout);// clearing the buffer
	scanf("%d",&size);//scanning the size form user
	for (i=0;i<size;i++) //loop at each row into two dimensional array
	{
		printf("word[%d]:" ,i+1);//asking user to enter the word
		fflush(stdin);fflush(stdout);//clearing the buffer
		scanf("%s",string[i]);//scanning the word from user
	}
	for (i=size-1;i>=0;i--)//loop at each word starting from the end
			{
				printf("%s ",string[i]);//print the last word in first
			}
	return 0;

}

