#define DAY 50
#define NAME 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"


int main()
{
	int mode = 0;
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
	struct node *head = NULL;


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

		scanf("%d", &mode);
		while (getchar() != '\n');


		switch(mode)
		{
			case 1:
				while(1)
				{
					if(count == 1)
					{
						count = 0;
						break;
					}
					if(count > 1 || count == 0|| p >= 1)
					{
						printf("\n< New member registration > \n name, age, period: ");
						scanf("%s %d %d", name, &age, &remain_period);
					}
					int k = searchlist(name);
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
