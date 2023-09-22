#define DAY 50
#define NAME 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"


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
	int k=0;
	char age_ch[5] = {0, };
	char period_ch[5] = {0, };
	char mode[3] = {0, };
	int flag = 0;


	printf("\n");

	if((fp = fopen("member_info.txt", "r")) == NULL)
	{
		printf("fail\n");
	}
	
	while(1)
    {
        if(fgets(buffer, sizeof(buffer), fp) == NULL)
            break;
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
					k=0;
					if(count == 1)
					{
						count = 0;
						break;
					}
					if(count > 1 || count == 0|| p >= 1)
					{
						printf("\n< New member registration > \n name, age, period: ");
						scanf("%s %s %s", name, age_ch, period_ch);
						getchar();
						age=atoi(age_ch);
						remain_period=atoi(period_ch);
						if(strlen(name) > 20)
						{
							printf("strlen name error > 20\n");
							continue;
						}
						if(strlen(age_ch) > 10)
						{
							printf("strlen age error > 20\n");
							continue;
						}
						if(strlen(period_ch) > 10)
						{
							printf("strlen period error > 10\n");
							continue;
						}
   
						for(int i = 0; i < strlen(name); i++)
						{
							if(!((int)name[i] > 96 && (int)name[i] < 123))
							{
								printf("name error\n");
								flag=1;
								break;
							}
						}
						for(int i = 0; i < strlen(age_ch); i++)
						{
							if(!((int)age_ch[i] > 47 && (int)age_ch[i] < 58) || ((int)age_ch[i] > 96 && (int)age_ch[i] < 123))
							{
								printf("age error\n");
								flag=1;
								break;
							}
						}
						for(int i = 0; i < strlen(period_ch); i++)
						{
							if((!(int)age_ch[i] > 47 && (int)age_ch[i] < 58) || ((int)period_ch[i] > 96 && (int)period_ch[i] < 123) )
							{
								printf("age error\n");
								flag=1;
								break;
							}
						}
					}
					if(flag == 1)
						break;
					k = searchlist(name);
					while(1)
					{
						if(k==1)
						{
							count = 1;
							printf("\n The name is already exists\n Try Again\n");
							p++;							
							count++;
							break;
						}
						else
						{
							count = 1;
							break;
						}
					}
				}
				if(flag == 1)
					break;
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
				extension(user, period);
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
				int k = searchlist(user);
				if(k == 1)
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


