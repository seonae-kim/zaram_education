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
	FILE *fout;
	struct member m[50];
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	char buffer[255] = {0};
	char user[20] = {0};
	int period = 0;
	int count = 0;
	char *ptr = {0}; 
	int i = 0;
	int line = 0;
   
	if((fp = fopen("member_info.txt", "r")) == NULL)
	{
		printf("fail\n");
	}

	while(fgets(buffer, sizeof(buffer), fp) != NULL)
	{
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
			/*else
			{
				ptr = strtok(NULL, "\t");
				i++;
			}*/
			count++;
		}
	}
	fclose(fp);

	printf(" < Update all membership >\n period : ");
    scanf("%d", &period);
	
	fp = fopen("member_info.txt", "r");
	fout = fopen ("exchange.txt", "w");
	if(fp == NULL)
    {
        printf("fail1\n");
    }
	if(fout == NULL)
    {
        printf("fail2\n");
    }

		while(fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		m[line].remain_period += period;
		tm.tm_mon += m[line].remain_period;
		mktime(&tm);
			
		sprintf(m[line].end_date, "%d-%d-%d %d:%d", 
				tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
			
		fprintf(fout,"%s	%d	%s	%s	%d\n",
				 m[line].name, m[line].age, m[line].start_date, m[line].end_date , m[line].remain_period);
		
		//printf("%s  %d  %s  %s  %d\n",
		//		m[line].name, m[line].age, m[line].start_date, m[line].end_date , m[line].remain_period);
		line++;
	}

	fclose(fp);
	fclose(fout);
	remove("member_info.txt");
	rename("exchange.txt", "member_info.txt");
	
	printf(" Success\n");
	return 0;
}




