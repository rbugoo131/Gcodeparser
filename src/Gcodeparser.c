#include<stdio.h>
#include<string.h>
#include"struc.h"

#define MAX_STRLEN 2000
char cmd[MAX_STRLEN];

Gcmd_struc gc;
int main(void)
{
	FILE *fr;
	char fname[200];
	char cmd_type;

	//printf("Please input the file name:");
	//scanf("%s",fname);
	//fr=fopen(fname,"r");

	while(gets(cmd)!=NULL)
	{
		gc_execute_line(cmd);
	//printf("%c motion= %d group=%d X=%f Y=%f Z=%f F=%d\n",gc.cmd_type,gc.motion_mode,gc.group_num,gc.p.x,gc.p.y,gc.p.z,gc.inverse_feed_rate_mode);
	}

	//fclose(fr);
	return 0;
}
