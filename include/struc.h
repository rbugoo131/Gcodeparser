/*
   define the structure to store the infomation of Gcode command
   */

#ifndef GCMD_STRUC_H
#define GCMD_STRUC_H


#include<stdio.h>
<<<<<<< HEAD
=======
#include<stdbool.h>
>>>>>>> f3c5b44682272cc2f200c3828e1625e7e4599495

typedef struct Point{
	double x;
	double y;
}Point;


typedef struct Gcmd_struc{
	char cmd_type;
	int group_num;
	int motion_mode;
<<<<<<< HEAD
	int counter;
	int status_code;

=======
	int non_modal;
	int status_code;
	bool inches_mode;	
	int  coord_select;
	int spindle_direction;
	int program_st;
	
>>>>>>> f3c5b44682272cc2f200c3828e1625e7e4599495
}Gcmd_struc;

extern Gcmd_struc gc;




#endif
