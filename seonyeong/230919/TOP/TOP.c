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
/*
struct node *head = NULL;

void insertbegin(char name[50], int age, char start_date[20], char end_date[20], int remain_period )
{
	struct node *lk = (struct node*) malloc(sizeof(struct node));
	sprintf(lk-> data.name , "%s",name);
	lk-> data.age = age;
	sprintf(lk-> data.start_date , "%s",start_date);
	sprintf(lk-> data.end_date , "%s",end_date);
	lk-> data.remain_period = remain_period;

	lk->next = head;
	head = lk;
}

void insertend(char name[50], int age, char start_date[20], char end_date[20], int remain_period)
{
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    
	sprintf(lk-> data.name , "%s",name);
	lk-> data.age = age;
	sprintf(lk-> data.start_date , "%s",start_date);
	sprintf(lk-> data.end_date , "%s",end_date);
	lk-> data.remain_period = remain_period;
    
	struct node *linkedlist = head;

	if (head == NULL)
	{
		lk->next = head;
		head = lk;
	}
	else
	{
		while(1)
		{
			if(linkedlist->next == NULL)
				break;
			linkedlist = linkedlist->next;
		}
		linkedlist->next = lk; 
	}
}

int deletenode(char* data)
{
	struct node *temp = head, *prev;
	if (temp != NULL && strstr(temp->data.name,data) != NULL) {
		head = temp->next;
		return 1;
	}

	while (temp != NULL && strstr(temp->data.name,data) == NULL) {
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) 
		return 0;

	prev->next = temp->next;
	return 1;
}

void deletebegin()
{
	head = head->next;
}

void deleteend()
{
	struct node *linkedlist = head;
	while (linkedlist->next->next != NULL)
		linkedlist = linkedlist->next;
	linkedlist->next = NULL;
}

int searchlist(char* data)
{
	struct node *temp = head;
	while(temp != NULL) 
	{
		if (strstr(temp->data.name, data) != NULL) 
		{
			printf("%s %d %s %s %d \n", 
					temp -> data.name, temp -> data.age ,temp -> data.start_date ,
					temp -> data.end_date ,temp -> data.remain_period);
			return 1;
		}
		temp=temp->next;
	}
	return 0;
}

int extension(char* data, int period)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	struct node *temp = head;
	while (temp != NULL)
	{
		if(strstr(temp->data.name, data) != NULL)
		{
			temp->data.remain_period =  temp->data.remain_period + period;
			tm.tm_mon += temp->data.remain_period;
			mktime(&tm);
				
			sprintf(temp->data.end_date,"%d-%d-%d %d:%d",
					tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);

			deletenode(data);
			insertend(temp->data.name, temp->data.age, temp->data.start_date, 
					temp->data.end_date, temp->data.remain_period);
			return 0;
		}
		temp = temp->next;
	}
}

int transfer(char *data1, char *data2)
{
	int A = 0;
	struct node *temp = head;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	while(temp != NULL)
	{
		if(strstr(temp->data.name, data1) != NULL)
		{
			A = temp->data.remain_period;
		}
		if(strstr(temp->data.name, data2) != NULL)
		{
			temp->data.remain_period = A + temp->data.remain_period;
			
			tm.tm_mon += temp->data.remain_period;
			mktime(&tm);
				
			sprintf(temp->data.end_date,"%d-%d-%d %d:%d",
					tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
		}
		temp = temp->next;		
	} 
	deletenode(data1);
	return 0;
}

void printList(){
      struct node *p = head;
  
      while(p != NULL) 
	  {
          printf(" %s %d %s %s %d \n", 
				  p -> data.name, p -> data.age ,p -> data.start_date ,
				  p -> data.end_date ,p -> data.remain_period);

          p = p->next;
      }
  }

void updateall()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	struct node *p = head;
	int count = 0;
	int a = 0;
	int i = 0;
	int remainyear = 0, remainmon = 0, remainday = 0;
	int end_year = 0, end_mon = 0;
	char end_time[20] = {0};
	while(p != NULL)
	{	
		count = 0;
		char *ptr = strtok(p->data.end_date , "-");
		while(ptr != NULL)
		{	
			if (count == 0)
			{
				end_year =  atof(ptr);
				ptr = strtok(NULL, "-");
			}
			else if(count == 1)
			{
				end_mon = atof(ptr);
				ptr = strtok(NULL, "-");
			}
			
			else
			{
				ptr = strtok(NULL, "-");
			}

			if(strstr(ptr, ":") != NULL) 
			{
				sprintf(end_time,"%s", ptr);
				ptr = strtok(NULL, "-");
			}
		
			count++;
		}
		
		remainyear = end_year - tm.tm_year-1900;
		remainmon = end_mon - tm.tm_mon-1;
		
		sprintf(p->data.end_date,"%d-%d-%s", end_year, end_mon, end_time);

				
		if(remainyear == 0 && remainday > 0)
		{
			p->data.remain_period = remainmon+1;
		}
		else if(remainyear > 0)
		{
			p->data.remain_period = remainyear * 12 + remainmon;
		}
		else if(remainyear == 0 && remainday < 0)
		{
			p->data.remain_period = remainmon-1;
		}
		
		p = p->next;
	}
}

void savefile()
{
	FILE *new = fopen("member_info.txt", "w");
	struct node *p = head;
	if(p != NULL)
	{
		while (p->next != NULL)
		{
			fprintf(new, "%s	%d	%s	%s	%d\n",
				 p->data.name,p->data.age ,p->data.start_date ,
				 p->data.end_date ,p->data.remain_period);
			
			p = p -> next;
		}
		fprintf(new, "%s	%d	%s	%s	%d\n",
				 p -> data.name, p -> data.age ,p -> data.start_date ,
				 p -> data.end_date ,p -> data.remain_period);
		p = p->next;
	}
}
*/

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
	char name[50], start_date[20], end_date[20];
	int age, remain_period, period;
	char user[20] = {0}, giver[20] = {0}, receiver[20] = {0};
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

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


	while(1)
	{
		if(e == 1)
			break;
		
		printf("\n # MEMBERSHIP PROGRAM #\n Select Mode\n 1-Registration\n 2-Extension of the period\n 3-Transfer of membership\n 4-Delete membership\n 5-Search membership \n 6-View all information \n 7-Update all membership \n 8-Save\n 9-exit & save\n");

		scanf("%d", &mode);


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
							printf("\n The name is already exists\n Try Again");
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
				sprintf(start_date,"%d-%d-%d %d:%d", 
						tm.tm_year+1900,tm.tm_mon+1, tm.tm_mday, tm.tm_hour, tm.tm_min);
				
				tm.tm_mon += remain_period;
				mktime(&tm);
				int end_year = tm.tm_year+1900;
				int end_mon = tm.tm_mon+1;
				int end_day = tm.tm_mday;
				int end_hour = tm.tm_hour;
				int end_min = tm.tm_min;
				
				sprintf(end_date,"%d-%d-%d %d:%d",
						end_year, end_mon, end_day, end_hour, end_min);

				insertend(name, age, start_date, end_date, remain_period);

				break;
		
			case 2:
				printf(" < Extension of the period >\n user name, period :");
				scanf("%s %d", user, &period);
				extension(user, period);

				break;

			case 3:
				printf(" < Extension of the period >\n giver, receiver : ");
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

				int k = searchlist(user);
				if(k == 1)
					printf(" User is found\n");
				else 
					printf(" User is not present in the list\n");
				break;

			case 6:
				printList();	
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
				break;
		}

	}

	fclose(fp);
	return 0;
}
