/*
   define the structure to store the infomation of Gcode command
   */

#ifndef GCMD_STRUC_H
#define GCMD_STRUC_H


#include<stdio.h>
#include<stdbool.h>

typedef struct Point{
	float x;
	float y;
	float z;
}Point;


typedef struct Gcmd_struc{
	char cmd_type;  //which kind  of command [ G,M,I,F.....]
	int group_num;	//modal group number
	int motion_mode;	//what kind of motion , linear? circle?
	int non_modal;	//
	int status_code;	//status of this block
	bool inches_mode;	//if true, unit->inches.false,unit->mm
	int  coord_select;	//select coordinate
	int spindle_direction;	//spindle CW or CCW
	int program_st;	//current program status of this block
	float spindle_speed;
	bool inverse_feed_rate_mode;
	int tool;
	float feed_rate;
	float inverse_feed_rate;
	float radius;
	int loop_cnt;
	float P;//parameters
	Point cent;

	Point p;
}Gcmd_struc;

extern Gcmd_struc gc;




#endif
