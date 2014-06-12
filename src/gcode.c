#include<stdio.h>
#include<string.h>
#include<math.h>
#include"gcode.h"
#include"struc.h"

//fill in the status
#define FILL_ST(status) gc.status_code=status;

Gcmd_struc gc;

//read input->line
//if input is a valid command ,return 1 . 
//else return 0

int  gc_execute_line(char *line)
{
	//if not a useful command
	if(!(line[0]>='A' && line[0]<='Z')) return 0;
	
	char cmd_type;
	char letter;
	float f_value;
	int int_value;
	int line_cnt=0;
<<<<<<< HEAD
	int group_number;
=======
	int group_number;	//Note: one block can contain G-cmd of different modal-group
						//But with same group,only last G-cmd is valid
						//group 00 has no continuous ability
	
	int non_modal_action=gc.non_modal=NON_MODAL_NONE;// track action of group 0
	
>>>>>>> f3c5b44682272cc2f200c3828e1625e7e4599495
	/*Parse 1: parse commands and set all modes.
	 check group violation?
	 */

	while(parse_word(&cmd_type,&f_value,line,&line_cnt))
	{
		int_value=trunc(f_value);

		switch(cmd_type)
		{
			case 'G':
				gc.cmd_type='G';
				printf("G command");
<<<<<<< HEAD
				printf("int value=%d\n",int_value);
=======
				printf(" value=%d\n",int_value);
>>>>>>> f3c5b44682272cc2f200c3828e1625e7e4599495
				//set modal group
				//什麼樣的int_value不重要？重要的是移動模式?
				switch(int_value)
				{
					case 4: case 10: case 27: case 28: case 30: case 53: case 70: case 71:case 72: case 73: case 74: case 75: case 76: case 92:	group_number=gc.group_num=MODAL_GROUP_0;	break;
					case 0: case 1: case 2: case 3: case 32: case 80: case 90: case 94: group_number=gc.group_num=MODAL_GROUP_1;	break;
					case 17: case 18: case 19: case 96: case 97: group_number=gc.group_num=MODAL_GROUP_2; break;
					case 91: group_number=gc.group_num=MODAL_GROUP_3; break;
					case 93: case 98: case 99: group_number=gc.group_num=MODAL_GROUP_5; break;
					case 20: case 21:	group_number=gc.group_num=MODAL_GROUP_6;	break;
					case 40: case 41: case 42:	group_number=gc.group_num=MODAL_GROUP_7;	break;
					case 54: case 55: case 56: case 57: case 58: case 59: group_number=gc.group_num=MODAL_GROUP_12; break;

				}

				//set G's command
				switch(int_value)
				{

<<<<<<< HEAD
				}
				break;
			case 'M':
				printf("M command\n");
				break;
		}

		//parse for parameters
		while(parse_word(&letter,&f_value,line,&line_cnt))
		{
		}
=======
					case 0:	gc.motion_mode	=	MOTION_MODE_SEEK;		break;
					case 1:	gc.motion_mode	=	MOTION_MODE_LINEAR; 	break;
					case 2:	gc.motion_mode	=	MOTION_MODE_CW_ARC; 	break;
					case 3:	gc.motion_mode	=	MOTION_MODE_CCW_ARC;	break;
					case 4:	non_modal_action	=	NON_MODAL_DWELL;	break;
					case 10:	non_modal_action	=	NON_MODAL_SET_COORDINATE_DATA; break;
					case 20:	gc.inches_mode =	true;	break;	//inches
					case 21:	gc.inches_mode	=	false;	break;	//millimeters
					//keep to set hone command
					case 54: case 55: case 56: case 57: case 58: case 59:	//set coordinate
								gc.coord_select=int_value-53;
								break;
					case 80: gc.motion_mode	=	MOTION_MODE_CANCEL;	break;
					default: FILL_ST(STATUS_UNSUPPORTED_STATEMENT);
				}
				break;
			case 'M':
				printf("M command");
				printf(" value=%d\n",int_value);
				switch(int_value)
				{
					case 0: gc.program_st=PROGRAM_FLOW_PAUSED; break;
					case 1: break; //optional stop
					case 2: case 30: gc.program_st=PROGRAM_FLOW_COMPLETED; break;
					case 3:	gc.spindle_direction = 1; break;//clockwise
					case 4: gc.spindle_direction = -1; break;//counter clockwise
					case 5:	gc.spindle_direction = 0; break;//stop
					default: FILL_ST(STATUS_UNSUPPORTED_STATEMENT);
					break;
				}
		}

		//any error,all status code>0 is an error
		if(gc.status_code) return gc.status_code;

		//Parse2: parameters
		while(parse_word(&letter,&f_value,line,&line_cnt))
		{
			switch(letter)
			{
				//hereby ignore?
				case 'G': case 'M': case 'N': break;
				case 'F':
					break;
				case 'X':
					break;
				case 'Y':
					break;
				case 'Z':
					break;
				default:FILL_ST(STATUS_UNSUPPORTED_STATEMENT);
			}
		}
		
		//should put in the while loop
		if(gc.status_code) return gc.status_code;
>>>>>>> f3c5b44682272cc2f200c3828e1625e7e4599495
	}

	return 1;
}


//each block command is consist of several words
//parse a word once at a time
//Return 1 if there exist an useful word otherwise return 0.
int  parse_word(char *letter ,float *ptr_float,char *line, int *line_cnt)
{
	//no more word
	if(line[*line_cnt]==0) return 0;	
	
	*letter=line[*line_cnt];
	//not an useful command
	if( (*letter<'A') || (*letter>'Z') )
	{
		FILL_ST(STATUS_UNEXPECTED_COMMAND_LETTER);
		return 0;
	}
	(*line_cnt)++;
	
	//Read floatnumber
	if(!read_float(line,line_cnt,ptr_float))
	{
		FILL_ST(STATUS_BAD_NUMBER_FORMAT);
		return 0;
	}
	return 1;
}
