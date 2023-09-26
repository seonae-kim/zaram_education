#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

#define DAY 50
#define NAME 20
#define AGE 5
#define PERIOD 5

int main()
{
	int e = 0;
	int i = 0;
	int p = 0;
	FILE *fp;
	struct member data[50] ;
	struct node node;
	char buffer[255] = {0};
	int count = 0;
	char name[NAME], start_date[DAY], end_date[DAY];
	int age, remain_period, period;
	char user[NAME] = {0}, giver[NAME] = {0}, receiver[NAME] = {0};
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int end_year = 0;
	int end_mon = 0;
	int end_day = 0;
	int end_hour = 0;
	int end_min = 0;
	int name_flag=0;
	char age_ch[AGE] = {0, };
	char period_ch[5] = {0, };
	char mode[3] = {0, };
	int flag = 0;


	printf("\n");
	fp = fopen("member_info.txt", "r");
	if(fp == NULL)
	{			
		printf("no file to read\n");
	}
	else
	{		
		while(1)
    	{		
  	    if(fgets(buffer, sizeof(buffer), fp) == NULL)
    	    {
				break;
			}
			count = 0;
    	    char *ptr = strtok(buffer, "\t");
    	    while(ptr != NULL)
    	    {   
				if(count == 0)
    	        {
    	            sprintf(name,"%s",ptr);
    	            ptr = strtok(NULL, "\t");
    	        }
				else if(count == 1)
    	        {
    	            age =atof(ptr);
    	            ptr = strtok(NULL, "\t");
    	        }
				else if(count == 2)
    	        {
    	            sprintf(start_date,"%s",ptr);
    	            ptr = strtok(NULL, "\t");
    	        }
				else if(count == 3)
    	        {
    	            sprintf(end_date,"%s",ptr);
    	            ptr = strtok(NULL, "\t");
    	        }
				else if(count == 4)
    	        {
    	            remain_period = atof(ptr);
    	            ptr = strtok(NULL, "\t");
    	        }
				else
				{
					ptr = strtok(NULL, "\t");
				}	
				
				count++;
    	    }
		
				insertend(name, age, start_date, end_date, remain_period);

    	}
		fclose(fp);
	}


	while(1)
	{
		if(e == 1)
			break;
		
		printf("\n # MEMBERSHIP PROGRAM #\n Select Mode\n 1-Registration\n 2-Extension of the period\n 3-Transfer of membership\n 4-Delete membership\n 5-Search membership \n 6-View all information \n 7-Update all membership \n 8-Save\n 9-exit & save\n");

		scanf("%s", mode);
		while (getchar() != '\n');
		if(!(atoi(mode) > 0 && atoi(mode) < 10))
		{
			printf("num 1 to 9\n");
			continue;
		}
		for(i = 0; i < strlen(mode); i++)
		{
			if((int)mode[i] > 96 && (int)mode[i] < 123)
			{
				printf("no char\n");
				continue;
			}
		}
		
		switch(atoi(mode))
		{
			case 1:
				while(1)
				{
					flag=0;
					name_flag=0;

					memset(name,'\0',NAME);
					memset(age_ch,'\0',AGE);
					memset(period_ch,'\0',PERIOD);

					printf("\n< New member registration > \n name, age, period: ");
					scanf("%s %s %s", name, age_ch, period_ch);
					getchar();
					age=atoi(age_ch);
					remain_period=atoi(period_ch);
						   
					for(i = 0; i < strlen(name); i++)
					{
						if(!(name[i] >= 'a' && name[i] <= 'z') && !(name[i] >= 'A' && name[i] <= 'Z'))
						{
							printf("name error\n");
							flag=1;
							break;
						}
					}
					for(i = 0; i < strlen(age_ch); i++)
					{
						if(!(age_ch[i] >= '0' && age_ch[i] <= '9') || ((age_ch[i] >= 'a' &&									age_ch[i] <= 'z') && (age_ch[i] >= 'A' && age_ch[i] <= 'Z')))
						{
							printf("age error\n");
							flag=1;
							break;
						}
					}
					for(i = 0; i < strlen(period_ch); i++)
					{
						if((!age_ch[i] >= '0' && age_ch[i] <= '9') || ((period_ch[i] >= 'a'									&& period_ch[i] <= 'z') && (period_ch[i] >= 'A' && period_ch[i] <= 'Z')))
						{
							printf("period error\n");
							flag=1;
							break;
						}
					}
					if(strlen(name) > NAME)
					{
						printf("strlen name error > 20\n");
						continue;
					}
					if(strlen(age_ch) > AGE)
					{
						printf("strlen age error > 20\n");
						continue;
					}
					if(strlen(period_ch) > PERIOD)
					{
						printf("strlen period error > 10\n");
						continue;
					}

					if(flag == 1)
						continue;
		
					name_flag = searchlist(name);
					
					if(name_flag == 1)
					{
						printf("\n The name is already exists\n Try Again\n");
						continue;
					}
					else
					{
						break;
					}
			
				}

				tm = *localtime(&t);

				sprintf(start_date,"%d-%d-%d %d:%d", 
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);	

				tm.tm_mon += remain_period;
				mktime(&tm);

				end_year = tm.tm_year+1900;
				end_mon = tm.tm_mon+1;
				end_day = tm.tm_mday;
				end_hour = tm.tm_hour;
				end_min = tm.tm_min;
				
				sprintf(end_date,"%d-%d-%d %d:%d",
						end_year, end_mon, end_day, end_hour, end_min);

				insertend(name, age, start_date, end_date, remain_period);
				printf(" Success\n");
				break;
		
			case 2:
				printf(" < Extension of the period >\n user name, period :");
				scanf("%s %d", user, &period);
				if(extension(user, period) == 1)
					printList();
	//			extension(user, period);
				printf(" Finish\n");
				break;

			case 3:
				printf(" < Extension of the period >\n giver, receiver : ");
				scanf("%s %s", giver, receiver);
				transfer(giver, receiver);
				printf(" Finish\n");
		        break;
	
			case 4:
				printf(" < Delete Membership >\n user name : ");
				scanf("%s", user);
				if(deletenode(user) == 0)
					printf(" fail\n");
				else 
					printf(" Success\n");
				break;

			case 5:
				printf(" < Search Member >\n user name : ");
				scanf("%s", user);
				name_flag = searchlist(user);
				if(name_flag == 1)
					printf(" Found\n");
				else 
					printf(" User is not present in the list\n");
				break;

			case 6:
				printList();
				printf(" Finish\n");
				break;

			case 7:
				printf(" < Update all membership >\n");
				updateall();
				printf(" Success\n");
				break;

			case 8:
				savefile();
				printf(" Save\n");
				break;	

			case 9:
				savefile();
				printf(" Finish\n");
				e++;
				break;	

			default :
				printf(" Try Again\n");
				break;
		}

	}
	return 0;
}


