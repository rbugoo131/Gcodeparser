#include<stdio.h>
#include<string.h>


#define MAX_STRLEN 2000
char cmd[MAX_STRLEN];

int main(void)
{
	FILE *fr;
	char fname[200];
	char cmd_type;

	scanf("%s",fname);
	fr=freopen(fname,"r",stdin);

	//read until end	while(gets(cmd)!=NULL)
	{
		cmd_type=cmd[0];

		switch(cmd_type){
			case 'G':
				break;
			case 'M':
				break;
			default:
				break;
		}

	}

	fclose(fr);
	return 0;
}
