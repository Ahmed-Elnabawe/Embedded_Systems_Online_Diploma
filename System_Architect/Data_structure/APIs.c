
/*
 * APIs.c
 *
 *  Created on: Aug 17, 2024
 *      Author: Lenovo
 */

#include "app.h"
extern struct Snode* gpFirstStudent;

// fill the new recored for new student
void fill__rew_recored (struct Snode*new_student){
	char temp_text [40];
	Dprintf("\n\t Enter ID : ");
	gets(temp_text);
	new_student->data.id=atoi(temp_text);

	Dprintf("\t Enter name : ");
	gets(new_student->data.name);

	Dprintf("\t Enter height : ");
	gets(temp_text);
	new_student->data.height=atof(temp_text);
}
void add_student(){

    struct Snode* pnewStudent;
	struct Snode* pLaststudent;

	if (gpFirstStudent==NULL)
	{
        pnewStudent = (struct Snode*)malloc(sizeof(struct Snode));
		gpFirstStudent=pnewStudent;
	}
	else
	{
		pLaststudent=gpFirstStudent;
		// navigate to the last element
		while(pLaststudent->next)
			pLaststudent=pLaststudent->next ;
        pnewStudent = (struct Snode*)malloc(sizeof(struct Snode));
		pLaststudent->next=pnewStudent;
	}
    fill__rew_recored(pnewStudent);
	pnewStudent->next=NULL;



}
int delete_student(){


	char temp [40];
	int selected_id ;
		if (gpFirstStudent==NULL) {
		Dprintf("\n empty list \n ");
		return 0;
	}
	Dprintf("\n enter the id to be deleted : ");
	gets(temp);
	selected_id=atoi(temp);

	struct Snode* Pselected = gpFirstStudent ;
	struct Snode* Pprev = NULL;
	if (Pselected)// list have a records
	{
		while(Pselected)
		{

			if (Pselected->data.id==selected_id)
			{

				if (Pprev)
				{
					Pprev->next=Pselected->next;
				}
				else
				{
					gpFirstStudent=Pselected->next;
				}

				free(Pselected);
				return 1;

			}
			Pprev=Pselected;
			Pselected=Pselected->next;
		}
	}
	Dprintf("\n this id is not found ! \n");
	return 0;
}
void view_all (){
	struct Snode* ploop = gpFirstStudent ;
	int counter=0 ;
	if (gpFirstStudent==NULL) {
		Dprintf("\n empty list \n ");
	}
	while(ploop)
	{

		Dprintf("\n student  : %d ",counter+1);
		Dprintf("\n ID : %d ",ploop->data.id);
		Dprintf("\n name : %s ",ploop->data.name);
		Dprintf("\n height : %f \n",ploop->data.height);
		ploop=ploop->next;
		counter ++;
	}
}
void delete_all(){
	struct Snode * pCurrent = gpFirstStudent;
	struct Snode * ptemp = NULL;
	if (gpFirstStudent==NULL) {
		Dprintf("\n empty list \n ");
	}
	while(pCurrent){
		ptemp=pCurrent;
		pCurrent=pCurrent->next;
		free(ptemp);
	}
	gpFirstStudent=NULL;
}
void get_Nth(){
    if(gpFirstStudent==NULL)
    {
       Dprintf("\n empty list \n");
    }
    else
    {
        int Nth;
        char temp[10];
        Dprintf("\n enter the index to be find: ");
        gets(temp);
        Nth=atoi(temp);
        int counter=0;
        struct Snode * pNth = gpFirstStudent;
        while(pNth)
        {
            if(counter == Nth)
                {
                    Dprintf("\n ID : %d ",pNth->data.id);
                    Dprintf("\n name : %s ",pNth->data.name);
                    Dprintf("\n height : %f \n",pNth->data.height);
                    break;
                }
            counter++;
            pNth=pNth->next;
        }
        if(!pNth)  Dprintf("\n not found \n");

    }
}

int get_length( struct Snode* head ){
   if(!head)
        return 0;
    else
        return (1 + get_length(head->next));
}





void get_Nth_from_end(){


    struct Snode * p_main = gpFirstStudent;
    struct Snode * p_ref = gpFirstStudent;
    int counter=0 ;
    int Nth_end;
    char temp[10];
    if(gpFirstStudent==NULL)
    {
       Dprintf("\n empty list \n");
    }
    else
        {
        Dprintf("\n enter the index from the end to be find: ");
        gets(temp);
        Nth_end=atoi(temp);
        if(get_length(gpFirstStudent)>Nth_end)
            {
                while(Nth_end>counter)
                {
                    p_ref=p_ref->next;
                    counter++;
                }
                while(p_ref->next)
                {
                    p_main=p_main->next;
                    p_ref=p_ref->next;
                }
                Dprintf("\n ID : %d ",p_main->data.id);
                Dprintf("\n name : %s ",p_main->data.name);
                Dprintf("\n height : %f \n",p_main->data.height);

            }
            else
            {
                Dprintf("\n enter a valid index \n");
            }
        }

}
void get_middle(){
   if(gpFirstStudent==NULL)
   {
       Dprintf("\n empty list \n");
   }
   else
   {
        struct Snode * p_mid = gpFirstStudent;
        struct Snode * p_ref = gpFirstStudent;
        while(p_ref->next&&p_ref->next->next)
        {
            p_ref=p_ref->next->next;
            p_mid=p_mid->next;
        }
        if(get_length(gpFirstStudent)%2==0)
            p_mid=p_mid->next;
        Dprintf("\n ID : %d ",p_mid->data.id);
        Dprintf("\n name : %s ",p_mid->data.name);
        Dprintf("\n height : %f \n",p_mid->data.height);
   }

}

