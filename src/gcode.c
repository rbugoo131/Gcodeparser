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
				//set group
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
