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


int mode1()
{
	FILE *fp;
	struct member m[50];
	int period = 0;
	char name[20] = {0};
	int age = 0;
	int i ;
	int line = 0;
	char buffer[2550] = {0};
	int count = 0;

	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	
	while(1)
	{
		if (count == 1)
		break;
		
		printf("\n< New member registration > \n name, age, period: ");
		scanf("%s %d %d", name, &m[i].age, &m[i].remain_period);
		
		if((fp = fopen("member_info.txt", "a+")) == NULL) 
		{
			printf("fail\n");
		}	

		while (fgets(buffer,sizeof(buffer),fp) != NULL)
		{
			char *ptr = strstr(buffer, name);

				if(ptr != NULL)
				{	
					count = 1;
					printf("\n Try Again\n");
					count++;
					printf("%d\n", __LINE__);
					break;
				}	
				else
				
					printf("%d\n", __LINE__);
					
					count = 1;
					sprintf(m[i].name, "%s", name);
					
					sprintf(m[i].start_date,"%d-%d-%d %d:%d",tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
					
					tm.tm_mon += period;
					mktime(&tm);

					sprintf(m[i].end_date,"%d-%d-%d %d:%d",tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
					fprintf(fp,"%s	%d	%s	%s	%d\n", m[i].name, m[i].age, m[i].start_date, m[i].end_date , m[i].remain_period);
					line++;
					i++;
					
					printf("\n Registration Complete\n");
					break;
				
		}
	}
		for( int j = 0; j < i; j ++)
		{
			printf("%d %d\n", __LINE__, m[j].age);

		}
		fclose(fp);
		return 0;
}

	

