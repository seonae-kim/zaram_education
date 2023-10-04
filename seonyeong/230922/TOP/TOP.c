#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

struct member
{
	char name[20];
	int age;
	char start_date[50];
	char end_date[50];
	int remain_period;
};

struct node{
	struct member data;
	struct node *next;
};

int main()
{
	FILE *fp;
	struct member data[50] ;
	struct node node;
	char buffer[255] = {0};
	int count = 0;
	char name[20] = {0}, start_date[20] = {0}, end_date[20] = {0};
	int mode = 0, e = 0, i = 0, p = 0, k = 0;
	int age = 0, remain_period = 0, period = 0;
	char mode_ch[5] = {0},age_ch[20]= {0} , period_ch[20] = {0};
	char user[20] = {0}, giver[20] = {0}, receiver[20] = {0};
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf("\n");

	if((fp = fopen("member_info.txt", "r")) == NULL)
	{
		printf("fail\n");
	}

	if(fp != NULL)
	{
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
			if(p == 0)
			{
				insertbegin(name, age, start_date, end_date, remain_period);
			}
			else
			{
				insertend(name, age, start_date, end_date, remain_period);
			}
			p++;
		}

	}
	while(1)
	{
		if(e == 1)
			break;

		printf("\n # MEMBERSHIP PROGRAM #\n Select Mode\n 1-Registration\n 2-Extension of the period\n 3-Transfer of membership\n 4-Delete membership\n 5-Search membership \n 6-View all information \n 7-Update all membership \n 8-Save\n 9-exit & save\n");

		scanf("%s", mode_ch);
		mode = atof(mode_ch);

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
						scanf("%s %s %s", name, age_ch, period_ch);
						age = atof(age_ch);
						period = atof(period_ch);
					}

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

						if(age <= 0) 
						{
							count = 1;
							printf("age error\n");
							p++;
							count++;
							break;
						}

						if(period <= 0)
						{
							count = 1;
							printf(" period error\n");
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
				struct tm tm = *localtime(&t);

				sprintf(start_date,"%d-%d-%d %d:%d", 
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);

				tm.tm_mon += period;
				mktime(&tm);
				int end_year = tm.tm_year+1900;
				int end_mon = tm.tm_mon+1;
				int end_day = tm.tm_mday;
				int end_hour = tm.tm_hour;
				int end_min = tm.tm_min;

				sprintf(end_date,"%d-%d-%d %d:%d",
						end_year, end_mon, end_day, end_hour, end_min);

				insertend(name, age, start_date, end_date, period);
				printf(" Success\n");
				break;

			case 2:
				printf(" < Extension of the period >\n user name, period :");
				scanf("%s %d", user, &period);
				extension(user, period);
				printf(" Finish\n");
				break;

			case 3:
				printf(" < Transfer of membership >\n giver, receiver : ");
				scanf("%s %s", giver, receiver);
				transfer(giver, receiver);
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
				k = searchlist(user);
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

	fclose(fp);
	return 0;
}
