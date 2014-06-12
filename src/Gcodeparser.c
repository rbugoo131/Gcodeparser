#include<stdio.h>
#include<string.h>


#define MAX_STRLEN 2000
char cmd[MAX_STRLEN];

int main(void)
{
	FILE *fr;
	char fname[200];
	char cmd_type;
	
	printf("Please input the file name:");
	//scanf("%s",fname);
	//fr=fopen(fname,"r");
	
	while(gets(cmd)!=NULL)
	{
		gc_execute_line(cmd);
	}
	
	//fclose(fr);
	return 0;
}
