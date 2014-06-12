#include<stdio.h>
#include<string.h>
<<<<<<< HEAD

=======
#include"struc.h"
>>>>>>> f3c5b44682272cc2f200c3828e1625e7e4599495

#define MAX_STRLEN 2000
char cmd[MAX_STRLEN];

<<<<<<< HEAD
=======
Gcmd_struc gc;
>>>>>>> f3c5b44682272cc2f200c3828e1625e7e4599495
int main(void)
{
	FILE *fr;
	char fname[200];
	char cmd_type;
<<<<<<< HEAD
	
	printf("Please input the file name:");
	//scanf("%s",fname);
	//fr=fopen(fname,"r");
	
	while(gets(cmd)!=NULL)
	{
		gc_execute_line(cmd);
	}
	
=======

	printf("Please input the file name:");
	//scanf("%s",fname);
	//fr=fopen(fname,"r");

	while(gets(cmd)!=NULL)
	{
		gc_execute_line(cmd);
		printf("motion_mode= %d group=%d\n",gc.motion_mode,gc.group_num);
	}

>>>>>>> f3c5b44682272cc2f200c3828e1625e7e4599495
	//fclose(fr);
	return 0;
}
