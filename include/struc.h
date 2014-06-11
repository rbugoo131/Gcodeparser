/*
   define the structure to store the infomation of Gcode command
   */

#ifndef GCMD_STRUC_H
#define GCMD_STRUC_H


#include<stdio.h>

typedef struct Point{
	double x;
	double y;
}Point;


typedef struct Gcmd_struc{
	char cmd_type;
	int G_group;
	int counter;
	int status_code;

}Gcmd_struc;

extern Gcmd_struc gc;




#endif
