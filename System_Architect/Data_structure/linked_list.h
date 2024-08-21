
/*
 * linked_list_student.h
 *
 *  Created on: Aug 17, 2024
 *      Author: Lenovo
 */

#ifndef LINKED_LIST_STUDENT_H_
#define LINKED_LIST_STUDENT_H_
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define Dprintf(...) {  fflush(stdin);\
						fflush(stdin);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdin);}


// struct for the main data of the student
typedef struct {
	int id ;
	char name[40];
	float height ;
}Sdata_t;
// node struct
struct Snode {
	Sdata_t data ;
	struct Snode * next;
};
// APIs
void fill__rew_recored ();
void add_student();
int delete_student();
void view_all ();
void delete_all();
void get_Nth();
int get_length( struct Snode*);
void get_Nth_from_end();
void get_middle();
#endif /* LINKED_LIST_STUDENT_H_ */

