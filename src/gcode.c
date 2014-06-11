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
	int group_number;
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
				printf("int value=%d\n",int_value);
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
