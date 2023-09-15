#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct member
{
    char name[20];
    int age;
    char start_date[50];
    char end_date[50];
    int remain_period;

};

int mode7()
{
    FILE *fp;
    struct member m[50];
	int i = 0 ;
	int period = 0;
	int count = 0;
	char temp_period;
	char buffer[255] = {0};

	fp = fopen("member_info.txt","r+");
	
	if( fp == NULL)
	{
		printf("fail\n");
	}

	printf(" < Update all membership >\n period : ");
    scanf("%d", &period);

	while(1)
    {   
        fgets(buffer, 255, fp);
		
		char *ptr = strtok(buffer, "\t");

		if( ptr == "\t")
		{
			count++;
			if(count == 3)
			{
				temp_period = ptr;
				printf(">%s\n", ptr);

			}
		}

		if(fgets(buffer, 255, fp) == NULL)
		{
			printf(" End\n");
			break;
		}

	}	


}
