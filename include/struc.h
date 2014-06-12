/*
   define the structure to store the infomation of Gcode command
   */

#ifndef GCMD_STRUC_H
#define GCMD_STRUC_H


#include<stdio.h>
#include<stdbool.h>

typedef struct Point{
	double x;
	double y;
}Point;


typedef struct Gcmd_struc{
	char cmd_type;
	int group_num;
	int motion_mode;
	int non_modal;
	int status_code;
	bool inches_mode;	
	int  coord_select;
	int spindle_direction;
	int program_st;
	
}Gcmd_struc;

extern Gcmd_struc gc;




#endif
