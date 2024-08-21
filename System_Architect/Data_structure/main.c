/*
 * main.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Lenovo
 */

#include "app.h"
struct Snode* gpFirstStudent = NULL ;
int main()
{

	char temp[10] ;
	while(1)
	{
		Dprintf("====================================");
		Dprintf("\n Chose one of the following options ");
		Dprintf("\n \t Enter 1 to add new student ");
		Dprintf("\n \t Enter 2 to delete student ");
		Dprintf("\n \t Enter 3 to view all student ");
		Dprintf("\n \t Enter 4 to delete all student");
		Dprintf("\n \t Enter 5 to get Nth student");
        Dprintf("\n \t Enter 6 to get length of list");
        Dprintf("\n \t Enter 7 to get Nth student from the end ");
        Dprintf("\n \t Enter 8 to get the middle of list ");

        Dprintf("\n====================================");
        Dprintf("\n option  : ");
        gets(temp);
        Dprintf("\n====================================");


		switch (atoi(temp)) {
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_all();
			break;
		case 4:
			delete_all();
			break;
        case 5:
            get_Nth();
            break;
        case 6:
            int length;
            length=get_length(gpFirstStudent);
            Dprintf("\n the length is %d \n",length);
            break;
        case 7:
            get_Nth_from_end();
            break;
        case 8:
            get_middle();
            break;

		default:
			Dprintf("\n wrong option \n ");
			break;
		}

	}
}


