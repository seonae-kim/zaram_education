#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mode1.h"
#include "mode2.h"
#include "mode4.h"
#include "mode5.h"
#include "mode6.h"
#include "mode7.h"

struct member
{
	char name[20];
	int age;
	char start_date[50];
	char end_date[50];
	int remain_period;
};
			

int main()
{
	int mode = 0;
	int e = 0;
	int i = 0;
	FILE *fp;
	struct member m[50] ;
	char buffer[255] = {0};
	int count = 0;
	/*
	if((fp = fopen("member_info.txt", "r")) == NULL)
	{
		printf("fail\n");
	}
	printf("%d\n",__LINE__);

	while(1)
	{
		if(fgets(buffer, sizeof(buffer), fp) == NULL)
			break;
		char *ptr = strtok(buffer, "\t");
		while(ptr != NULL)
		{
			if(count == 0)
			{
				sprintf(m[i].name,"%s",ptr);
				ptr = strtok(NULL, "\t");
			}
			if(count == 1)
			{
				m[i].age =atof(ptr);
				ptr = strtok(NULL, "\t");
			}
			if(count == 2)
			{
				sprintf(m[i].start_date,"%s",ptr);
				ptr = strtok(NULL, "\t");
			}
			if(count == 3)
			{
				sprintf(m[i].end_date,"%s",ptr);
				ptr = strtok(NULL, "\t");
			}
			if(count==4)
			{
				m[i].remain_period = atof(ptr);
				ptr = strtok(NULL, "\t");
				i++;
			}
			count++;
		}
	}
	*/
	while(1)
	{
		if(e == 1)
			break;

		printf("\n # MEMBERSHIP PROGRAM #\n Select Mode\n 1-Registration\n 2-Extension of the period\n 3-Transfer of membership\n 4-Delete membership\n 5-Search membership \n 6-View all information \n 7-Update all membership \n 8-exit\n");

		scanf("%d", &mode);


		switch(mode)
		{
			case 1:
				mode1(1);
				break;
		
			case 2:
				mode2(1);
				break;

			case 3:
		        break;
	
			case 4:
				mode4(1);
				break;

			case 5:
				mode5(1);
				break;

			case 6:
				mode6(1);
				break;

			case 7:
				mode7(1);
				break;

			case 8:
				printf(" FINISH\n");
				e++;
				break;	

			default :
				e++;
				break;
		}

	}

	return 0;
}
