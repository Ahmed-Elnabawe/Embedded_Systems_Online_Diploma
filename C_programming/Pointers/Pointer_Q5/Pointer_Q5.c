/*
 * Pointer_Q5.c
 *
 *  Created on: Jul 9, 2024
 *      Author: Ahmed Elnabawe
 */

struct se
{
	char* name;
	int salary;
};

#include"stdio.h"
int main()
{
	struct se em1 ={"ali",40},em2={"mohamed",34},em3={"ahmed",54};
	struct se *arr[]={&em1,&em2,&em3};
	struct se * (*ptr)[]=&arr;
	printf("%s with dot operator\n",(**(*ptr+1)).name);
	printf("%s with point operator\n",(*(*ptr+1))->name);
	printf("%d with dot operator\n",(**(*ptr+1)).salary);
	printf("%d with point operator\n",(*(*ptr+1))->salary);

}
